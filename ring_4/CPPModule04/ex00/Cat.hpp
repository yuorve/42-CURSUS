/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:18:17 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/28 14:50:05 by yoropeza         ###   ########.fr       */
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
		void makeSound() const override;
};

#endif