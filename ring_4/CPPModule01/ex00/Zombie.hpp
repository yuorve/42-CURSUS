/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:52:42 by yoropeza          #+#    #+#             */
/*   Updated: 2024/05/06 17:51:04 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <iostream>
# include <iomanip>

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		
		void announce( void );
		
	private:
		std::string	_name;
};
#endif
