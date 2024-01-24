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
