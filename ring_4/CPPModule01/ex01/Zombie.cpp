/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:55:54 by yoropeza          #+#    #+#             */
/*   Updated: 2024/04/25 17:24:24 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string str){
	this->_name.assign(str);
}

Zombie::~Zombie(void){
	std::cout << this->_name << " has been destroyed" <<std::endl;
}

void Zombie::announce( void ){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
