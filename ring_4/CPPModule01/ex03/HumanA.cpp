/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:16:03 by yoropeza          #+#    #+#             */
/*   Updated: 2024/05/25 20:21:50 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
    std::cout << "Creating HumanA " << this->_name << " with weapon " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "Destroying HumanA " << this->_name << std::endl;
}

void HumanA::setWeapon(Weapon weapon)
{
    this->_weapon = weapon;
}

void HumanA::attack(void)
{
        std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
