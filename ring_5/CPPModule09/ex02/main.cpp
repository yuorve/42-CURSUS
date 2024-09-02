/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:31:06 by yoropeza          #+#    #+#             */
/*   Updated: 2024/09/02 10:33:39 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <positive integer sequence>" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec.push_back(num);
        lst.push_back(num);
    }

    std::cout << "Before: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Medir el tiempo de ordenamiento usando std::vector
    auto start = std::chrono::high_resolution_clock::now();
    PmergeMe::mergeInsertionSortVector(vec);
    auto end = std::chrono::high_resolution_clock::now();
    auto vectorTime = std::chrono::duration<double, std::micro>(end - start).count();

    std::cout << "After: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: "
              << std::fixed << std::setprecision(5) << vectorTime << " us" << std::endl;

    // Medir el tiempo de ordenamiento usando std::list
    start = std::chrono::high_resolution_clock::now();
    PmergeMe::mergeInsertionSortList(lst);
    end = std::chrono::high_resolution_clock::now();
    auto listTime = std::chrono::duration<double, std::micro>(end - start).count();

    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: "
              << std::fixed << std::setprecision(5) << listTime << " us" << std::endl;

    return 0;
}
