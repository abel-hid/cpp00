

SRCS = main.cpp

OBJ = $(SRCS:.cpp=.o)

CC = g++

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = phoneBook
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)