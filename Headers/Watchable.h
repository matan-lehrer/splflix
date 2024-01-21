#pragma once

#include <vector>
#include <string>
#include "Session.h"

class Session;

class Watchable
{
    protected:
        int id;
        std::string name;
        int length;
        std::vector<std::string> tags;

    public:
        virtual Watchable* get_next_watchable(const Session& session) = 0;

};


class Movies : public Watchable
{
    public:
        Watchable* get_next_watchable(const Session& session);
};


class Episode : public Watchable
{
    public:
        Watchable* get_next_watchable(const Session& session);
};
