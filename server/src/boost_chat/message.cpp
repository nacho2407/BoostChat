#include "message.hpp"

boost_chat::Message::Message(std::string&& cid, std::string&& msg, std::string&& time, std::string&& version): cid_(cid), msg_(msg), time_(time) {}

template<class Archive>
void boost_chat::Message::serialize(Archive& ar)
{
        ar & cid_;
        ar & msg_;
        ar & time_;
}
