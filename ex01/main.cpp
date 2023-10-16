/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 03:15:59 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/16 03:51:28 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"

void haha(PhoneBook phonebook)
{
    while (1)
    {
        int index;
        std::string command;
        std::cout << "Enter index: ";
        // getline(cin, command);
        // if (command.empty() || isdigit_ss(command))
        // {
        //     cout << "Invalid index. Please try again." << endl;
        //     continue;
        // }
        // index = atoi(command.c_str());

        if (std::cin.eof())
            break;
        if (!(std::cin >> index))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid index. Please try again." << std::endl;
            continue;
        }
        if (index >= 0 && index < 8 && !phonebook.getContactByIndex(index).getFirstName().empty())
        {
            std::cout << "Contact details for index " << index << ":" << std::endl;
            std::cout << "First Name: " << phonebook.getContactByIndex(index).getFirstName() << std::endl;
            std::cout << "Last Name: " << phonebook.getContactByIndex(index).getLastName() << std::endl;
            std::cout << "Nickname: " << phonebook.getContactByIndex(index).getNickname() << std::endl;
            std::cout << "Phone Number: " << phonebook.getContactByIndex(index).getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << phonebook.getContactByIndex(index).getDarkestSecret() << std::endl;
            std::cin.ignore();
            break;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
void add_contact(PhoneBook &phonebook, int &oldest_index)
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
         if (command.empty() || is_space(command) || parsing_num(command))
        {
            std::cout << "Invalid phone number. Please try again." << std::endl;
            continue;
        }
        break;
    }
    contact.setPhoneNumber(command);
    contact.setDarkestSecret(enter_atrubiute("darkest secret"));
    phonebook.addContact(contact, oldest_index);
}


int search_contact(PhoneBook phonebook)
{
    if(phonebook.getContactByIndex(0).getFirstName().empty())
    {
        std::cout << "No contacts found." << std::endl;
        return (1);
    }
    
    std::cout << std::setw(10) << "index     |first name|last name |nickname  |" << std::endl;
    std::cout << "----------|----------|----------|----------|" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (!phonebook.getContactByIndex(i).getFirstName().empty())
        {
            std::cout << std::setw(10) << i << "|";
            show_column(phonebook.getContactByIndex(i).getFirstName(), 10);
            show_column(phonebook.getContactByIndex(i).getLastName(), 10);
            show_column(phonebook.getContactByIndex(i).getNickname(), 10);
            std::cout << std::endl;
        }
    }
    return (0);
}
int main()
{
    PhoneBook phonebook;
    Contact contact;
    int oldest_index = 0;

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
            add_contact(phonebook, oldest_index);
        else if (command == "SEARCH")
        {
            if (search_contact(phonebook))
                continue;
            haha(phonebook);
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
