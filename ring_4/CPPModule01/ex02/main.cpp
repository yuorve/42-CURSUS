/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:03:56 by yoropeza          #+#    #+#             */
/*   Updated: 2024/05/16 17:33:27 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string	str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
       
    std::cout << "ADDRESS STR: " << &str << std::endl;
    std::cout << "ADDRESS PTR: " << &stringPTR << std::endl;
    std::cout << "ADDRESS REF: " << &stringREF << std::endl;
    std::cout << "VALUE STR: " << str << std::endl;
    std::cout << "VALUE PTR: " << stringPTR << std::endl;
    std::cout << "VALUE REF: " << stringREF << std::endl;    
}
