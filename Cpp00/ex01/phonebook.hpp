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

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <string>
#include <cstdio>
#include <iostream>
#include <iomanip>

class PhoneBook {
private:
    Contact contacts[8];
    int numContacts;
    std::string truncateString(const std::string& str, size_t width = 10) const;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void displayContacts() const;
    void displayContactDetails(int index) const;
};
std::string promptUserForInput(const std::string& prompt);

#endif
