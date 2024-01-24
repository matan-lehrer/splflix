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
        virtual void print_details() = 0;

};


class LengthBasedUser : public User
{
    public:
        LengthBasedUser(std::string name);
        Watchable* get_recommendation();
        void print_details();
};


class RerunBasedUser : public User
{
    public:
        RerunBasedUser(std::string name);
        Watchable* get_recommendation();
        void print_details();
};


class SimilarGenreBasedUser : public User
{
    public:
        SimilarGenreBasedUser(std::string name);
        Watchable* get_recommendation();
        void print_details();
};
