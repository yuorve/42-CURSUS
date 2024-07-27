/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:22:42 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/27 17:46:07 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    std::cout << "Creating ClapTrap:" << std::endl;
    ClapTrap clap("CL4P-TP");
    
    std::cout << "\nCreating ScavTrap:" << std::endl;
    ScavTrap scav("SC4V-TP");
    
    std::cout << "\nCreating FragTrap:" << std::endl;
    FragTrap frag("FR4V-TP");
    
    std::cout << "\nTesting ClapTrap:" << std::endl;
    clap.attack("Bandit");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    std::cout << "\nTesting ScavTrap:" << std::endl;
    scav.attack("Psycho");
    scav.takeDamage(15);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\nTesting FragTrap:" << std::endl;
    frag.attack("Murder");
    frag.takeDamage(25);
    frag.beRepaired(20);
    frag.highFivesGuys();
    
    std::cout << "\nDestroying objects:" << std::endl;
    
    return 0;
}
