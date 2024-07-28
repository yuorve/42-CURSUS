/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:18:17 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/28 15:52:54 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
    	Brain *brain;
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog	&operator=(const Dog &other);
		~Dog(void);

		std::string	getType(void) const;
		void makeSound(void) const override;
};

#endif