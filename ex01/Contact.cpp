/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 02:55:58 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/16 02:57:22 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName() const
{
    return first_name;
}
std::string Contact::getLastName() const
{
    return last_name;
}
std::string Contact::getNickname() const
{
    return nickname;
}
std::string Contact::getPhoneNumber() const
{
    return phone_number;
}
std::string Contact::getDarkestSecret() const
{
    return darkest_secret;
}

void Contact::setFirstName(const std::string first_name)
{
    this->first_name = first_name;
}
void Contact::setLastName(const std::string last_name)
{
    this->last_name = last_name;
}
void Contact::setNickname(const std::string nickname)
{
    this->nickname = nickname;
}
void Contact::setPhoneNumber(const std::string phone_number)
{
    this->phone_number = phone_number;
}
void Contact::setDarkestSecret(const std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}
