#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class PmergeMe {
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;

    std::vector<int> fordJohnsonVector(std::vector<int>& arr);
    std::deque<int> fordJohnsonDeque(std::deque<int>& arr);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void run(int argc, char** argv);
};

#endif