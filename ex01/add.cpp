/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:46:34 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/22 00:10:57 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

int is_alpha(std::string command)
{
    int i = 0;
    while (command[i])
    {
        if (!isalpha(command[i]))
            return (0);
        i++;
    }
    return (1);
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
        if (command.empty() || is_space(command) || !is_alpha(command))
        {
            std::cout << "Invalid " << atrubiute << ". Please try again." << std::endl;
            continue;  
        }
        break;
    }
    return (command);
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
