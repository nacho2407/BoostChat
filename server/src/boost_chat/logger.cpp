#include "logger.hpp"

boost_chat::Logger& boost_chat::Logger::get_instance(void)
{
        static Logger instance_;

        return instance_;
}

void boost_chat::Logger::info(std::string_view msg)
{
        // 작성중
}

void boost_chat::Logger::error(std::string_view msg)
{
        // 작성중
}
