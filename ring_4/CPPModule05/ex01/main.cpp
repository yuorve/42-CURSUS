/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:43:52 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/29 19:04:36 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat 	b1("Pascuale", 1);
		Form		f1("42A", 42, 1);
		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		std::cout << std::endl;
		
		Bureaucrat 	b2("Tubercio", 150);
		Form		f2("RH01", 100, 1);
		std::cout << b2 << std::endl;
		std::cout << f2 << std::endl;
		b2.signForm(f2);
		std::cout << f2 << std::endl;
		std::cout << std::endl;		
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}