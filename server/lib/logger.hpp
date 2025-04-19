#ifndef BOOST_CHAT_LOGGER_HPP
#define BOOST_CHAT_LOGGER_HPP

#include "def.hpp"

#include <boost/asio.hpp>

#include <mutex>
#include <string>
#include <string_view>

using boost::asio::ip::tcp;

namespace boost_chat
{
        // Implemented as a singleton pattern
        class Logger
        {
        public:
                /**
                 * @brief Return instance of Logger
                 */
                static Logger& get_instance(void);

                /**
                 * @brief Print a connection message;
                 */
                void conn(const tcp::socket& remote_sck);

                /**
                 * @brief Print a plain error message
                 */
                void error(std::string_view msg);

                /**
                 * @brief Print an error message with client's information
                 */
                void error(const tcp::socket& remote_sck, std::string_view msg);

                /**
                 * @brief Get local time
                 */
                std::string get_time(void) const;

                /**
                 * @brief Print a plain log message
                 */
                void info(std::string_view msg);

                /**
                 * @brief Print a log message with client's information
                 */
                void info(const tcp::socket& remote_sck, std::string_view msg);
        private:
                std::mutex logger_mtx_;

                Logger() = default;
                ~Logger() = default;

                Logger(const Logger&) = delete;
                Logger& operator =(const Logger&) = delete;
                Logger(Logger&&) = delete;
                Logger& operator =(Logger&&) = delete;
        };
}
#endif
