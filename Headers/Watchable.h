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

};


class Movies : public Watchable
{
    public:
        Movies (int id, std::string name, int length, std::vector<std::string> tags);
        Watchable* get_next_watchable(const Session& session);
};


class Episode : public Watchable
{
    public:
        Episode (int id, std::string name, int length, std::vector<std::string> tags);
        Watchable* get_next_watchable(const Session& session);
};
