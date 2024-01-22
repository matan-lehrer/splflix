#pragma once

#include <iostream>
#include <vector>


template <typename T>
void print_vector(std::vector<T> vec)
{
    std::cout << "[ ";
    for(const auto& item: vec){
        std::cout << item << " ";
    }
    std::cout << "]\n";
}
