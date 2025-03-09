#include "tester.hpp"

#include "logger.hpp"

#include <boost/asio.hpp>

boost_chat::Tester& boost_chat::Tester::get_instance(void)
{
        static Tester instance;

        return instance;
}

int boost_chat::Tester::logger_test(void)
{
        static Logger& logger = Logger::get_instance();

        logger.error("Test error message");
        logger.info("Test information message");

        return 0;
}
