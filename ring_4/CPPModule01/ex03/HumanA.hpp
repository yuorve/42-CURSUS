/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:12:06 by yoropeza          #+#    #+#             */
/*   Updated: 2024/05/25 20:15:32 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

# include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	_name;
        Weapon      &_weapon;
        
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
				
        void setWeapon(Weapon weapon);
        void attack(void);
};
#endif
