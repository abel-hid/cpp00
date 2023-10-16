/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 03:15:59 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/16 06:42:57 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"
int parsing_index(std::string command)
{
    int i = 0;
    while (command[i])
    {
        if (!isdigit(command[i]))
            return (1);
        i++;
    }
    return (0);
}
void PhoneBook ::search_by_index()
{
    while (1)
    {
        std::string input;
        int index;
        std::cout << "Enter index: ";

        std::getline(std::cin, input);
        if(std::cin.eof())
            exit(0);
        if (input.empty() || !isdigit(input[0]) || parsing_index(input))
        {
            std::cout << "Invalid index. Please try again." << std::endl;
            continue;
        }
        index = std::atoi(input.c_str());
        if (index >= 0 && index < 8 && !getContactByIndex(index).getFirstName().empty())
        {
            std::cout << "Contact details for index " << index << ":" << std::endl;
            std:: cout << "First name: " << getContactByIndex(index).getFirstName() << std::endl;
            std:: cout << "Last name: " << getContactByIndex(index).getLastName() << std::endl;
            std:: cout << "Nickname: " << getContactByIndex(index).getNickname() << std::endl;
            std:: cout << "Phone number: " << getContactByIndex(index).getPhoneNumber() << std::endl;
            std:: cout << "Darkest secret: " << getContactByIndex(index).getDarkestSecret() << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid index. Please try again." << std::endl;
        }
    }
}


std::string enter_atrubiute(std::string atrubiute)
{
    std::string command;
    while (1)
    {
        std::cout << "Enter " << atrubiute << ": ";
        getline(std::cin, command);
        if (std::cin.eof())
            exit(0);
        if (command.empty() || is_space(command))
        {
            std::cout << "Invalid " << atrubiute << ". Please try again." << std::endl;
            continue;
        }
        break;
    }
    return command;
}
void    PhoneBook::add_contact()
{
    Contact contact;
    std::string command;
    contact.setFirstName(enter_atrubiute("first name"));
    contact.setLastName(enter_atrubiute("last name"));
    contact.setNickname(enter_atrubiute("nickname"));
    while(1)
    {
        std::cout << "Enter phone number: ";
        getline(std::cin, command);
        if (std::cin.eof())
            exit(0);
         else if (command.empty() || is_space(command) || parsing_num(command))
        {
            std::cout << "Invalid phone number. Please try again." << std::endl;
            continue;
        }
        break;
    }
    contact.setPhoneNumber(command);
    contact.setDarkestSecret(enter_atrubiute("darkest secret"));
    addContact(contact);
}


int PhoneBook::search_contact()
{
    if(getContactByIndex(0).getFirstName().empty())
    {
        std::cout << "No contacts found." << std::endl;
        return (1);
    }
    
    std::cout << std::setw(10) << "index     |first name|last name |nickname  |" << std::endl;
    std::cout << "----------|----------|----------|----------|" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (!getContactByIndex(i).getFirstName().empty())
        {
            std::cout << std::setw(10) << i << "|";
            show_column(getContactByIndex(i).getFirstName(), 10);
            show_column(getContactByIndex(i).getLastName(), 10);
            show_column(getContactByIndex(i).getNickname(), 10);
            std::cout << std::endl;
        }
    }
    return (0);
}
int main()
{
    PhoneBook phonebook;
    Contact contact;

    std::string command;
    while (true)
    {
        std::cout << "Enter command: ";
        getline(std::cin, command);
        if (std::cin.eof())
            break;
        if (command.empty())
            continue;
        if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
        {
            if (phonebook.search_contact())
                continue;
            phonebook.search_by_index();
            continue;
        }
        else if (command == "EXIT")
        {
            std::cout << "Bye!" << std::endl;
            break;
        }
        else
            std::cout << "Invalid command. Please try again." << std::endl;
    }
    return 0;
}
