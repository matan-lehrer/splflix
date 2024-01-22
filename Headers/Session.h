#pragma once 

#include <vector>
#include "Watchable.h"
#include "User.h"
#include "Action.h"
#include "JsonHandler.h"

class BaseAction;
class Movies;
class Episode;

class Session
{

    private:
        // std::vector<Watchable> m_available_watching_content;
        std::vector<Movies> m_available_movies_content;
        std::vector<Episode> m_available_episodes_content;

        std::vector<User> m_users;
        std::vector<User> m_current_active_users;
        std::vector<BaseAction> m_action_log; 
        JsonHandler m_json_handler;

    public:
        Session(std::string config_path);
        void print_available_content();
        void start();

};