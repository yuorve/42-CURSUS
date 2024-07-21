/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:13:08 by yoropeza          #+#    #+#             */
/*   Updated: 2024/07/21 12:15:59 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv){
	if (argc != 4) {
		std::cout << "Arguments: <filename> <string1> <string2>" << std::endl;
		return (1);
	}

	std::ifstream 	ifs (std::string(argv[1]).c_str());
	std::string		content;
	size_t			pos;	

	if (ifs.is_open()) {
		if (!std::getcontent(ifs, content, '\0')) {
			ifs.close();
			std::cout << "Error reading file." << std::endl;
			return (1);
		}
		else {
			std::ofstream	ofs((std::string(argv[1]) + ".replace").c_str());
			pos = content.find(std::string(argv[2]).c_str());			
			while (pos != std::string::npos) {
				content.erase(pos, std::string(argv[2]).size());
				content.insert(pos, std::string(argv[3]).c_str());
				pos = content.find(std::string(argv[2]).c_str(), pos + std::string(argv[2]).size());
			}			
			ofs << content;
			ofs.close();
		}
		ifs.close();
	}
	else {
		std::cout << "Error opening file." << std::endl;
	}
	
	return (0);
}
