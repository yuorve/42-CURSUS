/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:43:52 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/30 18:12:59 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	Intern someRandomIntern;
    AForm *rrf;
    AForm *scf;
    AForm *ppf;
    AForm *unknown;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "home");
    ppf = someRandomIntern.makeForm("presidential pardon", "Stephen Bannon");
    unknown = someRandomIntern.makeForm("unknown form", "nobody");

    if (rrf) delete rrf;
    if (scf) delete scf;
    if (ppf) delete ppf;
    if (unknown) delete unknown;
	return (0);
}