/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:04:07 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/30 17:41:21 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), target("Default"){
	//std::cout << "Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target){
	//std::cout << "Parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target){
	//std::cout << "Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	//std::cout << "Destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	if(!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else if(executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

		std::cout << executor.getName() << " executing " << this->getName() << std::endl;
		std::cout << "Rrrrrrrrrrrrr..." << std::endl;
		std::cout << "Vrrrrrrrrrrrrr..." << std::endl;
		std::cout << "Brrrrrrrrrrrrr..." << std::endl;
		std::cout << "Drrrrrrrrrrrrr..." << std::endl;
		std::cout << "Trrrrrrrrrrrrr..." << std::endl;
		std::cout << "Zzzzzzzzzzzzzzzz..." << std::endl;
		std::cout << "Grrrrrrrrrrrrr..." << std::endl;
		
		std::srand(std::time(0));
		
		int result = rand() % 2;
		if (result == 0)
			std::cout << this->target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Robotomy failed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		(void)other;
	}
	return *this;
}
