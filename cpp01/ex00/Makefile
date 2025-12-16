NAME = Zombie

F = main Zombie newZombie randomChump

SRC = $(foreach f, $(F), $(f).cpp)

OBJ = $(SRC:.cpp=.o)

GFLAG = -Wall -Wextra -Werror -std=c++98 -g3

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(GFLAG) $(OBJ) -o $(NAME)

.cpp.o:
	c++ $(GFLAG) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

r: re
	./$(NAME)

re: fclean all