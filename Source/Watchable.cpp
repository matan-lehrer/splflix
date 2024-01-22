#include "Watchable.h"


// Watchable
Watchable::Watchable (int id, std::string name, int length, std::vector<std::string> tags)
:m_id(id), m_name(name), m_length(length), m_tags(tags)
{
}

int Watchable::get_id() const
{
    return this->m_id;
}

std::string Watchable::get_name() const
{
    return this->m_name;
}

int Watchable::get_length() const
{
    return this->m_length;
}

std::vector<std::string> Watchable::get_tags() const
{
    return this->m_tags;
}



// Movies
Movies::Movies (int id, std::string name, int length, std::vector<std::string> tags)
:Watchable(id, name, length, tags)
{
}

Watchable* Movies::get_next_watchable(const Session& session)
{
    return nullptr;
}



// Episodes
Episode::Episode (int id, std::string name, int length, std::vector<std::string> tags)
:Watchable(id, name, length, tags)
{
}

Watchable* Episode::get_next_watchable(const Session& session)
{
    return nullptr;
}