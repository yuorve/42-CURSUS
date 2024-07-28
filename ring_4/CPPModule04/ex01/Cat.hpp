/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:18:17 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/28 11:15:16 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include "Animal.hpp"

class Cat : public Animal {
	protected:
		std::string	type;
	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat &other);
		Cat	&operator=(const Cat &other);
		~Cat(void);

		std::string	getType(void) const;
		virtual	void makeSound(void) const;
};

#endif