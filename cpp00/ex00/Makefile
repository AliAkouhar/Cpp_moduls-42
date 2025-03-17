# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 11:23:24 by aakouhar          #+#    #+#              #
#    Updated: 2024/10/14 11:23:25 by aakouhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
SRC = megaphone.cpp
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
