#ifndef BOOST_CHAT_LOGGER_HPP
        #define BOOST_CHAT_LOGGER_HPP

        #include "def.hpp"

        #include <boost/asio.hpp>

        #include <string>
        #include <string_view>

        namespace boost_chat
        {
                class Logger
                {
                public:
                        // Implemented as a singleton pattern
                        static Logger& get_instance(void);

                        /**
                         * @brief Print a connection message;
                         */
                        void conn(boost::asio::ip::address remote_addr);

                        /**
                         * @brief Print an error message
                         */
                        void error(std::string_view msg);

                        /**
                         * @brief Print a log message
                         */
                        void info(std::string_view msg);

                        // Deleted on purpose
                        Logger(const Logger&) = delete;
                        Logger(Logger&&) = delete;
                        Logger& operator =(const Logger&) = delete;
                        Logger& operator =(Logger&&) = delete;
                private:
                        Logger() = default;

                        /**
                         * @brief Get local time
                         */
                        std::string get_time(void);
                };
        }
#endif
