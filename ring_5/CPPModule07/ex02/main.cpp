/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 07:17:56 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/25 07:18:25 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        // Test constructor por defecto
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        // Test constructor con tamaño
        Array<int> intArray(5);
        std::cout << "Int array size: " << intArray.size() << std::endl;

        // Test operador []
        for (unsigned int i = 0; i < intArray.size(); ++i)
            intArray[i] = i * 2;

        // Test constructor de copia
        Array<int> copiedArray = intArray;

        std::cout << "Original array: ";
        for (unsigned int i = 0; i < intArray.size(); ++i)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;

        std::cout << "Copied array: ";
        for (unsigned int i = 0; i < copiedArray.size(); ++i)
            std::cout << copiedArray[i] << " ";
        std::cout << std::endl;

        // Test excepción
        std::cout << "Attempting to access out of bounds index..." << std::endl;
        std::cout << intArray[10] << std::endl; // Esto debería lanzar una excepción
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
