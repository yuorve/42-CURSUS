/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:37:12 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/28 15:45:23 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other) {
	this->type = other.type;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Woof" << std::endl;
}

std::string	Dog::getType(void) const {
	return this->type;
}
