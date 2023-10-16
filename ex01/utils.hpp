/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 03:48:58 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/16 20:24:50 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <iomanip>
# include <string>

std::string ft_substr(const std::string str, unsigned long len);
void show_column(const std::string data, int len);
int is_space(std::string command);
int parsing_num(std::string command);


#endif