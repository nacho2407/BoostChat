#include "server.hpp"

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
                if(!ec) {
                        // 작성중

                        clients_.insert(std::make_shared<Session>(std::move(socket), this));
                }
                else
                        // 작성중
                
                accept();
        });
}
