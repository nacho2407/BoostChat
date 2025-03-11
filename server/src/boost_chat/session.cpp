#include "session.hpp"

#include "logger.hpp"

#include <boost/system.hpp>

#include <cstddef>
#include <utility>

boost_chat::Session::Session(tcp::socket&& socket, Server& pserver)
        : socket_(std::move(socket)), pserver_(pserver)
{
        auto self(shared_from_this());
        socket_.async_read_some(boost::asio::buffer(buffer_, MAX_BUFFER_SIZE), [self](boost::system::error_code ec, std::size_t length) {
                static Logger& logger = Logger::get_instance();

                logger.conn(self->socket_);

                if(!ec) {
                        self->cid_ = std::string(self->buffer_.data(), length);

                        self->read();
                }
                else {
                        logger.error(self->socket_, "Client configuration error");

                        self->pserver_.close_session(self);
                }
        });
}

boost_chat::Session::~Session()
{
        boost_chat::Logger::get_instance().info(socket_, "Finish session");

        socket_.close();
}

void boost_chat::Session::send(std::string msg)
{
        auto self(shared_from_this());
        socket_.async_send(boost::asio::buffer(msg), [self](boost::system::error_code ec, std::size_t length) {
                static Logger& logger = Logger::get_instance();
                
                if(ec) {
                        if(ec == boost::asio::error::eof)
                                logger.info(self->socket_, "Client exits connection");
                        else
                                logger.error(self->socket_, "Broadcasting message sending error");

                        self->pserver_.close_session(self);
                }
        });
}

void boost_chat::Session::read(void)
{
        auto self(shared_from_this());
        socket_.async_read_some(boost::asio::buffer(buffer_, MAX_BUFFER_SIZE), [self](boost::system::error_code ec, std::size_t length) {
                static Logger& logger = Logger::get_instance();

                if(!ec) {
                        logger.info(self->socket_, "Client sends message");

                        // Broadcast clients message to all clients
                        self->pserver_.broadcast(self->buffer_.data());
                }
                else {
                        if(ec == boost::asio::error::eof)
                                logger.info(self->socket_, "Client exits connection");
                        else
                                logger.error(self->socket_, "Client's message reading error");

                        self->pserver_.close_session(self);
                }
        });
}
