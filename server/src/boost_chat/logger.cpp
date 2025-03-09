#include "logger.hpp"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

using std::chrono::system_clock;

boost_chat::Logger& boost_chat::Logger::get_instance(void)
{
        static Logger instance_;

        return instance_;
}

void boost_chat::Logger::conn(tcp::socket& remote_sck)
{
        std::cout << "[ Conn\t] " << get_time() << " - "
                << "New client connected: " << remote_sck.remote_endpoint().address().to_string() << std::endl;
}

void boost_chat::Logger::error(std::string_view msg)
{
        std::cerr << "[ Error\t] " << get_time() << " - " << msg << "\n";
}

void boost_chat::Logger::error(tcp::socket& remote_sck, std::string_view msg)
{
        std::cerr << "[ Error\t] " << get_time() << " - " << msg << ": " << remote_sck.remote_endpoint().address().to_string() << "\n";
}

void boost_chat::Logger::info(std::string_view msg)
{
        std::cout << "[ Info\t] " << get_time() << " - " << msg << std::endl;
}

void boost_chat::Logger::info(tcp::socket& remote_sck, std::string_view msg)
{
        std::cout << "[ Info\t] " << get_time() << " - " << msg << ": " << remote_sck.remote_endpoint().address().to_string() << std::endl;
}

std::string boost_chat::Logger::get_time(void)
{
        std::stringstream ss;

        std::time_t now = system_clock::to_time_t(system_clock::now());
        ss << std::put_time(std::localtime(&now), "%Y/%m/%d/%H:%M:%S");

        return ss.str();
}
