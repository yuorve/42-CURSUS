/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:10:28 by yoropeza          #+#    #+#             */
/*   Updated: 2024/08/25 16:24:00 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN	& RPN::operator=(RPN const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

RPN::RPN(RPN const & src) {
	*this = src;
}

RPN::RPN() { }

RPN::~RPN() { }

bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

int performOperation(int a, int b, const std::string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw std::runtime_error("Error: Division by zero");
        return a / b;
    }
    throw std::runtime_error("Error: Unknown operator");
}

int RPN::evaluate(std::string const & expression)
{
    std::istringstream iss(expression);
    std::string token;

    if (expression.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::runtime_error("Error");
    while (iss >> token) {
        if (isOperator(token)) {
            if (_numbers.size() < 2) {
                throw std::runtime_error("Error: Insufficient operands");
            }
            int b = _numbers.top(); _numbers.pop();
            int a = _numbers.top(); _numbers.pop();
            _numbers.push(performOperation(a, b, token));
        } else {
            try {
                int num = std::stoi(token);
                if (num < 0 || num > 9) {
                    throw std::runtime_error("Error: Number out of range (0-9)");
                }
                _numbers.push(num);
            } catch (const std::invalid_argument&) {
                throw std::runtime_error("Error: Invalid token - " + token);
            }
        }
    }

    if (_numbers.size() != 1) {
        throw std::runtime_error("Error: Too many operands");
    }

    return _numbers.top();
}
