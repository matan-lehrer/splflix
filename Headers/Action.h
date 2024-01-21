#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Session.h"


class Session;


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
        virtual void act(Session& session) = 0;
        virtual std::string to_string() = 0;
};


class CreateUser : public BaseAction
{
    public:
        void act(Session& session);
        std::string to_string();
};


class ChangeActiveUser : public BaseAction
{
    public:
        void act(Session& session);
        std::string to_string();
};


class DeleteUser : public BaseAction
{
    public:
        void act(Session& session);
        std::string to_string();

};


class DuplicateUser : public BaseAction
{
    public:
        void act(Session& session);
        std::string to_string();
};


class PrintContentList : public BaseAction
{
    public:
        void act(Session& session);
        std::string to_string();
};


class PrintWatchHistory : public BaseAction
{
    public:
        void act(Session& session);
        std::string to_string();

};


class Watch : public BaseAction
{
    public:
        void act(Session& session);
        std::string to_string();

};


class PrintActionLog : public BaseAction
{
    public:
        void act(Session& session);
        std::string to_string();

};


class Exit : public BaseAction
{
    public:
        void act(Session& session);
        std::string to_string();

};
