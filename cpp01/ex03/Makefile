# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 11:23:24 by aakouhar          #+#    #+#              #
#    Updated: 2024/11/04 12:29:05 by aakouhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
SRC = main.cpp HumanA.cpp HumanB.cpp weapon.cpp
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = weap
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all