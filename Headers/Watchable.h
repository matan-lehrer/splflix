#pragma once

#include <vector>
#include <string>
#include "Session.h"


class Watchable
{
    protected:
        int id;
        std::string name;
        int length;
        std::vector<std::string> tags;

    public:
        virtual Watchable* get_next_watchable(const Session&) = 0;

};


class Movies : Watchable
{
    public:
        Watchable* get_next_watchable(const Session&) = 0;
};


class Episode : Watchable
{
    public:
        Watchable* get_next_watchable(const Session&) = 0;
};