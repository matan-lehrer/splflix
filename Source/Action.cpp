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
{
    
}

std::string CreateUser::to_string()
{
    return "createuser";
}


// ChangeActiveUser
void ChangeActiveUser::act(Session& sess)
{

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
