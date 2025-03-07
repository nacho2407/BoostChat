#include "tester.hpp"

#include "boost_chat/logger.hpp"

#include <boost/asio.hpp>

int boost_chat::logger_test(void)
{
        static Logger& logger = Logger::get_instance();

        logger.conn(boost::asio::ip::make_address("127.0.0.1"));
        logger.error("Test error message");
        logger.info("Test information message");

        return 0;
}
