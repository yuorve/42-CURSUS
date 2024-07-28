/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:37:12 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/28 15:53:19 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &other) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog(void) {
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other) {
	this->type = other.type;
	this->brain = new Brain(*other.brain);
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Woof" << std::endl;
}

std::string	Dog::getType(void) const {
	return this->type;
}
