# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 11:38:03 by lduflot           #+#    #+#              #
#    Updated: 2025/07/30 08:09:06 by lduflot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


###############################
## ARGUMENTS/MACRO

CC = cc
CFLAGS = -g -pthread -Wall -Wextra -Werror
NAME = philo

###############################
## SOURCES

FILES = philo.c \
				source/philo_utils.c \
				source/thread.c \
				source/task_philo.c \
				source/task_philo2.c \
				source/death.c \
				source/init.c \
				source/time.c

OBJS = $(FILES:.c=.o)

###############################
## RULES


all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n Les philosophers attendent vos instructions.\n"
	@echo "                                                                                "
	@echo "                               \033[1m⚙️  PHILOSOPHERS ⚙️\033[0m                              "
	@echo "                                                                                "
	@echo " Dans un monde parallèle, il existe un mystérieux groupe.                      "
	@echo " Ils se retrouvent autour d'une table ronde pour \033[1mMANGER\033[0m, \033[1mPENSER\033[0m et \033[1mDORMIR\033[0m.                            "
	@echo "                                                                                "
	@echo " Ils se nourrissent exclusivement de spaghettis qu'ils dégustent avec \033[1m2 FOURCHETTES\033[0m.   "
	@echo " Chaque philosophe arrive avec une fourchette, il doit manger avec la sienne   "
	@echo " et celle de son voisin.                                                 "
	@echo "                                                                                "
	@echo " \033[1mGuidez les philosophers avec les instructions suivantes:                    "
	@echo ""
	@echo "        1 Nombres de philosophers                                              "
	@echo "        2 Temps avant qu'ils ne meurent de faim                               "
	@echo "        3 Temps du repas                                                      "
	@echo "        4 Temps de sommeil \033[0m   "
	@echo " *Temps en micro seconde*                                           "
	@echo " \033[1mOptionnel:                                                                 "
	@echo "        5 Nombre de repas qu'ils vont manger avant de terminer leur réunion.\033[0m  "
	@echo "                                                                                "
	@echo " "
	@echo "                              🌑 🌒 🌓 🌔 🌕 🌖 🌗 🌘                      "
	@echo " "
	@echo "                                     ψ👴____ψ👩    "
	@echo "                                    /          \                           "
	@echo "                                   /            \ "
	@echo "                                 🧔ψ     🍝     ψ🧒                            "
	@echo "                                   \            /                          "
	@echo "                                    \   ____   /                         "
	@echo "                                     👶ψ    👵ψ"
	@echo " "
	@echo "                              🌑 🌒 🌓 🌔 🌕 🌖 🌗 🌘                      "
	@echo " "
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning .o"
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning program"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re intro
