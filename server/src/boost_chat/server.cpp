#include "server.hpp"

#include "logger.hpp"

#include <boost/system.hpp>

#include <memory>
#include <utility>

boost_chat::Server::Server(boost::asio::io_context& context, unsigned short port, boost::asio::thread_pool& tpool)
        : acceptor_(context, tcp::endpoint(tcp::v4(), port)), tpool_(tpool)
{
        accept();
}

void boost_chat::Server::accept(void)
{
        acceptor_.async_accept([this](boost::system::error_code ec, tcp::socket socket) {
                static Logger& logger = Logger::get_instance();

                if(!ec) {
                        logger.conn(socket);

                        auto session = std::make_shared<Session>(std::move(socket), clients_, clients_mtx_, tpool_);
                }
                else
                        logger.error(socket, "Client connecting error");
                
                accept();
        });
}
