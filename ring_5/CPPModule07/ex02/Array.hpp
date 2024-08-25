/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 07:02:00 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/25 07:36:40 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T>
class Array
{
    private :
        unsigned int _size;
        T * _array;

    public :
        Array() : _array(nullptr), _size(0) { }
        Array(unsigned int n) : _array(new T[n]()), _size(n) { }
        Array(Array const &obj) : _array(new T[obj._size]), _size(obj._size)
        {
            for (unsigned int i = 0; i < _size; ++i)
                _array[i] = obj._array[i];
        }
        Array &operator=(Array const &rhs)
        {
            if (this != &rhs)
            {
                delete[] _array;
                _size = rhs._size;
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; ++i)
                    _array[i] = rhs._array[i];
            }
            return *this;
        }
        ~Array()
        {
            delete[] _array;
        }
        T &operator[](unsigned int index)
        {
            if (index >= _size)
                throw OutOfBoundsException();
            return _array[index];
        };
        unsigned int size() const
        {
            return _size;
        }
        
    class	OutOfBoundsException : public std::exception {
		virtual const char* what() const throw() { return "Out of Bounds"; };
	};
        
};

#endif