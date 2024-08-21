/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:43:47 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/30 18:10:21 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}
Intern::Intern(const Intern &other) { *this = other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
Intern::~Intern(void) {}

AForm *Intern::makeForm(const std::string formName, const std::string target) {
	std::string	forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int	i = 0;

	while (i < 3 && forms[i].compare(formName))
		i++;
	
	switch (i) {
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(target);
		default:
			std::cout << "Intern cannot create form: " << formName << " (unknown form type)" << std::endl;
			return (nullptr);
	}
}
