# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 20:07:55 by abel-hid          #+#    #+#              #
#    Updated: 2023/10/18 20:07:56 by abel-hid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp\
		Contact.cpp\
		PhoneBook.cpp\
		utils.cpp\
		search.cpp\
		add.cpp\


OBJ = $(SRCS:.cpp=.o)
CPP = c++
RM = rm -f
HEADERS = Contact.hpp PhoneBook.hpp utils.hpp
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phoneBook

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
