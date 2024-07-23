/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:33:24 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/23 16:43:21 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const intValue): _number(intValue << _fbits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const floatValue): _number(roundf(floatValue * (1 << _fbits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_number = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_number = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_number) / (1 << this->_fbits);
}

int Fixed::toInt(void) const {
    return this->_number >> this->_fbits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->toFloat() < other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->toFloat() != other.toFloat();
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result = this->toFloat() + other.toFloat();
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result = this->toFloat() - other.toFloat();
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result = this->toFloat() * other.toFloat();
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result = this->toFloat() / other.toFloat();
    return result;
}

Fixed &Fixed::operator++()
{
    this->_number++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_number++;
    return temp;
}

Fixed &Fixed::operator--()
{
    this->_number--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_number--;
    return temp;
}

Fixed &Fixed::max(Fixed &valueA, Fixed &valueB)
{
	if (valueA > valueB)
    	return valueA;
	else
		return valueB;
}

const Fixed &Fixed::max(const Fixed &valueA, const Fixed &valueB)
{
    if (valueA > valueB) 
		return valueA;
	else
		return valueB;
}

Fixed &Fixed::min(Fixed &valueA, Fixed &valueB)
{
	if (valueA < valueB) 
		return valueA;
	else
		return valueB;
}

const Fixed &Fixed::min(const Fixed &valueA, const Fixed &valueB)
{
    if (valueA < valueB)
		return valueA;
	else
		return valueB;
}
