/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 03:48:33 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/16 03:51:09 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string ft_substr(const std::string &str, unsigned long len)
{
    if (str.length() <= len)
        return str;
    return (str.substr(0, len - 1) + ".");
}

void show_column(const std::string &data, int len)
{
    std::cout << std::setw(len) << std::right << ft_substr(data, len) << "|";
}

int isdigit_ss(std::string ss)
{
    int i = 0;
    while (ss[i])
    {
        if (!isdigit(ss[i]))
            return 1;
        i++;
    }
    return 0;
}
int is_space(std::string command)
{
    int i = 0;
    while (command[i])
    {
        if (command[i] != ' ' && command[i] != '\t' && command[i] != '\n' && command[i] != '\v' 
            && command[i] != '\f' && command[i] != '\r')
            return 0;
        i++;
    }
    return 1;
}

int parsing_num(std::string command)
{
    int i = 0;
   if(command[0] == '+')
        i++;
    while (command[i])
    {
        if (!isdigit(command[i]))
            return (1);
        i++;
    }
    return (0);
}