#include "PmergeMe.hpp"
#include <sys/time.h>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    _vectorData = other._vectorData;
    _dequeData = other._dequeData;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return arr;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> largerElements;
    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = hasStraggler ? arr.back() : -1;

    for (size_t i = 0; i < arr.size() - (hasStraggler ? 1 : 0); i += 2) {
        if (arr[i] < arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
        else {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        }
        largerElements.push_back(pairs.back().first);
    }

    std::vector<int> mainChain = fordJohnsonVector(largerElements);

    std::vector<int> pendElements;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == mainChain[i]) {
                pendElements.push_back(pairs[j].second);
                break;
            }
        }
    }

    if (!pendElements.empty()) {
        mainChain.insert(mainChain.begin(), pendElements[0]);
    }

    size_t jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
    size_t jIdx = 1;

    while (jacobsthal[jIdx] - 1 < pendElements.size()) {
        size_t start = jacobsthal[jIdx] - 1;
        size_t end = jacobsthal[jIdx - 1];

        for (size_t i = start; i >= end; --i) {
            if (i < pendElements.size()) {
                std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pendElements[i]);
                mainChain.insert(it, pendElements[i]);
            }
        }
        jIdx++;
    }

    size_t lastCovered = jacobsthal[jIdx - 1];
    for (size_t i = pendElements.size() - 1; i >= lastCovered; --i) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pendElements[i]);
        mainChain.insert(it, pendElements[i]);
    }

    if (hasStraggler) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    return mainChain;
}

std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return arr;

    std::deque<std::pair<int, int> > pairs;
    std::deque<int> largerElements;
    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = hasStraggler ? arr.back() : -1;

    for (size_t i = 0; i < arr.size() - (hasStraggler ? 1 : 0); i += 2) {
        if (arr[i] < arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        } else {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        }
        largerElements.push_back(pairs.back().first);
    }

    std::deque<int> mainChain = fordJohnsonDeque(largerElements);

    std::deque<int> pendElements;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == mainChain[i]) {
                pendElements.push_back(pairs[j].second);
                break;
            }
        }
    }

    if (!pendElements.empty()) {
        mainChain.push_front(pendElements[0]);
    }

    size_t jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
    size_t jIdx = 1;

    while (jacobsthal[jIdx] - 1 < pendElements.size()) {
        size_t start = jacobsthal[jIdx] - 1;
        size_t end = jacobsthal[jIdx - 1];
        for (size_t i = start; i >= end; --i) {
            if (i < pendElements.size()) {
                std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pendElements[i]);
                mainChain.insert(it, pendElements[i]);
            }
        }
        jIdx++;
    }

    size_t lastCovered = jacobsthal[jIdx - 1];
    for (size_t i = pendElements.size() - 1; i >= lastCovered; --i) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pendElements[i]);
        mainChain.insert(it, pendElements[i]);
    }

    if (hasStraggler) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    return mainChain;
}

void PmergeMe::run(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.empty()) {
            std::cerr << "Error" << std::endl;
            return;
        }
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!isdigit(arg[j])) {
                std::cerr << "Error" << std::endl;
                return;
            }
        }
        int val = std::atoi(arg.c_str());
        if (val < 0) {
            std::cerr << "Error" << std::endl;
            return;
        }
        _vectorData.push_back(val);
        _dequeData.push_back(val);
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < _vectorData.size(); ++i) {
        std::cout << _vectorData[i] << " ";
    }
    std::cout << std::endl;

    struct timeval start, end;

    gettimeofday(&start, NULL);
    std::vector<int> sortedVector = fordJohnsonVector(_vectorData);
    gettimeofday(&end, NULL);
    double vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    std::deque<int> sortedDeque = fordJohnsonDeque(_dequeData);
    gettimeofday(&end, NULL);
    double dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    std::cout << "After:  ";
    for (size_t i = 0; i < sortedVector.size(); ++i) {
        std::cout << sortedVector[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vectorData.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeData.size() << " elements with std::deque  : " << dequeTime << " us" << std::endl;
}
