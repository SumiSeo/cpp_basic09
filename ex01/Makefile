NAME = RPN

SRC = RPN.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -g3 -Wall -Wextra -Werror -std=c++98

RM = rm -rf

.PHONY: all clean fclean re

all : $(NAME)

.cpp.o :
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME) : $(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) -g3 $(OBJ)

clean :
			$(RM) $(OBJ)

fclean : clean
			$(RM) $(NAME) $(OBJ)

re : fclean all