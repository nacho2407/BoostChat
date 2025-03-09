#ifndef BOOST_CHAT_TESTER_HPP
#define BOOST_CHAT_TESTER_HPP

namespace boost_chat
{
        class Tester
        {
        public:
                // Implemented as a singleton pattern
                static Tester& get_instance(void);

                /**
                 * @brief Test logger module
                 */
                int logger_test(void);

                // Deleted on purpose
                Tester(const Tester&) = delete;
                Tester(Tester&&) = delete;
                Tester& operator =(const Tester&) = delete;
                Tester& operator =(Tester&&) = delete;
        private:
                Tester();
        };
}
#endif
