/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 07:58:44 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/25 08:25:57 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<int> lst = {10, 20, 30, 40, 50};
    std::deque<int> deq = {22, 3, 42, 123, 1};
    try
    {
        std::cout << "Finding 3 in vector: " << *easyfind(vec, 3) << std::endl;
        std::cout << "Finding 30 in list: " << *easyfind(lst, 30) << std::endl;
        std::cout << "Finding 42 in queue: " << *easyfind(deq, 42) << std::endl;
        std::cout << "Finding 100 in vector: " << *easyfind(vec, 100) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
