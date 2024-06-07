/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:41:50 by sshahary          #+#    #+#             */
/*   Updated: 2024/06/07 20:33:21 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"
#include "contact.class.hpp"


std::string PhoneBook::truncateString(const std::string& str, size_t width) const {
        if (str.length() > width) {
            return str.substr(0, width - 3) + "...";
        }
        return str;
    }

void PhoneBook::displayContacts() const {
        std::cout << "Phone Book:" << std::endl;
        for (int i = 0; i < numContacts; ++i) {
            int index = (nextIndex + i) % MAX_CONTACTS; // Calculate the actual index of the contact
            std::cout << "|" << std::right << i
                      << "|" << std::right << truncateString(contacts[index].getFirstName())
                      << "|" << std::right << truncateString(contacts[index].getLastName())
                      << "|" << std::right << truncateString(contacts[index].getNickname())
                      << "|" << std::endl;
        }
    }

void PhoneBook::displayContactDetails(int index) const
{
        if (index >= 0 && index < numContacts) {
            int actualIndex = (nextIndex + index) % MAX_CONTACTS;
            const Contact& contact = contacts[actualIndex];
            std::cout << "First Name: " << contact.getFirstName() << std::endl;
            std::cout << "Last Name: " << contact.getLastName() << std::endl;
            std::cout << "Nickname: " << contact.getNickname() << std::endl;
            std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
        } else {
            std::cout << "Error: Invalid index." << std::endl;
        }
}

void PhoneBook::addContact(const Contact& contact)
{
        if (numContacts < MAX_CONTACTS)
		{
            contacts[nextIndex++] = contact;
            numContacts++;
        }
        else
        {
            contacts[nextIndex % MAX_CONTACTS] = contact;
            nextIndex = (nextIndex + 1) % MAX_CONTACTS;
        }
}