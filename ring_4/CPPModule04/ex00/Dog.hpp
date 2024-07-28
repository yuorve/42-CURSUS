/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:18:17 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/28 14:56:40 by yoropeza         ###   ########.fr       */
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
		void makeSound(void) const override;
};

#endif