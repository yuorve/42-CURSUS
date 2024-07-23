/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:19:08 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/23 16:21:31 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int                 _number;
		static const int    _fbits = 8;
	public:
		Fixed( void );
		Fixed( int const intValue);
		Fixed( float const floatValue);
		Fixed( const Fixed &other );
		Fixed &operator=( const Fixed &other );
		~Fixed( void );

		int		getRawBits( void ) const;
		void 	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
		
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static Fixed &min(Fixed &valueA, Fixed &valueB);
		static Fixed const &min(Fixed const &valueA, Fixed const &valueB);
		static Fixed &max(Fixed &valueA, Fixed &valueB);
		static Fixed const &max(Fixed const &valueA, Fixed const &valueB);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
