/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:43:52 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/29 17:59:01 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat b0;  // Usando el constructor por defecto
		std::cout << "Default bureaucrat: " << b0 << std::endl;

		Bureaucrat b1("Pascuale", 1);
		std::cout << b1 << std::endl;
		
		Bureaucrat b2("Tubercio", 150);
		std::cout << b2 << std::endl;
		
		std::cout << "Decreasing grade by one..." << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		
		std::cout << "Increasing grade by one..." << std::endl;
		b2.incrementGrade();
		std::cout << b2 << std::endl;

		Bureaucrat b3("Invalid", 0);  // Should throw exception
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}