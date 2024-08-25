/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:05:07 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/25 16:20:28 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define	RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

class	RPN
{
    private :
        std::stack<int> _numbers;
        RPN & operator=(RPN const & rhs);
        RPN(RPN const & obj);
        
    public :        
        RPN();
        ~RPN();
        int evaluate(std::string const & expression);

    
};

#endif
