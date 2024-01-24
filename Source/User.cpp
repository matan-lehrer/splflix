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


// LengthBasedUser
LengthBasedUser::LengthBasedUser(std::string name)
:User(name)
{
}

Watchable* LengthBasedUser::get_recommendation()
{
    return nullptr;
}

void LengthBasedUser::print_details()
{
    std::cout << "\n\n___________(USER DETAILS)___________ \n\n";
    std::cout << "user name: " << m_name << "\n\n";
    std::cout << "user recomendation is length based: ";
    std::cout << "\n\n********************************\n";

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

void RerunBasedUser::print_details()
{
    std::cout << "\n\n___________(USER DETAILS)___________ \n\n";
    std::cout << "user name: " << m_name << "\n\n";
    std::cout << "user recomendation is rerun based: ";
    std::cout << "\n\n********************************\n";
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

void SimilarGenreBasedUser::print_details()
{
    std::cout << "\n\n___________(USER DETAILS)___________ \n\n";
    std::cout << "user name: " << m_name << "\n\n";
    std::cout << "user recomendation is similar genre based. ";
    std::cout << "\n\n********************************\n";
}
