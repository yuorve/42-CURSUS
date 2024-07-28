/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:37:12 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/28 15:56:37 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat(const Cat &other) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat(void) {
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other) {
	this->type = other.type;
	this->brain = new Brain(*other.brain);
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}

std::string	Cat::getType(void) const {
	return this->type;
}
