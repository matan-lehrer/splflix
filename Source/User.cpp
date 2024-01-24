#include "User.h"


// User
User::User(std::string name)
:m_name(name)
{
}

std::string User::get_name()
{
    return this->m_name;
}

void User::set_name(std::string new_name)
{
    m_name = new_name;
}

std::vector<std::string>& User::get_watch_history()
{
    return m_watch_history;
}

void User::add_watch_history(std::string description)
{
    m_watch_history.push_back(description);
}


// LengthBasedUser
LengthBasedUser::LengthBasedUser(std::string name)
:User(name)
{
}

Watchable* LengthBasedUser::get_recommendation()
{
    return nullptr;
}

std::string LengthBasedUser::recomendation_stringified()
{
    return "length based";
}

std::shared_ptr<User> LengthBasedUser::clone() const
{
    return std::make_shared<LengthBasedUser>(*this);
}


// RerunBasedUser
RerunBasedUser::RerunBasedUser(std::string name)
:User(name)
{
}

Watchable* RerunBasedUser::get_recommendation()
{
    return nullptr;
}

std::string RerunBasedUser::recomendation_stringified()
{
    return "rerun based";
}

std::shared_ptr<User> RerunBasedUser::clone() const
{
    return std::make_shared<RerunBasedUser>(*this);
}


// SimilarGenreBasedUser
SimilarGenreBasedUser::SimilarGenreBasedUser(std::string name)
:User(name)
{
}

Watchable* SimilarGenreBasedUser::get_recommendation()
{
    return nullptr;
}

std::string SimilarGenreBasedUser::recomendation_stringified()
{
    return "similar genre based";
}

std::shared_ptr<User> SimilarGenreBasedUser::clone() const
{
    return std::make_shared<SimilarGenreBasedUser>(*this);
}
