/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 09:41:00 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/25 10:29:05 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) { }

Span & Span::operator=(Span const & rhs)
{
    if (this != &rhs) {
        this->_N = rhs._N;
        this->_numbers = rhs._numbers;
    }
    return *this;
}

Span::Span(Span const & obj)
{
    *this = obj;
}

Span::~Span() { }

Span::Span(unsigned int N) : _N(N)
{
    this->_numbers.reserve(_N);
}

void Span::addNumber(int number)
{
    if (_numbers.size() == _numbers.capacity())
		throw std::runtime_error("Span is full");
	else
		_numbers.push_back(number);
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
            throw std::runtime_error("Not enough numbers to calculate span");

        std::vector<int> sorted = _numbers;
        std::sort(sorted.begin(), sorted.end());

        int minSpan = std::numeric_limits<int>::max();
        for (size_t i = 1; i < sorted.size(); ++i)
        {
            int span = sorted[i] - sorted[i-1];
            if (span < minSpan)
                minSpan = span;
        }

        return minSpan;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
            throw std::runtime_error("Not enough numbers to calculate span");

        return *std::max_element(_numbers.begin(), _numbers.end()) - 
               *std::min_element(_numbers.begin(), _numbers.end());
}

void Span::fillVector(unsigned int n)
{
    unsigned int i = 1;
	std::srand(unsigned(std::time(0)));
    while (i < n)
    {        
        addNumber(std::rand());
        i++;        
    }
}
