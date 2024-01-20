#pragma once


#include <vector>
#include <string>
#include "Session.h"


enum Flag
{
    COMPLETED,
    PENDING,
    ERROR
};


class BaseAction
{
    protected:
        Flag status;

        void complete();
        void error(std::string err_msg);


    public:
        virtual void act(Session& sess) = 0;
        virtual std::string to_string() = 0;
};


class CreateUser : BaseAction
{
    public:
        void act(Session& sess);
        std::string to_string();
};


class ChangeActiveUser : BaseAction
{
    public:
        void act(Session& sess);
        std::string to_string();
};


class DeleteUser : BaseAction
{
    public:
        void act(Session& sess);
        std::string to_string();

};


class DuplicateUser : BaseAction
{
    public:
        void act(Session& sess);
        std::string to_string();
};


class PrintContentList : BaseAction
{
    public:
        void act(Session& sess);
        std::string to_string();
};


class PrintWatchHistory : BaseAction
{
    public:
        void act(Session& sess);
        std::string to_string();

};


class Watch : BaseAction
{
    public:
        void act(Session& sess);
        std::string to_string();

};


class PrintActionLog : BaseAction
{
    public:
        void act(Session& sess);
        std::string to_string();

};


class Exit : BaseAction
{
    public:
        void act(Session& sess);
        std::string to_string();

};
