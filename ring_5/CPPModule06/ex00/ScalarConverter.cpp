/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:14:40 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/23 11:25:25 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
    (void) rhs;
    return *this;
}
ScalarConverter::ScalarConverter(ScalarConverter const & obj)
{
    *this = obj;
}

ScalarConverter::ScalarConverter() { }

ScalarConverter::~ScalarConverter() { }

bool isChar(const std::string & str) {
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool isInt(const std::string & str) {
    try {
        std::stoi(str);
        return true;
    } catch (...) {
        return false;
    }
}

bool isFloat(const std::string &str) {
    try {
        std::stof(str);
        return (str.find('f') != std::string::npos);
    } catch (...) {
        return false;
    }
}

bool isDouble(const std::string &str) {
    try {
        std::stod(str);
        return (str.find('f') == std::string::npos);
    } catch (...) {
        return false;
    }
}

void printChar(double value) {
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible" << std::endl;
    } else if (value < 32 || value > 126) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
}

void printInt(double value) {
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

void printFloat(double value) {
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void printDouble(double value) {
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(std::string const & literal)
{
double value = 0;    
    
    if (isChar(literal)) {
        value = literal[1];
    } else if (isInt(literal)) {
        value = std::stoi(literal);
    } else if (isFloat(literal)) {
        value = std::stof(literal);
    } else if (isDouble(literal)) {
        value = std::stod(literal);
    } else {
        std::cerr << "Error: invalid literal." << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);    
}
