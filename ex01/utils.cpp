/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 03:48:33 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/18 23:17:08 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string ft_substr(std::string str, unsigned long len)
{
    if (str.length() <= len)
        return (str);
    return (str.substr(0, len - 1) + ".");
}

void show_column(std::string data, int len)
{
    std::cout << std::setw(len) << std::right << ft_substr(data, len) << "|";
}


int is_space(std::string command)
{
    int i = 0;
    while (command[i])
    {
        if(!isspace(command[i]))
            return (0);
        i++;
    }
    return (1);

}

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

int parsing_num(std::string command)
{
    int i = 0;
    if (command[0] == '+')
        i++;
    while (command[i])
    {
        if (!isdigit(command[i]))
            return (1);
        i++;
    }
    return (0);
}