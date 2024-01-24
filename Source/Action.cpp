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
    }

    else if("rer" == recomendation){
        new_user = std::make_shared<RerunBasedUser>(RerunBasedUser(user_name));
    }

    else if("gen" == recomendation){
        new_user = std::make_shared<SimilarGenreBasedUser>(SimilarGenreBasedUser(user_name));
    }
    
    else{
        error("no such recomendation...");
        return;
    }

    sess.add_users_map(new_user->get_name(), new_user);
    PrintUsersList().act(sess);
}

std::string CreateUser::to_string()
{
    return "createuser";
}


// ChangeActiveUser
void ChangeActiveUser::act(Session& sess)   
{
    const std::string user_name = sess.get_parsed_user_input().at(1);
    sess.set_current_active_user(user_name);
    PrintUsersList().act(sess);
}

std::string ChangeActiveUser::to_string()
{
    return "changeuser";
}


// DeleteUser
void DeleteUser::act(Session& sess)
{
    const std::string user_name = sess.get_parsed_user_input().at(1);

    if(sess.get_user(user_name) == sess.get_current_active_user()){
        error("can't delete current active user...");
        return;
    }

    sess.get_users_map().erase(user_name);
    PrintUsersList().act(sess);

}

std::string DeleteUser::to_string()
{
    return "deleteuser";
}


// DuplicateUser
void DuplicateUser::act(Session& sess)
{
    const std::string old_name = sess.get_parsed_user_input().at(1);
    const std::string new_name = sess.get_parsed_user_input().at(2);
    
    std::shared_ptr<User> new_user = sess.get_user(old_name)->clone();
    new_user->set_name(new_name);
    sess.add_users_map(new_name, new_user);

    PrintUsersList().act(sess);
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


// PrintUsersList
void PrintUsersList::act(Session& sess)
{   
    int index = 1;
    std::cout << "\n\n___________(USERS DETAILS)___________ \n\n";
    
    for(const auto& user : sess.get_users_map()){

        if(user.second == sess.get_current_active_user()){
            std::cout << "(CURRENT ACTIVE USER)\n";
        }
        std::cout << index << ". user name: " << user.first << "\n";
        std::cout << "  user recomenmdation is " << user.second->recomendation_stringified() << "\n\n";
        index++;
    }
    std::cout << "*************************************\n";
}

std::string PrintUsersList::to_string()
{
    return "users";
}


// PrintWatchHistory
void PrintWatchHistory::act(Session& sess)
{
    int index = 1;
    std::cout << "\n\n___________(WATCH HISTORY FOR - "<< sess.get_current_active_user()->get_name() << ")___________ \n\n";
    
    for(const auto& watchable_content : sess.get_current_active_user()->get_watch_history()){
        std::cout << index << ". [" << watchable_content << "] \n";
        index++;
    }
    std::cout << "\n\n***************************************************\n";
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
    const int content_id = std::stoi(sess.get_parsed_user_input().at(1));

    for(const auto& content : sess.get_available_watching_content()){
        if(content_id == content->get_id()){
            std::cout << "(WATCHING - " << content->get_name() << ") \n";
            content->print_description();
            sess.get_current_active_user()->add_watch_history(content->get_name());
            break;
        }
    }
    PrintWatchHistory().act(sess);
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
