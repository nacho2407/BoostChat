#ifndef BOOST_CHAT_MESSAGE_HPP
#define BOOST_CHAT_MESSAGE_HPP

#define BOOST_CHAT_MESSAGE_VERSION "1.0"

#include <string>

namespace boost_chat
{
        class Message
        {
        public:
                Message(std::string&& cid, std::string&& msg, std::string&& time, std::string version = BOOST_CHAT_MESSAGE_VERSION);

                std::string version_;

                template<class Archive>
                void serialize(Archive& ar);
        private:
                std::string cid_;
                std::string msg_;
                std::string time_;
        };
}
#endif
