/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:47:25 by yoropeza          #+#    #+#             */
/*   Updated: 2024/09/02 10:18:05 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::mergeInsertionSortVector(std::vector<int>& arr) {
    if (arr.size() > 1) {
        mergeInsertionSortVectorHelper(arr, 0, arr.size() - 1);
    }
}

void PmergeMe::mergeInsertionSortVectorHelper(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursivamente ordenamos ambas mitades
        mergeInsertionSortVectorHelper(arr, left, mid);
        mergeInsertionSortVectorHelper(arr, mid + 1, right);

        // Combinamos las mitades ordenadas
        mergeVector(arr, left, mid, right);
    }
}

void PmergeMe::mergeVector(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeInsertionSortList(std::list<int>& lst) {
    if (lst.size() > 1) {
        mergeInsertionSortListHelper(lst);
    }
}

void PmergeMe::mergeInsertionSortListHelper(std::list<int>& lst) {
    if (lst.size() > 1) {
        std::list<int> left, right;
        auto it = lst.begin();
        std::advance(it, lst.size() / 2);
        left.splice(left.begin(), lst, lst.begin(), it);
        right.splice(right.begin(), lst);

        mergeInsertionSortListHelper(left);
        mergeInsertionSortListHelper(right);

        mergeList(lst, left, right);
    }
}

void PmergeMe::mergeList(std::list<int>& lst, std::list<int>& left, std::list<int>& right) {
    auto itLeft = left.begin();
    auto itRight = right.begin();

    while (itLeft != left.end() && itRight != right.end()) {
        if (*itLeft <= *itRight) {
            lst.push_back(*itLeft);
            itLeft++;
        } else {
            lst.push_back(*itRight);
            itRight++;
        }
    }

    lst.splice(lst.end(), left, itLeft, left.end());
    lst.splice(lst.end(), right, itRight, right.end());
}
