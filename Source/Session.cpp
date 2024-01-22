#include "Session.h"


Session::Session(std::string config_path)
:m_json_handler(config_path)
{
    // std::vector<std::string> tags;
    // tags.reserve(5);
    m_available_movies_content.reserve(10);

    rapidjson::Value& movies = m_json_handler.get_doc()["movies"];
    for(auto& movie : movies.GetArray()){
        m_available_movies_content.emplace_back(Movies( 1, 
                                                        movie["name"].GetString(), 
                                                        movie["length"].GetInt(),
                                                        {"fucking tag"}));
    }
}

void Session::start()
{
    std::cout << "\nSPLFLIX is now on! \n";

    std::cout << "\n\n(MOVIES)";
    m_json_handler.get_movies();
    
    std::cout << "\n\n(TV SHOWS)";
    m_json_handler.get_episodes();

}
