/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:22:10 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/30 17:40:35 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("Default Form"), isSigned(false), gradeToSign(1), gradeToExecute(1) {
	isSigned = false;
	//std::cout << "Form Default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
	//std::cout << "Form Parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
		//std::cout << "Form copy constructor called" << std::endl;
	}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {        
        isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm() {
	//std::cout << "Form Destructor called" << std::endl;
}

std::string AForm::getName(void) const { 
	return name;
}

bool AForm::getIsSigned(void) const { 
	return isSigned;
}

int AForm::getGradeToSign(void) const { 
	return gradeToSign;
}

int AForm::getGradeToExecute(void) const { 
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "Form " << form.getName() << ": ";
    os << (form.getIsSigned() ? "signed" : "not signed");
    os << ", grade to sign: " << form.getGradeToSign();
    os << ", grade to execute: " << form.getGradeToExecute();
    return os;
}