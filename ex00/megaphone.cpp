/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:24:22 by abel-hid          #+#    #+#             */
/*   Updated: 2023/09/27 23:24:23 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac , char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }

    for (int j = 1; av[j] ; j++)
    {
        for (int i = 0; av[j][i]; i++)
            std::cout << (char)toupper(av[j][i]);
    }
    std::cout << std::endl;
    return (0);
}