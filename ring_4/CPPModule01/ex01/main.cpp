/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:25:27 by yoropeza          #+#    #+#             */
/*   Updated: 2024/05/06 17:33:40 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void){
	
	Zombie*	zombie = zombieHorde(10, "Carl");

	zombie->announce();
	delete	zombie;
	return (0);

}
