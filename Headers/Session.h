#pragma once 

#include <vector>
#include <memory>
#include "Watchable.h"
#include "User.h"
#include "Action.h"
#include "JsonHandler.h"
#include "Utilities.h"

class BaseAction;

class Watchable;
class Movies;
class Episode;

class User;
class LengthBasedUser;
class RerunBasedUser;
class SimilarGenreBasedUser;

class Session
{

    private:
        JsonHandler m_json_handler;
        std::vector<std::unique_ptr<Watchable>> m_available_watching_content;
        std::vector<std::unique_ptr<User>> m_users;

        std::vector<std::unique_ptr<User>> m_current_active_users;
        std::vector<std::unique_ptr<BaseAction>> m_action_log; 

        void fill_available_content();
        void init_default_user();

    public:
        Session(std::string config_path);
        void print_available_content();
        void start();
};
