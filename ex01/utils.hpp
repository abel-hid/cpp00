/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 03:48:58 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/18 23:20:36 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include <iostream>
# include <iomanip>
# include <string>

std::string ft_substr(std::string str, unsigned long len);
void show_column(std::string data, int len);
int is_space(std::string command);
int parsing_num(std::string command);
int parsing_index(std::string command);

#endif