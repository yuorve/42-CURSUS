/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:12:06 by yoropeza          #+#    #+#             */
/*   Updated: 2024/05/25 20:27:12 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

# include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	_name;
        Weapon      *_weapon;
        
	public:
		HumanB(std::string name);
		~HumanB(void);
				
        void setWeapon(Weapon &weapon);
        void attack(void);
};
#endif
