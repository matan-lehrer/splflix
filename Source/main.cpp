#include "Session.h"


int main(int argc, char **argv) 
{

    if(argc != 2){
        std::cerr << "missing json file...\n" 
                     "exiting...\n";
        exit(1);
    }


    Session session(argv[1]);
    session.start();
    session.print_available_content();

    
    return 0;
}
