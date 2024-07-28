/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:18:17 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/28 11:15:21 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	protected:
		std::string	type;
	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog &other);
		Dog	&operator=(const Dog &other);
		~Dog(void);

		std::string	getType(void) const;
		virtual void makeSound(void) const;
};

#endif