CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = AMateria.cpp  Character.cpp  Cure.cpp  Ice.cpp  main.cpp  MateriaSource.cpp Garbage.cpp
NAME = recap
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all