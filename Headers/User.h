#pragma once


#include <vector>
#include <string>
#include "Watchable.h"

class Watchable;

class User
{
    protected:
        std::string m_name;
        // maybe hold only string
        // and have method in other class that returns watch string
        std::vector<Watchable> m_watch_history;
    
    public:
        User(std::string name);
        virtual Watchable* get_recommendation() = 0;

};


class LengthBasedUser : public User
{
    public:
        LengthBasedUser(std::string name);
        Watchable* get_recommendation();

};


class RerunBasedUser : public User
{
    public:
        RerunBasedUser(std::string name);
        Watchable* get_recommendation();
};


class SimilarGenreBasedUser : public User
{
    public:
        SimilarGenreBasedUser(std::string name);
        Watchable* get_recommendation();
};
