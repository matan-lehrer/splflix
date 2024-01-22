#include "Session.h"


Session::Session(std::string config_path)
:m_json_handler(config_path)
{
    fill_available_content();
    init_default_user();
}


void Session::fill_available_content()
{

    m_available_watching_content.reserve(15);

    int id = 0;
    std::vector<std::string> tags;
    tags.reserve(5);

    std::vector<int> seasons;
    tags.reserve(10);

    rapidjson::Value& movies = m_json_handler.get_doc()["movies"];
    for(auto& movie : movies.GetArray()){

        tags.clear();
        for (auto& tag : movie["tags"].GetArray()) {
            tags.push_back(tag.GetString());
        }

        m_available_watching_content.emplace_back(
            std::make_unique<Movies>( Movies(  id, 
                                                movie["name"].GetString(), 
                                                movie["length"].GetInt(),
                                                tags)));
        id++;
    }

    rapidjson::Value& episodes = m_json_handler.get_doc()["tv_series"];
    for(auto& episode : episodes.GetArray()){

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
        id++;
}
}


void Session::init_default_user()
{
    m_users.reserve(5);
    m_users.emplace_back(std::make_unique<LengthBasedUser>(LengthBasedUser("default")));

    std::cout << "Users length: " << m_users.size() << "\n";
    std::cout << "User name: " << m_users[0]->get_name() << "\n\n";
}


void Session::print_available_content()
{
    // for(auto movie : m_available_movies_content){
    //     std::cout << "\n(MOVIE)\n";
    //     std::cout << "id: " << movie.get_id() << "\n";
    //     std::cout << "name: " << movie.get_name()<< "\n";
    //     std::cout << "first tag: " << movie.get_tags().at(0) << "\n";
    //     std::cout << "length: " << movie.get_length()<< "\n";
    //     std::cout << "tags: ";
    //     print_vector<std::string>(movie.get_tags());
    //     std::cout << "\n";
    // }

    // for(auto episode : m_available_episodes_content){
    //     std::cout << "\n(Episode)\n";
    //     std::cout << "id: " << episode.get_id() << "\n";
    //     std::cout << "name: " << episode.get_name()<< "\n";
    //     std::cout << "length: " << episode.get_length()<< "\n";
        
    //     std::cout << "seasons: ";
    //     print_vector<int>(episode.get_seasons());
        
    //     std::cout << "tags: ";
    //     print_vector<std::string>(episode.get_tags());
        
    //     std::cout << "\n";

    // }
}


void Session::start()
{
    std::cout << "\nSPLFLIX is now on! \n";

    // std::cout << "\n\n(episodeS)";
    // m_json_handler.get_movies();
    
    // std::cout << "\n\n(TV SHOWS)";
    // m_json_handler.get_episodes();

}
