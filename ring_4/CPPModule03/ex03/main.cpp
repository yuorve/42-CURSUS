/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:22:42 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/27 19:04:38 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {   
    std::cout << "\nCreating DiamondTrap" << std::endl;
    DiamondTrap diamond("DT4V-TP");
       
    std::cout << "\nTesting DiamondTrap:" << std::endl;
    diamond.attack("Zombie");
    diamond.takeDamage(50);
    diamond.beRepaired(10);
    diamond.whoAmI();

    std::cout << "\nDestroying objects:" << std::endl;
    
    return 0;
}
