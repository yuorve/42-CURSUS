/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:44:01 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/25 11:21:30 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    public :
        typedef typename std::stack<T>::container_type::iterator iterator;
        
        MutantStack() : std::stack<T>() { }
        MutantStack(MutantStack<T> const & obj) : std::stack<T>(obj) { }
        ~MutantStack() { }
        MutantStack<T>& operator=(MutantStack<T> const & rhs)
        {
            if (this != &rhs)
                std::stack<T>::operator=(rhs);
            return *this;
        }

        iterator begin() 
        { 
            return this->c.begin();
        }
        
        iterator end()
        {
            return this->c.end();
        }       
};

#endif