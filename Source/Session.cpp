#include "Session.h"


// public
Session::Session(const std::string config_path)
:m_json_handler(config_path)
{
    init_default_user();
    fill_available_content();
    fill_action_menu();
    
    m_action_log.reserve(10);
}

void Session::start()
{
    std::cout << "\nSPLFLIX is now on! \n";

    try {
        while(true) {
            m_parsed_user_input = get_user_input();
            std::string action = m_parsed_user_input.at(0);

            if(is_valid_action(action)){
                m_action_log.push_back(m_parsed_user_input);
                this->m_action_menu.at(action)->act(*this);
            }

            else{
                std::cout << "\nno such action! \n" <<
                             "please try another action ...\n\n";
                continue;
            }
        }
    } catch (const BreakLoopException& e) {
        std::cout << e.what();
    }
}


// getters
const std::vector<std::vector<std::string>>& Session::get_action_log() const
{
    return m_action_log;
}

const std::vector<std::unique_ptr<Watchable>>& Session::get_available_watching_content() const
{
    return m_available_watching_content;
}

std::map<std::string, std::shared_ptr<User>>& Session::get_users_map()
{
    return m_users;
}

const std::vector<std::string>& Session::get_parsed_user_input() const
{
    return m_parsed_user_input;
}

std::shared_ptr<User>& Session::get_current_active_user() 
{
    return m_current_active_user;
}

std::shared_ptr<User>& Session::get_user(std::string name)
{
    return m_users[name];
}


// setters
void Session::set_current_active_user(std::string next_user)
{
    m_current_active_user = m_users[next_user];
}

void Session::add_users_map(std::string name, std::shared_ptr<User>& new_user)
{
    m_users.emplace(name, new_user);
}


// private
void Session::fill_available_content()
{
    int id = 0;
    std::vector<std::string> tags;
    std::vector<int> seasons;

    m_available_watching_content.reserve(15);   
    tags.reserve(5);
    seasons.reserve(10);

    // fill movies
    rapidjson::Value& movies = m_json_handler.get_doc()["movies"];
    for(auto& movie : movies.GetArray()){
        id++;
        
        tags.clear();
        for (auto& tag : movie["tags"].GetArray()) {
            tags.push_back(tag.GetString());
        }

        m_available_watching_content.emplace_back(
            std::make_unique<Movies>( Movies(  id, 
                                                movie["name"].GetString(), 
                                                movie["length"].GetInt(),
                                                tags)));
    }

    // fill episodes
    rapidjson::Value& episodes = m_json_handler.get_doc()["tv_series"];
    for(auto& episode : episodes.GetArray()){
        id++;
        
        tags.clear();
        for (auto& tag : episode["tags"].GetArray()) {
            tags.push_back(tag.GetString());
        }

        seasons.clear();
        for (auto& season : episode["seasons"].GetArray()) {
            seasons.push_back(season.GetInt());
        }

        m_available_watching_content.emplace_back(
            std::make_unique<Episode>(Episode(  id, 
                                                episode["name"].GetString(), 
                                                episode["episode_length"].GetInt(),
                                                seasons,
                                                tags)));
}
}

void Session::init_default_user()
{
    m_current_active_user = std::make_shared<LengthBasedUser>(LengthBasedUser("default"));
    m_users.emplace(m_current_active_user->get_name(), m_current_active_user);

}

void Session::fill_action_menu()
{
    m_action_menu.emplace("exit", std::make_unique<Exit>(Exit()));
    m_action_menu.emplace("watch", std::make_unique<Watch>(Watch()));
    m_action_menu.emplace("log", std::make_unique<PrintActionLog>(PrintActionLog()));
    m_action_menu.emplace("watchist", std::make_unique<PrintWatchHistory>(PrintWatchHistory()));
    m_action_menu.emplace("users", std::make_unique<PrintUsersList>(PrintUsersList()));
    m_action_menu.emplace("content", std::make_unique<PrintContentList>(PrintContentList()));
    m_action_menu.emplace("dupuser", std::make_unique<DuplicateUser>(DuplicateUser()));
    m_action_menu.emplace("deleteuser", std::make_unique<DeleteUser>(DeleteUser()));
    m_action_menu.emplace("changeuser", std::make_unique<ChangeActiveUser>(ChangeActiveUser()));
    m_action_menu.emplace("createuser", std::make_unique<CreateUser>(CreateUser()));
}

std::vector<std::string> Session::get_user_input()
{
    std::string user_input;
    std::vector<std::string> result;

    std::cout << "\n\n___________(ACTION MENU)___________ \n\n"; 

    for(auto& action : m_action_menu){
        std::cout << "<" << action.second->to_string() << "> \n";
    }
    std::cout << "\n"; 
    
    std::getline(std::cin, user_input);
    std::istringstream iss(user_input);
    for(std::string s; iss >> s; ) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        result.push_back(s);
    }
    
    return result;
}

bool Session::is_valid_action(const std::string action_input)
{
    for(auto& action : m_action_menu){
        if(action_input == action.first){
            return true;
        }
    }
    return false;
}
