/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:11:55 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/24 11:44:20 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
    public :
        virtual ~Base() { };
        static Base* generate(void);
        static void identify(Base* p);
        static void identify(Base& p);

};

class A : public Base { };
class B : public Base { };
class C : public Base { };

#endif