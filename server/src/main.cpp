#define BOOST_CHAT_SERVER_VERSION "build"

#define BOOST_CHAT_DEFAULT_PORT 24072

#include "server.hpp"

#include <boost/asio.hpp>

#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <string>

/**
 * @brief Start to accept client
 */
static void run_server(const unsigned short port);

int main(int argc, char *argv[])
{
    unsigned short port = BOOST_CHAT_DEFAULT_PORT;

    if (argc > 2) {
        std::cerr << "Usage: BoostChat-server [port=" << BOOST_CHAT_DEFAULT_PORT << "]\n";

        return 1;
    } else if (argc == 2) {
        try {
            port = std::stoi(argv[1]);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid port number.\n"
                << "Usage: BoostChat-server [port=" << BOOST_CHAT_DEFAULT_PORT << "]\n";

            return 1;
        }
    }

    std::cout << "======================================================================\n\n"

        << "\033[32m______                    _____             ______        _____ \n"
        << "___  /______________________  /_      _________  /_______ __  /_\n"
        << "__  __ \\  __ \\  __ \\_  ___/  __/_______  ___/_  __ \\  __ `/  __/\n"
        << "_  /_/ / /_/ / /_/ /(__  )/ /_ _/_____/ /__ _  / / / /_/ // /_  \n"
        << "/_.___/\\____/\\____//____/ \\__/        \\___/ /_/ /_/\\__,_/ \\__/  \033[0mserver\n\n"

        << "ver. " << BOOST_CHAT_SERVER_VERSION << "\n\n"

        << "======================================================================" << std::endl;

    try {
        run_server(port);
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << '\n';

        return 1;
    }

    return 0;
}

static void run_server(const unsigned short port)
{
    boost::asio::io_context context;

    boost_chat::Server server(context, port);

    context.run();
}
