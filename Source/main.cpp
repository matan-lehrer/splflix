#include "JsonHandler.h"

int main(int argc, char **argv) 
{

    if(argc != 2){
        std::cerr << "missing json file...\n" 
                     "exiting...\n";
        exit(1);
    }

    std::cout << "SPLFLIX is now on! \n";

    JsonHandler json_handler(argv[1]);

    std::cout << "\n\n(MOVIES)";
    json_handler.get_movies();
    
    std::cout << "\n\n(TV SHOWS)";
    json_handler.get_tv_series();

    return 0;
}
