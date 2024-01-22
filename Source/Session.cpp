#include "Session.h"


Session::Session(std::string config_path)
:m_json_handler(config_path)
{
    fill_available_content();
    init_default_user();
    
    m_current_active_users.reserve(5);
    m_action_log.reserve(10);
}


void Session::fill_available_content()
{
    int id = 0;
    std::vector<std::string> tags;
    std::vector<int> seasons;

    m_available_watching_content.reserve(15);   
    tags.reserve(5);
    seasons.reserve(10);

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

    // std::cout << "Users length: " << m_users.size() << "\n";
    // std::cout << "User name: " << m_users[0]->get_name() << "\n\n";
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

    // std::cout << "\n\n(episodeS)";
    // m_json_handler.get_movies();
    
    // std::cout << "\n\n(TV SHOWS)";
    // m_json_handler.get_episodes();

}
