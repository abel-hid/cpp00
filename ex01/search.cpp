/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:43:20 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/18 19:51:03 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

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