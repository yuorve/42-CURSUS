/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:35:33 by yoropeza          #+#    #+#             */
/*   Updated: 2024/04/24 18:14:58 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

std::string	Contact::get(std::string field){
    if (field == "firstname"){
        return (this->_firstname);
    }
    else if (field == "lastname"){
        return (this->_lastname);
    }
    else if (field == "nickname"){
        return (this->_nickname);
    }
    else if (field == "phonenumber"){
        return (this->_phonenumber);
    }
    else if (field == "secret"){
        return (this->_secret);
    }
    return (0);
}

void		Contact::set(std::string field, std::string str){
    if (field == "firstname"){        
        this->_firstname.assign(str);
    }
    else if (field == "lastname"){        
        this->_lastname.assign(str);
    }
    else if (field == "nickname"){        
        this->_nickname.assign(str);
    }
    else if (field == "phonenumber"){        
        this->_phonenumber.assign(str);
    }
    else if (field == "secret"){        
        this->_secret.assign(str);
    }
}
