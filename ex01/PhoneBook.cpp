/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 03:02:45 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/16 06:31:41 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    oldest_index = 0;
    for (int i = 0; i < 8; i++)
    {
        contacts[i].setFirstName("");
        contacts[i].setLastName("");
        contacts[i].setNickname("");
        contacts[i].setPhoneNumber("");
        contacts[i].setDarkestSecret("");
    }
}

Contact PhoneBook::getContactByIndex(int index) const
{
    if (index >= 0 && index < 8)
        return contacts[index];
    else
        return Contact();
}
void PhoneBook::addContact(const Contact contact)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (contacts[i].getFirstName().empty())
        {
            contacts[i] = contact;
            break;
        }
        else if (i == 7)
        {
            if(oldest_index == 8)
                oldest_index = 0;
            contacts[oldest_index] = contact;
            oldest_index++;
            break;
        }
    }
}