#include "session.hpp"

#include "logger.hpp"

#include <cstddef>
#include <utility>

boost_chat::Session::Session(tcp::socket&& socket, std::set<std::shared_ptr<Session>>& clients, std::mutex& clients_mtx, boost::asio::thread_pool& tpool)
        : socket_(std::move(socket)), clients_(clients), clients_mtx_(clients_mtx), tpool_(tpool)
{
        std::unique_lock<std::mutex> lk(clients_mtx_);
        clients_.insert(shared_from_this());
        
        lk.unlock();

        socket_.async_read_some(boost::asio::buffer(buffer, MAX_BUFFER_SIZE), [this](boost::system::error_code ec, std::size_t length) {
                static Logger& logger = Logger::get_instance();

                if(!ec) {
                        cid_ = std::string(buffer.data(), length);

                        read();
                }
                else {
                        logger.error(socket_, "Client configuration error");

                        // 작성중
                }
        });
}

boost_chat::Session::~Session()
{
        // 작성중
}

void boost_chat::Session::broadcast(void)
{
        // 작성중
}

void boost_chat::Session::read(void)
{
        // 작성중
}
