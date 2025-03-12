#ifndef BOOST_CHAT_SERVER_HPP
#define BOOST_CHAT_SERVER_HPP

#include "def.hpp"
#include "message.hpp"
#include "session.hpp"

#include <boost/asio.hpp>

#include <memory>
#include <mutex>
#include <set>

using boost::asio::ip::tcp;

namespace boost_chat
{
        class Server
        {
        public:
                Server() = delete;
                Server(const Server&) = delete;
                Server(Server&&) = default;

                Server(boost::asio::io_context& context, const unsigned short port);

                /**
                 * @brief Erase session from clients_
                 */
                void close_session(const std::shared_ptr<Session>& session);

                /**
                 * @brief Broadcast message to all clients
                 */
                void broadcast(Message&& msg);
        private:
                tcp::acceptor acceptor_;

                // Critical Section
                std::set<std::shared_ptr<Session>> clients_;
                std::mutex clients_mtx_;

                /**
                 * @brief Accept a client asynchronously and insert session to clients_
                 */
                void accept(void);
        };
}
#endif
