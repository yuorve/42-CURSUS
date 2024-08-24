/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:04:31 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/23 11:25:14 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char ** argv)
{
    if (argc == 2)
    {
        ScalarConverter::convert(argv[1]);        
        return (0);
    } else {
        std::cout << "Usage: ./ScalarConverter [number]" << std::endl;
        return (1);
    }
}
