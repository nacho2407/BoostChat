#ifndef BOOST_CHAT_MESSAGE_HPP
#define BOOST_CHAT_MESSAGE_HPP

#include <boost/serialization/string.hpp>

#include <string>
#include <utility>

namespace boost_chat
{
        class Message
        {
        public:
                Message(std::string cid, std::string&& msg, std::string&& time)
                        : cid_(cid), msg_(std::move(msg)), time_(std::move(time)) {}

                std::string cid_;
                std::string msg_;
                std::string time_;

                /**
                 * @brief Serialize Message instance
                 */
                template<class Archive>
                void serialize(Archive& ar, const unsigned int version)
                {
                        ar & cid_;
                        ar & msg_;
                        ar & time_;
                }
        };
}
#endif
