/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:56:42 by yoropeza          #+#    #+#             */
/*   Updated: 2024/04/25 08:20:24 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(){
	this->_index = 0;
	std::cout << "The PhoneBook has been created!\n" << std::endl;
}

PhoneBook::~PhoneBook(){	
	std::cout << "The PhoneBook has been deleted and the contacts are lost forever!\n" << std::endl;
}

std::string	get_value(std::string label)
{
	std::string	str;
	
	while (!std::cin.eof() && str == ""){
		std::cout << label;
		std::getline(std::cin, str);
	}
	return (str);
}

void	PhoneBook::add(void){
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phonenumber;
	std::string	secret;
	
	std::cout << "Add contact " << (this->_index % 8) + 1 << "\n" << std::endl;
	if (this->_index >= 8)
	{
		std::cout << "Overwriting contact ";
		std::cout << this->_contacts[this->_index % 8].get("firstname") << std::endl;
	}
	
	this->_contacts[this->_index % 8].set("firstname", get_value("First name: "));
	this->_contacts[this->_index % 8].set("lastname", get_value("Last name: "));
	this->_contacts[this->_index % 8].set("nickname", get_value("Nick name: "));
	this->_contacts[this->_index % 8].set("phonenumber", get_value("Phone number: "));
	this->_contacts[this->_index % 8].set("secret", get_value("Darkest secret: "));
	this->_index++;
	std::cout << std::endl;
}

void	PhoneBook::search(void){
	std::string query;

	std::cout << "Search contact\n" << std::endl;
	if (this->_contacts[0].get("firstname").length() == 0)
		std::cout << "You have no contacts" << std::endl;
	else {
		this->show();
		while (!std::cin.eof()){
			std::cout << "Contact's index: ";
			std::getline(std::cin, query);
			if (query.length() == 1 && (query[0] >= '1' && query[0] <= '8')){
				this->print(this->_contacts[(query[0] - 1) - '0']);
				break ;
			}
			else
				std::cout << "Invalid index!" << std::endl;
		}
	}
}

void	PhoneBook::print(Contact contact){
	if (!contact.get("firstname").length()){
		std::cout << "Query for this contact has been failed" << std::endl;
		return ;
	}
	std::cout << "First name: " << contact.get("firstname") << std::endl;
	std::cout << "Last name: " << contact.get("lastname") << std::endl;
	std::cout << "Nick name: " << contact.get("nickname") << std::endl;
	std::cout << "Phone number: " << contact.get("phonenumber") << std::endl;
	std::cout << "Darkest Secret: " << contact.get("secret") << std::endl;
	std::cout << std::endl;
}

std::string	format(std::string data){

	std::string str;
	int			len;

	len = data.length();
	if (len > 10) {
		str.assign(data, 0, 9);
		str += '.';
		return (str);
	}
	else
		return (data);
}

void	PhoneBook::show(void){
	for (int index = 0; index < 8; index++){
		if (this->_contacts[index].get("firstname").length() != 0){
			std::cout << std::setw(10) << index + 1 << "|";
			std::cout << std::setw(10) << format(this->_contacts[index].get("firstname")) << "|";
			std::cout << std::setw(10) << format(this->_contacts[index].get("lastname")) << "|";
			std::cout << std::setw(10) << format(this->_contacts[index].get("nickname")) << "|";
			std::cout << std::endl;
		}
	}
	if (this->_index >= 8)
		std::cout << "Total records: 8" << std::endl;
	else
		std::cout << "Total records: " << this->_index % 8 << std::endl;
	std::cout << std::endl;
}
