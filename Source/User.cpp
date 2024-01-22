#include "User.h"


// User
User::User(std::string name)
:m_name(name)
{
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

// RerunBasedUser
RerunBasedUser::RerunBasedUser(std::string name)
:User(name)
{
}

Watchable* RerunBasedUser::get_recommendation()
{
    return nullptr;
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
