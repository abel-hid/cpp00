
SRCS = megaphone.cpp
OBJ = $(SRCS:.cpp=.o)
CC = g++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -std=c++98
NAME = phoneBook

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all