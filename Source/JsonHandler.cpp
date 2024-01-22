#include "JsonHandler.h"

JsonHandler::JsonHandler(std::string json_path)
:m_file(json_path), 
 m_json((std::istreambuf_iterator<char>(this->m_file)), std::istreambuf_iterator<char>())
{
    this->m_doc.Parse(this->m_json.c_str()); 

    if (this->m_doc.HasParseError()) {
        std::cerr << "Error parsing JSON: " 
                  << this->m_doc.GetParseError() << std::endl;
    }
}

void JsonHandler::print_json() const
{
    std::cout << m_json.c_str();
}


void JsonHandler::get_movies()
{
    rapidjson::Value& movies = this->m_doc["movies"];
    for(auto& movie : movies.GetArray()){
        std::cout << "\n" << movie["name"].GetString();
    }
}


void JsonHandler::get_episodes()
{
    rapidjson::Value& episodes = this->m_doc["tv_series"];
    for(auto& tv_show : episodes.GetArray()){
        std::cout << "\n" << tv_show["name"].GetString();
    }
}


rapidjson::Document& JsonHandler::get_doc() 
{
    return this->m_doc;
}

