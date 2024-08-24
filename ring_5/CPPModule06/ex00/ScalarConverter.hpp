/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:14:40 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/23 11:22:24 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>

enum    _type
{
	NONE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	LITERALS
};

class ScalarConverter
{
    private : 
        ScalarConverter & operator=(ScalarConverter const & rhs);
        ScalarConverter(ScalarConverter const & obj);
        ScalarConverter();
        ~ScalarConverter();

    public :
        static void convert(std::string const & literal);
};
#endif
