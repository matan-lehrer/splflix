#pragma once 

#include <vector>
#include "Watchable.h"
#include "User.h"
#include "Action.h"
#include "JsonHandler.h"


class Session
{

    private:
        std::vector<Watchable> available_watching_content;
        std::vector<User> users;
        std::vector<User> current_active_users;
        // maybe turn into string and have action print the log
        // and use return value to push back vector
        std::vector<BaseAction> action_log; 
        JsonHandler json_handler;

    public:

};