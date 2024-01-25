#include "Session.h"
#include "Tests.h"


constexpr bool DEBUGGING = true;


int main(int argc, char **argv) 
{

    if(argc != 2){
        std::cerr << "missing json file...\n" 
                     "exiting...\n";
        exit(1);
    }

    Session session(argv[1]);
    
    if(!DEBUGGING){
        session.start();
    }

    else{
        run_tests(session);
    }
    
    return 0;
}
