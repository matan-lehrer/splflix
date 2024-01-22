#include "Session.h"


Session::Session(std::string config_path)
:m_json_handler(config_path)
{
    fill_available_content();
}


void Session::fill_available_content()
{
    std::vector<std::string> tags;
    tags.reserve(5);

    m_available_movies_content.reserve(10);

    rapidjson::Value& movies = m_json_handler.get_doc()["movies"];
    for(auto& movie : movies.GetArray()){

        tags.clear();
        for (auto& tag : movie["tags"].GetArray()) {
            tags.push_back(tag.GetString());
        }

        m_available_movies_content.emplace_back(Movies( 1, 
                                                        movie["name"].GetString(), 
                                                        movie["length"].GetInt(),
                                                        tags));
    }

    rapidjson::Value& episodes = m_json_handler.get_doc()["tv_series"];
    for(auto& episode : episodes.GetArray()){

        tags.clear();
        for (auto& tag : episode["tags"].GetArray()) {
        tags.push_back(tag.GetString());
        }

        m_available_episodes_content.emplace_back(Episode( 1, 
                                                            episode["name"].GetString(), 
                                                            episode["episode_length"].GetInt(),
                                                            {10, 20, 30, 40},
                                                            tags));
}
}


void Session::print_available_content()
{
    for(auto movie : m_available_movies_content){
        std::cout << "\n(MOVIE)\n";
        std::cout << "id: " << movie.get_id() << "\n";
        std::cout << "name: " << movie.get_name()<< "\n";
        std::cout << "first tag: " << movie.get_tags().at(0) << "\n";
        std::cout << "length: " << movie.get_length()<< "\n\n";

    }

    for(auto episode : m_available_episodes_content){
        std::cout << "\n(Episode)\n";
        std::cout << "id: " << episode.get_id() << "\n";
        std::cout << "name: " << episode.get_name()<< "\n";
        std::cout << "first tag: " << episode.get_tags().at(0) << "\n";
        std::cout << "length: " << episode.get_length()<< "\n\n";

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
