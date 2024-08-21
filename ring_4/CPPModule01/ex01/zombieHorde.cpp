/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:24:23 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/07 17:32:04 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){

	if (N > 0) {
		Zombie	*horde = new Zombie[N];

		for (int i = 0; i < N; i++)
			horde[i].set_name(name);
		
		return (horde);
	} else
		return NULL;
}
