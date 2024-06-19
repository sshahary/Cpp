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

int isString(std::string command)
{
    int index;

    if (command.length() < 1 || command.length() > 1)
        return (-1);
    index = command[0] - '0';
    if (index >= 0 && index <= 7)
        return (index);
    return (-1);
}

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
        index = isString(promptUserForInput("Enter the index of the contact to display"));
        if (index == -1)
        {
            std::cout << "Invalid Index"<<std::endl;
            return ;
        }
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