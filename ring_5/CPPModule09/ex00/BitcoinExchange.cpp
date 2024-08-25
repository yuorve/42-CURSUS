/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:56:42 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/25 13:14:44 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{ 
    this->_database = rhs._database;
    return *this;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & obj)
{
    *this = obj;
}

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(std::string const & dbFile)
{
    std::ifstream file (dbFile);
    std::string line, date;
    double rate;

    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (std::getline(iss, date, ',') && iss >> rate) {
            _database[date] = rate;           
        } else 
            throw std::runtime_error("Error: could not process database file.");
    }
}

bool BitcoinExchange::isValidDate(std::string const & date)
{
    int year, month, day;
    std::istringstream iss(date);
    char str;

    if (!(iss >> year >> str >> month >> str >> day))
    {
        return false;
    }
        
    if (year <= 0 || month <= 0 || month > 12 || day <= 0) {
        return false;
    }

    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {        
        days[1] = 29;
    }    
    
    return day <= days[month - 1];;
}

bool BitcoinExchange::isValidValue(double value)
{
    return value >= 0 && value <= 1000;
}

std::string BitcoinExchange::findClosestDate(std::string const & date)
{
    auto it = _database.upper_bound(date);
    if (it != _database.begin()) {
        --it;
    }
    return it->first;
}

void BitcoinExchange::processInputFile(std::string const & inputFile)
{
        std::ifstream file(inputFile);
        std::string line, date;
        double value;

        if (!file.is_open()) {
            throw std::runtime_error("Error: could not open input file.");
        }

        std::getline(file, line);
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            if (std::getline(iss, date, '|') && iss >> value) {
                date = date.substr(0, date.find_last_not_of(" \t") + 1);
                
                if (!isValidDate(date)) {
                    std::cout << "Error: bad date => " << date << std::endl;
                } else if (!isValidValue(value)) {
                    std::cout << "Error: " << (value < 0 ? "not a positive number." : "too large a number.") << std::endl;
                } else {
                    std::string closestDate = findClosestDate(date);
                    double rate = _database[closestDate];
                    std::cout << date << " => " << value << " = " << value * rate << std::endl;
                }
            } else {
                std::cout << "Error: bad input => " << line << std::endl;
            }
        }
    }
    