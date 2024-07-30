/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:34:07 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/30 17:41:08 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), target("Default"){
	//std::cout << "Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target){
	//std::cout << "Parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target){
	//std::cout << "Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	//std::cout << "Destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	if(!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else if(executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

		std::cout << executor.getName() << " executing " << this->getName() << std::endl;
		
		std::ofstream	file(this->target + "_shrubbery");
		
		file << "         ccee88oo" << std::endl;
		file << "   C8O8O8Q8PoOb o8oo" << std::endl;
		file << " dOB69QO8PdUOpugoO9bD" << std::endl;
		file << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
		file << "    6OuU  /p u gcoUodpP" << std::endl;
		file << "      \\||/  /douUP" << std::endl;
		file << "        \\||///" << std::endl;
		file << "         |||||" << std::endl;
		file << "         |||||" << std::endl;
		file << "         |||||" << std::endl;
		file << "   ...../|||||....." << std::endl;

		file.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		(void)other;
	}
	return *this;
}
