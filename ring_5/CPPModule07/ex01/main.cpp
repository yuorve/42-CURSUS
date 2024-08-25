/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 06:49:45 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/25 06:58:31 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Iter.hpp"

template<typename T>
void print(T &x)
{
    std::cout << x << " ";
}

int main()
{
    int     intArray[] = {1, 2, 3, 4, 5};
	char	str[] = {'a', 'b', 'c'};
    double  doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "Int array: ";
    ::iter(intArray, 5, print<int>);
    std::cout << std::endl;

    std::cout << "Double array: ";
    ::iter(doubleArray, 5, print<double>);
    std::cout << std::endl;  

	std::cout << "Iter of 3 char: ";
	::iter(str, 3, print<char>);
    std::cout << std::endl;
    
    return 0;
}
