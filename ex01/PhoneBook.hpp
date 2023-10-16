/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 03:02:52 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/16 04:36:22 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
class PhoneBook
{
private:
    Contact contacts[8];
    // int oldest_index;
public:

    PhoneBook();
    Contact getContactByIndex(int index) const;
    void addContact(const Contact &contact, int &oldest_index);
    void search_by_index();
    int search_contact();
    void add_contact(int &oldest_index);
};


#endif