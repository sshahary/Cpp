/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:07:27 by sshahary          #+#    #+#             */
/*   Updated: 2024/06/07 21:06:07 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "contact.class.hpp"

class PhoneBook {
private:
    Contact contact[8];
    int numContacts;
    int nextIndex;
    std::string truncateString(const std::string& str, size_t width = 10) const;

public:

    PhoneBook() : numContacts(0), nextIndex(0) {};

    void addContact(const Contact& contact);
    void displayContacts() const;
    void displayContactDetails(int index) const;
    int getNumContacts() const { return numContacts; }
};


#endif