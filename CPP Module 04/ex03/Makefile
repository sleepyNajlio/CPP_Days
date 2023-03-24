# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 03:45:53 by nloutfi           #+#    #+#              #
#    Updated: 2023/03/24 04:47:46 by nloutfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Materials

SRC		= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

CC		= c++ -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(SRC) -o $(NAME)
	@echo "✅"

clean :
	@rm -f $(NAME)
	@echo "❌"
	
fclean : clean

re : fclean all