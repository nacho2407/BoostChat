#ifndef BOOST_CHAT_MESSAGE_HPP
#define BOOST_CHAT_MESSAGE_HPP

#define BOOST_CHAT_MESSAGE_VERSION "1.0"

#include <boost/serialization/string.hpp>

#include <string>
#include <utility>

namespace boost_chat
{
        class Message
        {
        public:
                Message() = default;
                Message(std::string cid, std::string&& msg, std::string&& time, std::string version = BOOST_CHAT_MESSAGE_VERSION)
                        : cid_(cid), msg_(std::move(msg)), time_(std::move(time)) {}

                std::string cid_;
                std::string msg_;
                std::string time_;
                std::string version_;

                template<class Archive>
                void serialize(Archive& ar, const unsigned int version);
        };
}
#endif
