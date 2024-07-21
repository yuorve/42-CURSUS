/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:57:40 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/21 13:26:33 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    std::cout << "Creating Harl..." << std::endl;
}

Harl::~Harl()
{
    std::cout << "Destroying Harl..." << std::endl;
}

void    Harl::debug( void )
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info( void )
{
   std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error( void )
{
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain( std::string level )
{
    void		(Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++){

		if (levels[i].compare(level) == 0){
			(this->*ptr[i])();
			return ;
		}

	}
    
    std::cout << "Unknown level: " << level << std::endl;
}
