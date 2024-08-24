/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:19:15 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/24 11:42:38 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* Base::generate(void) {
    srand(static_cast<unsigned int>(time(0)));
    int randomValue = rand() % 3;

    switch (randomValue) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return nullptr;
    }
}

void Base::identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "class A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "class B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "class C" << std::endl;
    } else {
        std::cout << "Unknown Type" << std::endl;
    }
}

void Base::identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "class A" << std::endl;
    } catch (std::bad_cast& e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "class B" << std::endl;
    } catch (std::bad_cast& e) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "class C" << std::endl;
    } catch (std::bad_cast& e) {}
}
