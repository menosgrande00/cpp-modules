#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;

    std::cout << "\n--- 15.000 ---" << std::endl;
    Span bigSpan(15000);
    std::vector<int> randomNumbers;
    
    srand(time(NULL));
    for (int i = 0; i < 15000; ++i) {
        randomNumbers.push_back(rand() % 1000000);
    }

    try {
        bigSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());
        
        std::cout << "15.000 numbers added." << std::endl;
        std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << bigSpan.longestSpan() << std::endl;
        
        bigSpan.addNumber(42); 
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n-------------------" << std::endl;
    Span tinySpan(5);
    tinySpan.addNumber(100);
    try {
        tinySpan.shortestSpan();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}