#include "server.hpp"

#include "logger.hpp"

#include <boost/system.hpp>

#include <iostream>
#include <utility>

boost_chat::Server::Server(boost::asio::io_context& context, const unsigned short port)
        : acceptor_(context, tcp::endpoint(tcp::v4(), port))
{
        std::cout << "--------------------------------\n"
                << "Server started at port " << port << ".\n"
                << "--------------------------------" << std::endl;
        
        accept();
}

void boost_chat::Server::close_session(const std::shared_ptr<Session>& session)
{
        std::lock_guard<std::mutex> lk(clients_mtx_);
        
        clients_.erase(session);
}

void boost_chat::Server::broadcast(Message&& msg)
{
        Message msg_ = std::move(msg);

        std::lock_guard<std::mutex> lk(clients_mtx_);

        for(auto& c: clients_)
                c->send(msg_);
}

void boost_chat::Server::accept(void)
{
        acceptor_.async_accept([this](boost::system::error_code ec, tcp::socket socket) {
                static Logger& logger = Logger::get_instance();

                if(!ec) {
                        logger.conn(socket);

                        std::lock_guard<std::mutex> lk(clients_mtx_);
                        clients_.insert(std::make_shared<Session>(std::move(socket), *this));
                }
                else
                        logger.error(socket, "Client connecting error");
                
                accept();
        });
}
