/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:15:03 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/30 17:17:31 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), target("Default"){
	//std::cout << "Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5), target(target){
	//std::cout << "Parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Form(other), target(other.target){
	//std::cout << "Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	//std::cout << "Destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	if(!this->getIsSigned())
		throw Form::FormNotSignedException();
	else if(executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();

	std::cout << executor.getName() << " executing " << this->getName() << std::endl;
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		(void)other;
	}
	return *this;
}
