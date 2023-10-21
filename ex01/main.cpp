/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 03:15:59 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/20 04:04:32 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"


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
    return (0);
}
