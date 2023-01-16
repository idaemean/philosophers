# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 10:43:52 by iczarnie          #+#    #+#              #
#    Updated: 2023/01/11 10:43:52 by iczarnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c utils.c parsing.c initialise.c

CFLAGS = -Wall -Wextra -pthread
CC = gcc
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(CFLAGS) -g -o $(NAME)
	@echo "Compiled!"
clean:
	rm -rf $(OBJ)
	@echo "Executables cleaned."
fclean: clean
	rm -f $(NAME)
	@echo "Cleaned!"

re: fclean all
	@echo "Compiling again was succesful!"

.PHONY: all clean fclean re