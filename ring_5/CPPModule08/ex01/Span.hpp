/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 09:31:53 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/25 10:21:56 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <ctime>
#include <limits>
#include <algorithm>
#include <vector>

class Span
{
    private :
        unsigned int        _N;
        std::vector<int>    _numbers;
        Span();
    
    public :
        Span & operator=(Span const & rhs);
        Span(Span const & obj);
        ~Span();
        Span(unsigned int N);
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        void fillVector(unsigned int n);
};

#endif