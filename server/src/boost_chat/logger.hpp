#ifndef BOOST_CHAT_LOGGER_HPP
        #define BOOST_CHAT_LOGGER_HPP

        #include "def.hpp"

        #include <iostream>
        #include <string_view>

        namespace boost_chat
        {
                class Logger
                {
                public:
                        // Implemented as a singleton pattern
                        static Logger& get_instance(void);

                        /**
                         * @brief Print a log message
                         */
                        void info(std::string_view msg);

                        /**
                         * @brief Print an error message
                         */
                        void error(std::string_view msg);

                        // Deleted on purpose
                        Logger(const Logger&) = delete;
                        Logger& operator =(const Logger&) = delete;
                private:
                        Logger() = default;
                };
        }
#endif