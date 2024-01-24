#pragma once


#include <vector>
#include <string>
#include "Watchable.h"

class Watchable;

class User
{
    protected:
        std::string m_name;
        std::vector<Watchable> m_watch_history;
    
    public:
        User(std::string name);
        virtual Watchable* get_recommendation() = 0;
        virtual std::string get_name();
        virtual std::string recomendation_stringified() = 0;

};


class LengthBasedUser : public User
{
    public:
        LengthBasedUser(std::string name);
        Watchable* get_recommendation();
        std::string recomendation_stringified();

};


class RerunBasedUser : public User
{
    public:
        RerunBasedUser(std::string name);
        Watchable* get_recommendation();
        std::string recomendation_stringified();
};


class SimilarGenreBasedUser : public User
{
    public:
        SimilarGenreBasedUser(std::string name);
        Watchable* get_recommendation();
        std::string recomendation_stringified();
};
