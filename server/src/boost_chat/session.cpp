#include "session.hpp"

#include "logger.hpp"

#include <cstddef>
#include <utility>

boost_chat::Session::Session(tcp::socket&& socket, Server& pserver)
        : socket_(std::move(socket)), pserver_(pserver)
{
        std::unique_lock<std::mutex> lk(pserver_.clients_mtx_);
        clients_.insert(shared_from_this());
        
        lk.unlock();

        socket_.async_read_some(boost::asio::buffer(buffer_, MAX_BUFFER_SIZE), [this](boost::system::error_code ec, std::size_t length) {
                static Logger& logger = Logger::get_instance();

                logger.conn(socket_);

                if(!ec) {
                        // Configure client's id
                        cid_ = std::string(buffer_.data(), length);

                        // Start reading
                        read();
                }
                else {
                        logger.error(socket_, "Client configuration error");

                        std::unique_lock<std::mutex> lk(clients_mtx_);
                        clients_.erase(shared_from_this());

                        lk.unlock();
                }
        });
}

boost_chat::Session::~Session()
{
        boost_chat::Logger::get_instance().info(socket_, "Finish session");

        socket_.close();
}

void boost_chat::Session::broadcast(std::string msg)
{
        std::unique_lock<std::mutex> lk(clients_mtx_);
        for(auto cp: clients_) {
                boost::asio::post(tpool_, [cp, msg](void) {
                        auto self(cp);
                        cp->socket_.async_send(boost::asio::buffer(msg), [self](boost::system::error_code ec, std::size_t length) {
                                if(ec)
                                        boost_chat::Logger::get_instance().error(self->socket_, "Client's message sending error");
                        });
                });
        }

        lk.unlock();
}

void boost_chat::Session::read(void)
{
        auto self(shared_from_this());
        socket_.async_read_some(boost::asio::buffer(buffer_, MAX_BUFFER_SIZE), [this, self](boost::system::error_code ec, std::size_t length) {
                static Logger& logger = Logger::get_instance();

                if(!ec) {
                        logger.info(socket_, "Client sends message");

                        // Broadcast clients message to all clients
                        broadcast(buffer_.data());
                }
                else {
                        if(ec == boost::asio::error::eof)
                                logger.info(socket_, "Client exits connection");
                        else
                                logger.error(socket_, "Client's message reading error");

                        std::unique_lock<std::mutex> lk(clients_mtx_);
                        clients_.erase(shared_from_this());

                        lk.unlock();
                }
        });
}
