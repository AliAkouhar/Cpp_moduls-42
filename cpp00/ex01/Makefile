CXX = c++
SRC = Add.cpp  ContactImplimentation.cpp  main.cpp  PhoneBookImplimentation.cpp  Searsh.cpp
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = contact
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all