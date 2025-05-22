#include "message.hpp"

BOOST_CLASS_VERSION(boost_chat::Message, 1)

template<class Archive>
void serialize(Archive& ar, const unsigned int version)
{
    ar & cid_;
    ar & msg_;
    ar & time_;
}
