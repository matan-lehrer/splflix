#pragma once

#include "../Json/rapidjson/document.h"
#include <fstream>
#include <iostream>


class JsonHandler
{
    private:
        std::ifstream m_file;
        std::string m_json;
        rapidjson::Document m_doc;  

    public:
        JsonHandler(std::string json_path);
        void print_json() const;
        rapidjson::Document& get_doc();

};
