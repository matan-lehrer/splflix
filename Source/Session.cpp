#include "Session.h"


Session::Session(std::string config_path)
:m_json_handler(config_path)
{
    // m_json_handler.get_doc();

    rapidjson::Value& movies = m_json_handler.get_doc()["movies"];
    for(auto& movie : movies.GetArray()){
        std::cout << "\n" << movie["name"].GetString();
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
