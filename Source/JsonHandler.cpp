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


rapidjson::Document& JsonHandler::get_doc() 
{
    return this->m_doc;
}
