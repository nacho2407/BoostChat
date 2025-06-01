#include "session.hpp"

#include "logger.hpp"

#include <boost/archive/binary_oarchive.hpp>
#include <boost/system.hpp>

#include <cstddef>
#include <sstream>
#include <utility>

boost_chat::Session::Session(tcp::socket&& socket, Server& pserver)
        : socket_(std::move(socket)), pserver_(pserver)
{
        auto self(shared_from_this());
        socket_.async_read_some(boost::asio::buffer(buffer_, MAX_BUFFER_SIZE), [self](boost::system::error_code ec, std::size_t length) {
                static Logger& logger = Logger::get_instance();

                logger.conn(self->socket_);

                if(!ec) {
                        // Configure clients id
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

void boost_chat::Session::send(boost_chat::Message msg)
{
        boost_chat::Message msg_ = std::move(msg);

        // Serialize Message
        std::ostringstream oss;
        boost::archive::binary_oarchive bo(oss);
        bo << msg_;

        auto self(shared_from_this());
        socket_.async_send(boost::asio::buffer(oss.str()), [self](boost::system::error_code ec, std::size_t length) {
                static Logger& logger = Logger::get_instance();
                
                if(ec) {
                        if(ec == boost::asio::error::eof)
                                logger.info(self->socket_, "Client's disconnected while sending a message.");
                        else
                                logger.error(self->socket_, "Message sending error");

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
                        self->pserver_.broadcast(boost_chat::Message(self->cid_, self->buffer_.data(), logger.get_time()));
                }
                else {
                        if(ec == boost::asio::error::eof)
                                logger.info(self->socket_, "Client's disconnected while reading a message.");
                        else
                                logger.error(self->socket_, "Clients message reading error");

                        self->pserver_.close_session(self);
                }

                self->read();
        });
}
