/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 02:55:58 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/18 23:03:12 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName()
{
    return (first_name);
}

std::string Contact::getLastName()
{
    return (last_name);
}
std::string Contact::getNickname()
{
    return (nickname);
}

std::string Contact::getPhoneNumber()
{
    return (phone_number);
}

std::string Contact::getDarkestSecret()
{
    return (darkest_secret);
}

void Contact::setFirstName(std::string first_name)
{
    this->first_name = first_name;
}

void Contact::setLastName(std::string last_name)
{
    this->last_name = last_name;
}
void Contact::setNickname(std::string nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(std::string phone_number)
{
    this->phone_number = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}
