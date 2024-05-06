/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:24:01 by yoropeza          #+#    #+#             */
/*   Updated: 2024/04/25 07:46:54 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.class.hpp"

int	main(void)
{
	std::string	command;
	PhoneBook	phonebook;

	std::cout << "My Awasome PhoneBook" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Available commands: ADD SEARCH EXIT" << std::endl;
	std::cout << std::endl;
	while (command.compare("EXIT") != 0)
	{
		std::cout << "_: ";
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
			phonebook.add();
		else if (command.compare("SEARCH") == 0)
			phonebook.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}		
	}
	return (0);
}