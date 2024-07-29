/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:16:23 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/29 19:05:07 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		Form(void);		
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form(void);

		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade too high";
			}
		};

		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade too low";
			}
		};
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif