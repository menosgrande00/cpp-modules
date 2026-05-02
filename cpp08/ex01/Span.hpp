#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iostream>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end) {
            if (_numbers.size() + std::distance(begin, end) > _maxSize) {
                throw FullSpanException();
            }
            _numbers.insert(_numbers.end(), begin, end);
        }

        class FullSpanException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Error: Span capacity is full!";
            }
        };

        class NotEnoughElementsException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Error: Need at least 2 elements!";
            }
        };
};

#endif