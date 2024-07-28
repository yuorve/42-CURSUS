/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:18:17 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/28 11:15:27 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongCat(void);
		WrongCat(std::string type);
		WrongCat(const WrongCat &other);
		WrongCat	&operator=(const WrongCat &other);
		~WrongCat(void);

		std::string	getType(void) const;
		virtual	void makeSound(void) const;
};

#endif