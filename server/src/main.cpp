#include "tester.hpp"

/**
 * @brief Test modules
 */
static int test(void);

int main(void)
{
        test();

        return 0;
}

static int test(void)
{
        static boost_chat::Tester& tester = boost_chat::Tester::get_instance();

        return tester.logger_test();
}
