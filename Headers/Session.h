#pragma once 

#include <vector>
#include <map>
#include <memory>
#include <sstream>
#include <algorithm>
#include "Watchable.h"
#include "User.h"
#include "Action.h"
#include "JsonHandler.h"
#include "Utilities.h"

// Actions
class BaseAction;
class CreateUser;
class ChangeActiveUser;
class DeleteUser;
class DuplicateUser;
class PrintContentList;
class PrintWatchHistory;
class PrintActionLog;
class Watch;
class Exit;

// Watchables
class Watchable;
class Movies;
class Episode;

// Users
class User;
class LengthBasedUser;
class RerunBasedUser;
class SimilarGenreBasedUser;


class Session
{

    private:
        JsonHandler m_json_handler;
        std::unordered_map<std::string, std::unique_ptr<BaseAction>> m_action_menu;
        std::map<std::string, std::shared_ptr<User>> m_users;
        std::shared_ptr<User> m_current_active_user;
        std::vector<std::unique_ptr<Watchable>> m_available_watching_content;
        std::vector<std::vector<std::string>> m_action_log; 
        std::vector<std::string> m_parsed_user_input;        

        // private - functions
        void init_default_user();
        void fill_available_content();
        void fill_action_menu();
        bool is_valid_action(const std::string action_input);
        std::vector<std::string> get_user_input();

    public:
        Session(std::string config_path);
        void start();

        // getters
        const std::vector<std::vector<std::string>>& get_action_log() const;
        const std::vector<std::unique_ptr<Watchable>>& get_available_watching_content() const;
        std::map<std::string, std::shared_ptr<User>>& get_users_map();
        const std::vector<std::string>& get_parsed_user_input() const;  
        std::shared_ptr<User>& get_current_active_user();    
        std::shared_ptr<User>& get_user(std::string name);

        //setters
        void set_current_active_user(std::shared_ptr<User>);
        void add_users_map(std::string name, std::shared_ptr<User>& new_user);
};
