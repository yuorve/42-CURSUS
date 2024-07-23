/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:19:08 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/23 14:36:38 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class	Fixed
{
	private:
		int                 _number;
		static const int    _fbits = 8;
	public:
		Fixed( void );
		Fixed( const Fixed &other );
		Fixed &operator=( const Fixed &other );
		~Fixed( void );
		int		getRawBits( void ) const;
		void 	setRawBits( int const raw );
};

#endif
