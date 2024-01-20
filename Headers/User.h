#pragma once


#include <vector>
#include <string>
#include "Watchable.h"

class Watchable;

class User
{
    protected:
        std::string name;
        // maybe hold only string
        // and have method in other class that returns watch string
        std::vector<Watchable> watch_history;
    
    public:
        virtual Watchable get_recommendation() = 0;

};


class LengthBasedUser : User
{

};


class RerunBasedUser : User
{

};


class SimilarGenreBasedUser : User
{

};
