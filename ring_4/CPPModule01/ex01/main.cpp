/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:25:27 by yoropeza          #+#    #+#             */
/*   Updated: 2024/05/25 18:14:15 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void){
	
	Zombie*	horde = zombieHorde(10, "Carl");

	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete	[]	horde;
	return (0);	
}
