/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:55:54 by yoropeza          #+#    #+#             */
/*   Updated: 2024/05/25 20:10:27 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
    std::cout << "Creating Weapon " << type << std::endl;
}

Weapon::~Weapon(void)
{
    std::cout << "Destroying Weapon " << _type << std::endl;
}

std::string& Weapon::getType( void )
{
    return (this->_type);
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}
