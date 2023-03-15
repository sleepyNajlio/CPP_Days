# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nloutfi <nloutfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 03:45:53 by nloutfi           #+#    #+#              #
#    Updated: 2023/03/15 23:48:45 by nloutfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Zombies

SRC		= main.cpp Zombie.cpp zombieHorde.cpp 

CC		= c++ -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean :
	rm -f $(NAME)
	
fclean : clean

re : fclean all