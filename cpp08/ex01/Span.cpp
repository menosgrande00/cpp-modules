#include "Span.hpp"
#include <algorithm>
#include <numeric>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw FullSpanException();
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw NotEnoughElementsException();
    }

    std::vector<int> copy = _numbers;

    std::sort(copy.begin(), copy.end());
    int min_span = copy[1] - copy[0];

    for (size_t i = 1; i < copy.size(); ++i) {
        int diff = copy[i] - copy[i - 1];
        if (diff < min_span) {
            min_span = diff;
        }
    }

    return min_span;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw NotEnoughElementsException();
    }

    std::vector<int>::const_iterator min_it = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator max_it = std::max_element(_numbers.begin(), _numbers.end());

    return *max_it - *min_it;
}