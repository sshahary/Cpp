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

#include "contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

void Contact::setFirstName(const std::string &fn) { firstName = fn; }
void Contact::setLastName(const std::string &ln) { lastName = ln; }
void Contact::setNickname(const std::string &nn) { nickname = nn; }
void Contact::setPhoneNumber(const std::string &pn) { phoneNumber = pn; }
void Contact::setDarkestSecret(const std::string &ds) { darkestSecret = ds; }

void Contact::setContact(const std::string &fn, const std::string &ln, const std::string &nn, const std::string &pn, const std::string &ds) {
    firstName = fn;
    lastName = ln;
    nickname = nn;
    phoneNumber = pn;
    darkestSecret = ds;
}
