#ifndef BOOST_CHAT_SERVER_HPP
        #define BOOST_CHAT_SERVER_HPP

        #include "def.hpp"

        #include <boost/asio.hpp>

        #include <mutex>
        #include <set>

        using boost::asio::ip::tcp;

        namespace boost_chat
        {
                class Server
                {
                public:
                        Server(boost::asio::io_context& context, unsigned short port, boost::asio::thread_pool& tpool);
                private:
                        tcp::acceptor acceptor_;

                        // Critical Section
                        std::set<std::shared_ptr<Session>> clients_;
                        std::mutex clients_mtx_;
                        
                        boost::asio::thread_pool& tpool_;

                        /**
                         * @brief Accept a client asynchronously
                         */
                        void accept(void);
                };
        }
#endif
