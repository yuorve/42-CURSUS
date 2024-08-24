/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 10:59:10 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/24 11:05:12 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer & Serializer::operator=(Serializer const & rhs) 
{ 
    (void) rhs;
    return *this;
}

Serializer::Serializer(Serializer const & obj)
{
    *this = obj;
}

Serializer::Serializer() { }

Serializer::~Serializer() { }

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
