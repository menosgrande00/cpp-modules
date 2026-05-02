#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::cout << "--- std::vector Test ---" << std::endl;
    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i * 10);
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Vector found: " << *it << std::endl;

        easyfind(vec, 99); 
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- std::list Test ---" << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try {
        std::list<int>::iterator it = easyfind(lst, 2);
        std::cout << "List found: " << *it << std::endl;

        easyfind(lst, 42); 
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}