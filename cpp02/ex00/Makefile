# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 10:58:55 by aakouhar          #+#    #+#              #
#    Updated: 2024/11/16 11:33:14 by aakouhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
SRC = main.cpp Fixed.cpp
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = a.out
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all