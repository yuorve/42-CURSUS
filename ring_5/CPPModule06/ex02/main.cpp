/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:22:58 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/24 11:38:07 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
    Base* basePtr = Base::generate();
    
    std::cout << "Identifying by pointer: ";
    Base::identify(basePtr);
    
    std::cout << "Identifying by reference: ";
    Base::identify(*basePtr);

    delete basePtr;

    return 0;
}
