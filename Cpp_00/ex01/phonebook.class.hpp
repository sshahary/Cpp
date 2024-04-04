/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:07:27 by sshahary          #+#    #+#             */
/*   Updated: 2024/04/04 10:49:18 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <limits>
#include "contact.class.hpp"

class PhoneBook {
private:
	std::vector<Contact> contacts;

public:
	void addContact(const Contact& contact) {
		contacts.push_back(contact);
	}

	void displayContacts() const {
		std::cout << "Phone Book:" << std::endl;
		for (size_t i = 0; i < contacts.size(); ++i) {
			std::cout << "|" << std::setw(10) << std::right << i
					  << "|" << std::setw(10) << std::right << truncateString(contacts[i].getFirstName())
					  << "|" << std::setw(10) << std::right << truncateString(contacts[i].getLastName())
					  << "|" << std::setw(10) << std::right << truncateString(contacts[i].getNickname())
					  << "|" << std::endl;
		}
	}

	void displayContactDetails(size_t index) const {
		if (index < contacts.size()) {
			const Contact& contact = contacts[index];
			std::cout << "First Name: " << contact.getFirstName() << std::endl;
			std::cout << "Last Name: " << contact.getLastName() << std::endl;
			std::cout << "Nickname: " << contact.getNickname() << std::endl;
			std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
		} else {
			std::cout << "Error: Index out of range." << std::endl;
		}
	}

private:
	std::string truncateString(const std::string& str, size_t length = 10) const {
		if (str.length() <= length) {
			return str;
		} else {
			return str.substr(0, length - 1) + ".";
		}
	}
};


#endif