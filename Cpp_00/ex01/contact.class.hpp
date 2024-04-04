/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:30:12 by sshahary          #+#    #+#             */
/*   Updated: 2024/04/04 10:49:24 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include "phonebook.class.hpp"

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact(const std::string& firstName, const std::string& lastName,
			const std::string& nickname, const std::string& phoneNumber,
			const std::string& darkestSecret)
		: firstName(firstName), lastName(lastName), nickname(nickname),
		  phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

	std::string getFirstName() const {
		return firstName;
	}

	std::string getLastName() const {
		return lastName;
	}

	std::string getNickname() const {
		return nickname;
	}

	std::string getPhoneNumber() const {
		return phoneNumber;
	}

	std::string getDarkestSecret() const {
		return darkestSecret;
	}
};

# endif