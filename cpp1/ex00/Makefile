# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 11:23:24 by aakouhar          #+#    #+#              #
#    Updated: 2024/10/30 12:07:25 by aakouhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = brainz
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all