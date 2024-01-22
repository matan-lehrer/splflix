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
        std::vector<std::unique_ptr<Watchable>> m_available_watching_content;
        std::vector<std::unique_ptr<User>> m_users;
        std::map<std::string, std::unique_ptr<BaseAction>> m_action_menu;
        std::vector<std::unique_ptr<User>> m_current_active_users;
        std::vector<std::unique_ptr<std::string>> m_action_log;         

        void fill_available_content();
        void init_default_user();
        void fill_action_menu();
        bool is_valid_action(const std::string action_input);

        std::vector<std::string> get_user_input();

    public:
        Session(std::string config_path);
        void print_available_content();
        void start();
};
