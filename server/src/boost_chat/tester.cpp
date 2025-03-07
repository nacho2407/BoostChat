#include "logger.hpp"

#include <boost/asio.hpp>

namespace boost_chat
{
        /**
         * @brief Test logger module
         */
        static int logger_test(void);
}

int main(void)
{
        boost_chat::logger_test();

        return 0;
}

static int boost_chat::logger_test(void)
{
        static Logger& logger = Logger::get_instance();

        logger.conn(boost::asio::ip::make_address("127.0.0.1"));
        logger.error("Test error message");
        logger.info("Test information message");

        return 0;
}
