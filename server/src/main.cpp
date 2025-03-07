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
        return boost_chat::logger_test();
}
