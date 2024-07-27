/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:22:42 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/27 16:32:24 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap clap1;
    ClapTrap clap2("CL4P-TP");
    
    clap1.attack("Zombie");
    clap1.takeDamage(3);
    clap2.attack("MegaZombie");
    clap2.takeDamage(5);
    clap1.beRepaired(3);
    
    return 0;
}
