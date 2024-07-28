/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:37:12 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/28 14:51:47 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(std::string type) {
	std::cout << "Cat parametized constructor called" << std::endl;
	this->type = type;
}

Cat::Cat(const Cat &other) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other) {
	this->type = other.type;
	return *this;
}

void Cat::makeSound(void) const override {
	std::cout << "Meow" << std::endl;
}

std::string	Cat::getType(void) const {
	return this->type;
}
