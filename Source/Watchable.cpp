#include "Watchable.h"


Watchable::Watchable (int id, std::string name, int length, std::vector<std::string> tags)
:m_id(id), m_name(name), m_length(length), m_tags(tags)
{
}



Movies::Movies (int id, std::string name, int length, std::vector<std::string> tags)
:Watchable(id, name, length, tags)
{
}

Watchable* Movies::get_next_watchable(const Session& session)
{
    return nullptr;
}




Episode::Episode (int id, std::string name, int length, std::vector<std::string> tags)
:Watchable(id, name, length, tags)
{
}

Watchable* Episode::get_next_watchable(const Session& session)
{
    return nullptr;
}