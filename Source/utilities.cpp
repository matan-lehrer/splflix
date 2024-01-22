#include "utilities.h"


template<typename T>
void print_vector(std::vector<T> vec)
{
    for(const auto& item: vec){
        std::cout << item << ", ";
    }
    std::cout << "\n";
}