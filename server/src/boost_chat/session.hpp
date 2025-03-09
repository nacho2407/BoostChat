#ifndef BOOST_CHAT_SESSION_HPP
#define BOOST_CHAT_SESSION_HPP

#include "def.hpp"

#include <boost/asio.hpp>

#include <array>
#include <memory>
#include <mutex>
#include <set>
#include <string>

using boost::asio::ip::tcp;

namespace boost_chat
{
        class Session: public std::enable_shared_from_this<Session>
        {
        public:
                Session(tcp::socket&& socket, std::set<std::shared_ptr<Session>>& clients, std::mutex& clients_mtx, boost::asio::thread_pool& tpool);

                ~Session();
        private:
                tcp::socket socket_;
                std::string cid_;

                // Buffer for writing and reading a message
                std::array<char, MAX_BUFFER_SIZE> buffer_;

                std::set<std::shared_ptr<Session>>& clients_;
                std::mutex& clients_mtx_;
                boost::asio::thread_pool& tpool_;

                /**
                 * @brief Broadcast message to all clients
                 */
                void broadcast(void);

                /**
                 * @brief Read a message from client
                 */
                void read(void);
        };
}
#endif
