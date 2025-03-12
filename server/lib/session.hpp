#ifndef BOOST_CHAT_SESSION_HPP
#define BOOST_CHAT_SESSION_HPP

#include "def.hpp"
#include "message.hpp"
#include "server.hpp"

#include <boost/asio.hpp>

#include <array>
#include <memory>
#include <string>

using boost::asio::ip::tcp;

namespace boost_chat
{
        class Session: public std::enable_shared_from_this<Session>
        {
        public:
                Session() = delete;
                Session(const Session&) = delete;
                Session(Session&&) = default;

                Session(tcp::socket&& socket, Server& pserver);

                ~Session();

                /**
                 * @brief Send a message to client
                 */
                void send(Message msg);
        private:
                tcp::socket socket_;
                std::string cid_;

                // Buffer for writing and reading a message
                std::array<char, MAX_BUFFER_SIZE> buffer_;

                Server& pserver_;

                /**
                 * @brief Read a message from client
                 */
                void read(void);
        };
}
#endif
