#pragma once

#include <vector>
#include <string>
#include "Session.h"

class Session;

class Watchable
{
    protected:
        int m_id;
        std::string m_name;
        int m_length;
        std::vector<std::string> m_tags;

    public:
        Watchable (int id, std::string name, int length, std::vector<std::string> tags);
        
        virtual Watchable* get_next_watchable(const Session& session) = 0;
        int get_id() const;
        std::string get_name() const;
        int get_length() const;
        std::vector<std::string> get_tags() const;
};


class Movies : public Watchable
{
    public:
        Movies (int id, std::string name, int length, std::vector<std::string> tags);
        Watchable* get_next_watchable(const Session& session);
};


class Episode : public Watchable
{
    private:
        std::vector<int> m_seasons;

    public:
        Episode (int id, std::string name, int length, std::vector<int> seasons, std::vector<std::string> tags);
        Watchable* get_next_watchable(const Session& session);
        std::vector<int> get_seasons() const;

};
