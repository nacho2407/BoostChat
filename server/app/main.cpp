#define BOOST_CHAT_DEFAULT_PORT 24072
#define BOOST_CHAT_SERVER_VERSION "build"

#include "../lib/server.hpp"

#include <boost/asio.hpp>

#include <iostream>
#include <stdlib.h>

/**
 * @brief Start to accept client
 */
static int run_server(const unsigned short& port);

int main(int argc, char* argv[])
{
        unsigned short port = BOOST_CHAT_DEFAULT_PORT;

        if(argc > 2) {
                std::cerr << "Usage: BoostChat-server [port=" << BOOST_CHAT_DEFAULT_PORT << "]\n";

                exit(1);
        }
        else if(argc == 2)
                port = atoi(argv[1]);

        std::cout << "================================\n\n"
        
        << "\tBoostChat-server\n\n"

        << "\tver. " << BOOST_CHAT_SERVER_VERSION << "\n\n"

        << "================================" << std::endl;
        
        run_server(port);

        return 0;
}

static int run_server(const unsigned short& port)
{
        boost::asio::io_context context;

        boost_chat::Server server(context, port);

        context.run();
        
        return 0;
}
