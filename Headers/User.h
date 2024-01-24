#pragma once

#include <vector>
#include <string>
#include "Watchable.h"

class Watchable;

class User
{
    protected:
        std::string m_name;
        std::vector<std::string> m_watch_history;
    
    public:
        User(std::string name);
        std::string get_name();
        void set_name(std::string new_name);
        std::vector<std::string>& get_watch_history();
        void add_watch_history(std::string description);

        virtual std::shared_ptr<User> clone() const = 0;
        virtual Watchable* get_recommendation() = 0;
        virtual std::string recomendation_stringified() = 0;


};


class LengthBasedUser : public User
{
    public:
        LengthBasedUser(std::string name);
        Watchable* get_recommendation();
        std::string recomendation_stringified();
        std::shared_ptr<User> clone() const;

};


class RerunBasedUser : public User
{
    public:
        RerunBasedUser(std::string name);
        Watchable* get_recommendation();
        std::string recomendation_stringified();
        std::shared_ptr<User> clone() const;
};


class SimilarGenreBasedUser : public User
{
    public:
        SimilarGenreBasedUser(std::string name);
        Watchable* get_recommendation();
        std::string recomendation_stringified();
        std::shared_ptr<User> clone() const;
};
