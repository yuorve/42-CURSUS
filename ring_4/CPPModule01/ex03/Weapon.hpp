/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:42:26 by yoropeza          #+#    #+#             */
/*   Updated: 2024/05/25 20:07:57 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

# include <iostream>

class	Weapon
{
	private:
		std::string	_type;
        
	public:
		Weapon(std::string type);
		~Weapon(void);
		
		std::string& getType(void);
        void setType(std::string type);
};
#endif
