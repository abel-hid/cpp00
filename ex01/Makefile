SRCS = main.cpp\
		Contact.cpp\
		PhoneBook.cpp\
		utils.cpp\


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
