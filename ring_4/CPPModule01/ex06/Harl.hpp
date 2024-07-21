/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:48:26 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/21 12:56:16 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CLASS_HPP
# define HARL_CLASS_HPP

# include <iostream>

class	Harl
{
    private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		Harl( void );
		~Harl( void );
		void complain( std::string level );
};
#endif
