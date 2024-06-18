/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:19:38 by sshahary          #+#    #+#             */
/*   Updated: 2024/06/18 11:19:38 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <limits>


void executeCommand(PhoneBook& phoneBook, const std::string& command)
{
    if (command == "ADD")
    {
        phoneBook.addContact();
        std::cout << "Contact added successfully." << std::endl;
    }
    else if (command == "SEARCH")
    {
        phoneBook.displayContacts();
        int index;
        std::cout << "Enter the index of the contact to display: ";
        std::cin >> index;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        command = promptUserForInput("Enter command (ADD, SEARCH, EXIT) ");
        executeCommand(phoneBook, command);
        if (command == "EXIT")
            break;
    }

    return 0;
}