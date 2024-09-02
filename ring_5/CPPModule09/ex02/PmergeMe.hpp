/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:42:48 by yoropeza          #+#    #+#             */
/*   Updated: 2024/09/02 10:24:36 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <string>


class PmergeMe {
public:
    static void mergeInsertionSortVector(std::vector<int>& arr);
    static void mergeInsertionSortList(std::list<int>& lst);

private:
    static void mergeInsertionSortVectorHelper(std::vector<int>& arr, int left, int right);
    static void mergeVector(std::vector<int>& arr, int left, int mid, int right);
    
    static void mergeInsertionSortListHelper(std::list<int>& lst);
    static void mergeList(std::list<int>& lst, std::list<int>& left, std::list<int>& right);
};

#endif
