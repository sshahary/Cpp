/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:31:37 by sshahary          #+#    #+#             */
/*   Updated: 2024/06/07 20:55:43 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : numContacts(0) {}
PhoneBook::~PhoneBook() {}

std::string PhoneBook::truncateString(const std::string& str, size_t width) const {
    if (str.length() > width) {
        return str.substr(0, width - 3) + "...";
    }
    return str;
}

void PhoneBook::displayContacts() const {
    std::cout << "Phone Book:" << std::endl;
    std::cout << "| Index | First Name | Last Name | Nickname  |" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < numContacts; ++i) {
        std::cout << "|" << std::setw(6) << i
                  << "|" << std::setw(11) << truncateString(contacts[i].getFirstName())
                  << "|" << std::setw(10) << truncateString(contacts[i].getLastName())
                  << "|" << std::setw(10) << truncateString(contacts[i].getNickname())
                  << "|" << std::endl;
    }
}

void PhoneBook::displayContactDetails(int index) const {
    if (index >= 0 && index < numContacts) {
        const Contact &contact = contacts[index];
        std::cout << "First Name: " << contact.getFirstName() << std::endl;
        std::cout << "Last Name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
    } else {
        std::cout << "Error: Invalid index." << std::endl;
    }
}

std::string promptUserForInput(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt << ": ";
        std::getline(std::cin, input);
        if (!input.empty())
            break;
        std::cout << "Invalid input. Please try again." << std::endl;
    }
    return input;
}


void PhoneBook::addContact() {
    std::string firstName = promptUserForInput("Enter first name");
    std::string lastName = promptUserForInput("Enter last name");
    std::string nickname = promptUserForInput("Enter nickname");
    std::string phoneNumber = promptUserForInput("Enter phone number");
    std::string darkestSecret = promptUserForInput("Enter darkest secret");

    if (numContacts >= 8) {
        for (int index = 1; index < numContacts; index++) {
            contacts[index - 1] = contacts[index];
        }
        numContacts = 7;  // Adjust to maintain 8 contacts.
    }
    contacts[numContacts].set_contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    if (numContacts < 8) {
        numContacts++;
    }
}
