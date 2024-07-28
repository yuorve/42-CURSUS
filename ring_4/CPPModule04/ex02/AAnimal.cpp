/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:37:12 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/28 14:46:34 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

Animal::Animal(void) {
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(std::string type) {
	std::cout << "Animal parametized constructor called" << std::endl;
	this->type = type;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = other.type;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &other) {
	this->type = other.type;
	return *this;
}

void	Animal::makeSound(void) const {
	std::cout << "Animal sound" << std::endl;
}

std::string	Animal::getType(void) const {
	return this->type;
}
