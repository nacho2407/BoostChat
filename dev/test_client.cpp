// test_client.cpp
#include "message.hpp"

#include <boost/asio.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/string.hpp>

#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>

using boost::asio::ip::tcp;
using boost_chat::Message;

std::string get_time() {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    return std::string(std::ctime(&now));
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "사용법: " << argv[0] << " <host> <port>\n";
        return 1;
    }

    boost::asio::io_context io_context;
    tcp::resolver resolver(io_context);
    auto endpoints = resolver.resolve(argv[1], argv[2]);
    tcp::socket socket(io_context);
    boost::asio::connect(socket, endpoints);

    // 1. 클라이언트 ID 전송
    std::string cid;
    std::cout << "[클라이언트 ID 입력]: ";
    std::getline(std::cin, cid);
    socket.send(boost::asio::buffer(cid));

    // 2. 수신 쓰레드 시작
    std::thread receive_thread([&]() {
        while (true) {
            try {
                std::array<char, 1024> recv_buf;
                boost::system::error_code ec;
                size_t len = socket.read_some(boost::asio::buffer(recv_buf), ec);
                if (ec == boost::asio::error::eof) {
                    std::cout << "\n[서버 연결 종료됨]\n";
                    break;
                }

                std::istringstream iss(std::string(recv_buf.data(), len));
                boost::archive::binary_iarchive ia(iss);
                Message m("", "", "");
                ia >> m;

                std::cout << "\n[" << m.cid_ << "] " << m.msg_ << " (" << m.time_ << ")\n> ";
                std::cout.flush();
            } catch (std::exception& e) {
                std::cerr << "\n[수신 오류]: " << e.what() << "\n";
                break;
            }
        }
    });

    // 3. 사용자 입력 → 메시지 직렬화 전송
    std::string line;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);
        if (line == "/quit") break;

        std::ostringstream oss;
        boost::archive::binary_oarchive oa(oss);
        Message m(cid, std::move(line), get_time());
        oa << m;

        boost::asio::write(socket, boost::asio::buffer(oss.str()));
    }

    socket.close();
    receive_thread.join();
    return 0;
}
