/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:50:20 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/25 13:04:24 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

class BitcoinExchange
{
    private :
        std::map<std::string, double> _database;
        BitcoinExchange & operator=(BitcoinExchange const & rhs);
        BitcoinExchange(BitcoinExchange const & obj);
        BitcoinExchange();
        bool isValidDate(std::string const & date);
        bool isValidValue(double value);
        std::string findClosestDate(std::string const & date);
        
    public : 
        ~BitcoinExchange();
        BitcoinExchange(std::string const & dbFile);
        void processInputFile(std::string const & inputFile);
};

#endif