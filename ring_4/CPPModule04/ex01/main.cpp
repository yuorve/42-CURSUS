/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:06:40 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/28 14:31:15 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
	const Animal 	*j = new Dog();
	const Animal 	*i = new Cat();
	
	delete j;//should not create a leak
	delete i;
	
	const Animal	*animals[10];

	for (int i=0; i < 5; i++) {
		animals[i] = new Dog();
	}
	
	for (int i=5; i < 10; i++) {
		animals[i] = new Cat();
	}
	
	for (int i=0; i < 10; i++) {
		delete animals[i];
	}
	
	return (0);
}
