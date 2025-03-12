#include "message.hpp"

template<class Archive>
void boost_chat::Message::serialize(Archive& ar, const unsigned int version)
{
        ar & cid_;
        ar & msg_;
        ar & time_;
}
