#include "Session.h"


// public
Session::Session(std::string config_path)
:m_json_handler(config_path)
{
    fill_available_content();
    init_default_user();
    fill_action_menu();

    m_current_active_users.reserve(5);
    m_action_log.reserve(10);
}

void Session::print_available_content()
{
    for(const auto& watchable_content : m_available_watching_content){
        watchable_content->print_description();
    }
}

void Session::start()
{
    std::cout << "\nSPLFLIX is now on! \n";

    std::vector<std::string> parsed_user_input;


    while(true){
        parsed_user_input = get_user_input();
        this->m_action_menu[parsed_user_input.at(0)]->act(*this);
        
        std::cout << "input is: ";
        print_vector<std::string>(parsed_user_input);
    }
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
    m_users.reserve(5);
    m_users.emplace_back(std::make_unique<LengthBasedUser>(LengthBasedUser("default")));
}

void Session::fill_action_menu()
{
    m_action_menu.emplace("createuser", std::make_unique<CreateUser>(CreateUser()));
    m_action_menu.emplace("changeuser", std::make_unique<ChangeActiveUser>(ChangeActiveUser()));
    m_action_menu.emplace("deleteuser", std::make_unique<DeleteUser>(DeleteUser()));
    m_action_menu.emplace("dupuser", std::make_unique<DuplicateUser>(DuplicateUser()));
    m_action_menu.emplace("content", std::make_unique<PrintContentList>(PrintContentList()));
    m_action_menu.emplace("watchist", std::make_unique<PrintWatchHistory>(PrintWatchHistory()));
    m_action_menu.emplace("log", std::make_unique<PrintActionLog>(PrintActionLog()));
    m_action_menu.emplace("watch", std::make_unique<Watch>(Watch()));
    m_action_menu.emplace("exit", std::make_unique<Exit>(Exit()));
}

std::vector<std::string> Session::get_user_input()
{
    std::string user_input;
    std::vector<std::string> result;

    std::cout << "\n\n(CHOOSE ACTION) \n\n\n"; 

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
