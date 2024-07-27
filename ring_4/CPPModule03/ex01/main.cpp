/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:22:42 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/27 16:58:53 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    std::cout << "Creating ClapTrap:" << std::endl;
    ClapTrap clap("CL4P-TP");
    
    std::cout << "\nCreating ScavTrap:" << std::endl;
    ScavTrap scav("SC4V-TP");
    
    std::cout << "\nTesting ClapTrap:" << std::endl;
    clap.attack("Bandit");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    std::cout << "\nTesting ScavTrap:" << std::endl;
    scav.attack("Psycho");
    scav.takeDamage(15);
    scav.beRepaired(10);
    scav.guardGate();
    
    std::cout << "\nDestroying objects:" << std::endl;
    
    return 0;
}
