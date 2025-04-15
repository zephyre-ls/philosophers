# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 11:38:03 by lduflot           #+#    #+#              #
#    Updated: 2025/04/15 15:53:27 by lduflot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


###############################
##ARGUMENTS/MACRO

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = philo

###############################
##SOURCES

FILES = philo.c \
				check_args.c \
				thread.c


OBJS = $(FILES:.c=.o)

###############################
##RULES

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compilation de $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Nettoyage des .o"
	@rm -f $(OBJS)
fclean: clean
	@echo "Nettoyage des .o et programme"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
