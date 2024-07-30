/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:28:02 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/30 17:38:13 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	
	private:
		const std::string name;
    	int grade;
		
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);		
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		std::string getName(void) const;
    	int getGrade(void) const;

		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(AForm &form);
		void executeForm(AForm const &form);

		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Grade too high";
			}
		};

		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Grade too low";
			}
		};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif