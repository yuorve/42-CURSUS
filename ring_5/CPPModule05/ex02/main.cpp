/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:43:52 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/30 17:18:26 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	try {
		Bureaucrat 				b1("Pascuale", 100);
		ShrubberyCreationForm	f1("42A");
		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;
		b1.executeForm(f1);
		b1.signForm(f1);
		b1.executeForm(f1);
		std::cout << std::endl;
		
		Bureaucrat 				b2("Tubercio", 40);
		RobotomyRequestForm		f2("RH01");
		std::cout << b2 << std::endl;
		std::cout << f2 << std::endl;
		b2.signForm(f2);
		b2.executeForm(f2);
		std::cout << std::endl;

		Bureaucrat 				b3("Edmundo", 1);
		PresidentialPardonForm	f3("28C");
		std::cout << b3 << std::endl;
		std::cout << f3 << std::endl;
		b3.signForm(f3);
		b3.executeForm(f3);
		std::cout << std::endl;

		b2.signForm(f3);
		b1.executeForm(f3);		
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}