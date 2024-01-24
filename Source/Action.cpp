#include "Action.h"


//Base Action
void BaseAction::complete()
{
    status = Flag::COMPLETED;
}

void BaseAction::error(std::string err_msg)
{
    std::cerr << err_msg << "\n";
    status = Flag::ERROR;
}


// CreateUser
void CreateUser::act(Session& sess)
// use here builder pattern! gets 3 - letters and returns instance of...
{
    const std::string user_name = sess.get_parsed_user_input().at(1);
    const std::string recomendation = sess.get_parsed_user_input().at(2);
    std::shared_ptr<User> new_user;

    if("len" == recomendation){
        new_user = std::make_shared<LengthBasedUser>(LengthBasedUser(user_name));
        sess.get_users_map().emplace(new_user->get_name(), new_user);
    }

    else if("rer" == recomendation){
        new_user = std::make_shared<RerunBasedUser>(RerunBasedUser(user_name));
        sess.get_users_map().emplace(new_user->get_name(), new_user);
    }

    else if("gen" == recomendation){
        new_user = std::make_shared<SimilarGenreBasedUser>(SimilarGenreBasedUser(user_name));
        sess.get_users_map().emplace(new_user->get_name(), new_user);
    }
    
    else{
        error("no such recomendation...");
        return;
    }

    new_user->print_details();
}

std::string CreateUser::to_string()
{
    return "createuser";
}


// ChangeActiveUser
void ChangeActiveUser::act(Session& sess)
{
    const std::string user_name = sess.get_parsed_user_input().at(1);
    std::shared_ptr<User> next_user = sess.get_users_map().at(user_name);
    sess.set_current_active_user(next_user);
    next_user->print_details();
}

std::string ChangeActiveUser::to_string()
{
    return "changeuser";
}


// DeleteUser
void DeleteUser::act(Session& sess)
{

}

std::string DeleteUser::to_string()
{
    return "deleteuser";
}


// DuplicateUser
void DuplicateUser::act(Session& sess)
{

}

std::string DuplicateUser::to_string()
{
    return "dupuser";
}


// PrintContentList
void PrintContentList::act(Session& sess)
{
    std::cout << "\n\n___________(CONTENT LIST)___________ \n";
    for(const auto& watchable_content : sess.get_available_watching_content()){
        watchable_content->print_description();
    }
    std::cout << "***********************************\n";

}

std::string PrintContentList::to_string()
{
    return "content";
}


// PrintWatchHistory
void PrintWatchHistory::act(Session& sess)
{

}

std::string PrintWatchHistory::to_string()
{
    return "watchist";
}


// PrintActionLog
void PrintActionLog::act(Session& sess)
{
    int index = 1;
    std::cout << "\n\n___________(LOG LIST)___________ \n\n";
    for(const auto& log: sess.get_action_log()){
        std::cout<< index << ". ";
        print_vector<std::string>(log);
        index++;
    }
    std::cout << "\n********************************\n";

}

std::string PrintActionLog::to_string()
{
    return "log";
}


// Watch
void Watch::act(Session& sess)
{

}

std::string Watch::to_string()
{
    return "watch";
}


// Exit
void Exit::act(Session& sess)
{
    throw BreakLoopException();
}

std::string Exit::to_string()
{
    return "exit";
}
