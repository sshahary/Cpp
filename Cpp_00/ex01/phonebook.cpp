/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:31:37 by sshahary          #+#    #+#             */
/*   Updated: 2024/04/04 12:09:09 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"
#include "contact.class.hpp"

std::string promptUserForInput(const std::string& prompt)
{
	std::string input;
	std::cout << prompt << ": ";
	std::getline(std::cin, input);
	// if (!(std::getline(std::cin, input)))         i have to protect this
	// 	std::cout << "invalid input" << std::endl;
	return input;
}

void executeCommand(PhoneBook& phoneBook, const std::string& command)
{
	if (command == "ADD")
	{
		std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
		firstName = promptUserForInput("Enter first name");
		lastName = promptUserForInput("Enter last name");
		nickname = promptUserForInput("Enter nickname");
		phoneNumber = promptUserForInput("Enter phone number");
		darkestSecret = promptUserForInput("Enter darkest secret");

		if (!firstName.empty() && !lastName.empty() && !nickname.empty() &&
			!phoneNumber.empty() && !darkestSecret.empty())
			{
				phoneBook.addContact(Contact(firstName, lastName, nickname, phoneNumber, darkestSecret));
				std::cout << "Contact added successfully." << std::endl;
			} 
		else
			std::cout << "Error: All fields must be filled." << std::endl;
	}
	else if (command == "SEARCH")
	{
		phoneBook.displayContacts();
		size_t index;
		std::cout << "Enter the index of the contact to display: ";
		std::cin >> index;
		phoneBook.displayContactDetails(index);
	}
	else if (command == "EXIT")
		std::cout << "Exiting program. Contacts are lost forever..." << std::endl;
	else
		std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Phone Book Application" << std::endl;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::cin >> command;

		// Convert the command to uppercase for case-insensitive comparison
		std::transform(command.begin(), command.end(), command.begin(), ::toupper);

		std::cin.ignore(); // Clear input buffer

		if (std::cin.fail())
		{ // If input was not a string
			std::cin.clear(); // Clear error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard input buffer
			std::cout << "Invalid input. Please enter a valid command." << std::endl;
			continue; // Prompt again for input
		}

		executeCommand(phoneBook, command);

		if (command == "EXIT") {
			break; // Exit the loop
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard remaining input buffer
	}

	return 0;
}
