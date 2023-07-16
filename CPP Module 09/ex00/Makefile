NAME	=	btc

SRCS	=	main.cpp BitcoinExchange.cpp

CC		=	c++ -Wall -Wextra -Werror -std=c++98

all		:	$(NAME)

$(NAME)	:	$(SRCS)
			@$(CC) $(SRCS) -o $(NAME)
			@echo "✅"

clean	:
			@rm -f $(NAME)
			@echo "❌"

fclean	:	clean
