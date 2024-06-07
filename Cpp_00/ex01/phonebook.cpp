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

#include "phonebook.class.hpp"
#include "contact.class.hpp"

std::string promptUserForInput(const std::string& prompt)
{
	std::string input;
    while (true)
    {
        std::cout << prompt << ": ";
        std::getline(std::cin, input);
        if (!input.empty())
            break;
        std::cout << "Invalid input. Please try again." << std::endl;
    }
    return input;

}

// void executeCommand(PhoneBook& phoneBook, const std::string& command)
// {
// 	if (command == "ADD")
// 	{
// 		std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
// 		firstName = promptUserForInput("Enter first name");
// 		lastName = promptUserForInput("Enter last name");
// 		nickname = promptUserForInput("Enter nickname");
// 		phoneNumber = promptUserForInput("Enter phone number");
// 		darkestSecret = promptUserForInput("Enter darkest secret");

// 		if (!firstName.empty() && !lastName.empty() && !nickname.empty() &&
// 			!phoneNumber.empty() && !darkestSecret.empty())
// 			{
// 				phoneBook.addContact(Contact(firstName, lastName, nickname, phoneNumber, darkestSecret));
// 				std::cout << "Contact added successfully." << std::endl;
// 			} 
// 		else
// 			std::cout << "Error: All fields must be filled." << std::endl;
// 	}
// 	else if (command == "SEARCH")
// 	{
// 		phoneBook.displayContacts();
// 		size_t index;
// 		std::cout << "Enter the index of the contact to display: ";
// 		std::cin >> index;
// 		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// 		phoneBook.displayContactDetails(index);
// 	}
// 	else if (command == "EXIT")
// 		std::cout << "Exiting program. Contacts are lost forever..." << std::endl;
// 	else
// 		std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
// }

// int main()
// {
// 	PhoneBook phoneBook;
// 	std::string command;

// 	std::cout << "Phone Book Application" << std::endl;

// 	while (true)
// 	{
// 		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
// 		std::cin >> command;

// 		std::transform(command.begin(), command.end(), command.begin(), ::toupper);
// 		std::cin.ignore();

// 		if (std::cin.fail())
// 		{
// 			std::cin.clear();
// 			std::cin.ignore(std::numeric_limits<std::streamsize>::max());
// 			std::cout << "Invalid input. Please enter a valid command." << std::endl;
// 			break;
// 		}

// 		executeCommand(phoneBook, command);

// 		if (command == "EXIT")
// 			break;

// 		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// 	}

// 	return 0;
// }

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

        phoneBook.addContact(Contact(firstName, lastName, nickname, phoneNumber, darkestSecret));
        std::cout << "Contact added successfully." << std::endl;
    }
    else if (command == "SEARCH")
    {
        phoneBook.displayContacts();
        std::cout << "Enter the index of the contact to display: ";
        int index;
        std::cin >> index;

        if (std::cin.fail() || index < 0 || index >= phoneBook.getNumContacts())
        {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the input
            std::cout << "Invalid index. Please enter a number between 0 and " << phoneBook.getNumContacts() - 1 << "." << std::endl;
        }
        else
        {
            phoneBook.displayContactDetails(index);
        }

        // Clear the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else if (command == "EXIT")
    {
        std::cout << "Exiting program. Contacts are lost forever..." << std::endl;
    }
    else
    {
        std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
    }
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Phone Book Application" << std::endl;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        std::transform(command.begin(), command.end(), command.begin(), ::toupper);

        executeCommand(phoneBook, command);

        if (command == "EXIT")
            break;
    }

    return 0;
}
