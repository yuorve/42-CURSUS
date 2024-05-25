/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:16:03 by yoropeza          #+#    #+#             */
/*   Updated: 2024/05/25 20:38:54 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
    std::cout << "Creating HumanB " << this->_name << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "Destroying HumanB " << this->_name << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack(void)
{
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
