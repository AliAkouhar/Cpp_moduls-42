CXX = c++
SRC = Account.cpp tests.cpp
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = accounts
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all