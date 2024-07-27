/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:17:17 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/27 16:18:29 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } else {
        std::cout << "ClapTrap " << _name << " can't attack. Not enough energy or hit points!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= amount) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damage and is destroyed!" << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damage! " << _hitPoints << " hit points remaining." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points! Now has " << _hitPoints << " hit points." << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " can't repair. Not enough energy or hit points!" << std::endl;
    }
}
