#!/bin/bash

#!bin/zsh
##Possibilite de l'exe avec zhs egalement, le code étant compatible
#Run =
# make project
# ./test_philo.sh

# couleurs
YELLOW='\033[0;33m'
GREEN='\033[0;32m'
RESET='\033[0m' ##reviens à la color de base

# Fichier .sh = sript shell = suite de commandes que j'aurai écrites à la mano dans mon terminal. S'exe automatiquement dans ce script.
# Le -e de echo = par défaut echo affiche ce qu'on lui donne tel quel, sans interpréter les caractere spéciaux. L'option -e permet d'afficher les séquences d'échappements.
# Séquences d'échappement = caractere spéciaux précédés d'un \
# Dans le cas du script : les couleurs \033

#NO VALGRIND :

echo
echo -e "${YELLOW}Test: no arguments${RESET}"
echo -e "${GREEN}./philo${RESET}"
./philo
echo

echo
echo -e "${YELLOW}Test: miss arguments${RESET}"
echo -e "${GREEN}./philo 4 800 200${RESET}"
./philo 4 800 200
echo

echo
echo -e "${YELLOW}Test: arguments no valid letters${RESET}"
echo -e "${GREEN}./philo a b c d${RESET}"
./philo a b c d
echo

echo
echo -e "${YELLOW}Test: invalid argument negative${RESET}"
echo -e "${GREEN}./philo -1 800 200 200${RESET}"
./philo -1 800 200 200
echo

echo
echo -e "${YELLOW}Test: too many arguments${RESET}"
echo -e "${GREEN}./philo 4 800 200 200 5 9${RESET}"
./philo 4 800 200 200 5 9
echo

echo
echo -e "${YELLOW}Test: argument invalid 0 philos${RESET}"
echo -e "${GREEN}./philo 0 800 200 200${RESET}"
./philo 0 800 200 200
echo

echo
echo -e "${YELLOW}Test: argument invalid 0 time_to_die${RESET}"
echo -e "${GREEN}./philo 1 0 200 200${RESET}"
./philo 1 0 200 200
echo

echo
echo -e "${YELLOW}Test: argument invalid 0 time_to_eat${RESET}"
echo -e "${GREEN}./philo 1 800 0 200${RESET}"
./philo 1 800 0 200
echo

echo
echo -e "${YELLOW}Test: argument invalid 0 time_to_sleep${RESET}"
echo -e "${GREEN}./philo 1 800 200 0${RESET}"
./philo 1 800 200 0
echo

echo
echo -e "${YELLOW}Test: argument invalid 0 meals ${RESET}"
echo -e "${GREEN}./philo 4 800 200 200 0${RESET}"
./philo 4 800 200 200 0
echo

echo
echo -e "${YELLOW}Test: argument invalid letter ${RESET}"
echo -e "${GREEN}./philo 4 800f 200 200 7${RESET}"
./philo 4 800f 200 200 7
echo

echo
echo -e "${YELLOW}Test: all arguments 10ms${RESET}"
echo -e "${GREEN}./philo 4 10 10 10${RESET}"
./philo 4 10 10 1
echo

echo
echo -e "${YELLOW}Test: all arguments 10ms${RESET}"
echo -e "${GREEN}./philo 4 10 10 10${RESET}"
./philo 4 1 1 1
echo


echo
echo -e "${YELLOW}Test: death short${RESET}"
echo -e "${GREEN}./philo 5 100 60 60${RESET}"
./philo 5 100 60 60
echo

echo
echo -e "${YELLOW}Test: die${RESET}"
echo -e "${GREEN}./philo 1 200 100 100${RESET}"
./philo 1 200 100 100
echo

echo -e "${YELLOW}Test: no die, finish the meal${RESET}"
echo -e "${GREEN}./philo 5 800 200 200 4${RESET}"
./philo 5 800 200 200 4
echo

echo -e "${YELLOW}Test: die or finish the meal ?${RESET}"
echo -e "${GREEN}./philo 4 310 200 100 1${RESET}"
./philo 4 310 200 100
echo

echo -e "${YELLOW}Test: die${RESET}"
echo -e "${GREEN}./philo 4 310 200 100${RESET}"
./philo 4 310 200 100
echo

#With valgrind

echo -e "${YELLOW} RUN TEST WITH VALGRIND${RESET}"


echo
echo -e "${YELLOW}Test: no arguments${RESET}"
echo -e "${GREEN}./philo${RESET}"
valgrind ./philo
echo

echo
echo -e "${YELLOW}Test: miss arguments${RESET}"
echo -e "${GREEN}./philo 4 800 200${RESET}"
valgrind ./philo 4 800 200
echo

echo
echo -e "${YELLOW}Test: arguments no valid letters${RESET}"
echo -e "${GREEN}./philo a b c d${RESET}"
valgrind ./philo a b c d
echo

echo
echo -e "${YELLOW}Test: invalid argument negative${RESET}"
echo -e "${GREEN}./philo -1 800 200 200${RESET}"
./philo -1 800 200 200
echo

echo
echo -e "${YELLOW}Test: too many arguments${RESET}"
echo -e "${GREEN}./philo 4 800 200 200 5 9${RESET}"
valgrind ./philo 4 800 200 200 5 9
echo

echo
echo -e "${YELLOW}Test: argument invalid 0 philos${RESET}"
echo -e "${GREEN}./philo 0 800 200 200${RESET}"
valgrind ./philo 0 800 200 200
echo

echo
echo -e "${YELLOW}Test: argument invalid 0 time_to_die${RESET}"
echo -e "${GREEN}./philo 1 0 200 200${RESET}"
valgrind ./philo 1 0 200 200
echo

echo
echo -e "${YELLOW}Test: argument invalid 0 time_to_eat${RESET}"
echo -e "${GREEN}./philo 1 800 0 200${RESET}"
valgrind ./philo 1 800 0 200
echo

echo
echo -e "${YELLOW}Test: argument invalid 0 time_to_sleep${RESET}"
echo -e "${GREEN}./philo 1 800 200 0${RESET}"
valgrind ./philo 1 800 200 0
echo

echo
echo -e "${YELLOW}Test: argument invalid 0 meals ${RESET}"
echo -e "${GREEN}./philo 4 800 200 200 0${RESET}"
valgrind ./philo 4 800 200 200 0
echo

echo
echo -e "${YELLOW}Test: argument invalid letter ${RESET}"
echo -e "${GREEN}./philo 4 800f 200 200 7${RESET}"
./philo 4 800f 200 200 7
echo

echo
echo -e "${YELLOW}Test: all arguments 10ms${RESET}"
echo -e "${GREEN}./philo 4 10 10 10${RESET}"
valgrind --tool=helgrind ./philo 4 10 10 1
echo

echo
echo -e "${YELLOW}Test: all arguments 10ms${RESET}"
echo -e "${GREEN}./philo 4 10 10 10${RESET}"
valgrind --tool=helgrind ./philo 4 1 1 1
echo


echo
echo -e "${YELLOW}Test: death short${RESET}"
echo -e "${GREEN}./philo 5 100 60 60${RESET}"
valgrind --tool=helgrind ./philo 5 100 60 60
echo

echo
echo -e "${YELLOW}Test: die${RESET}"
echo -e "${GREEN}./philo 4 400 200 200${RESET}"
valgrind --tool=helgrind ./philo 4 400 200 200
echo

echo
echo -e "${YELLOW}Test: die${RESET}"
echo -e "${GREEN}./philo 1 200 100 100${RESET}"
valgrind --tool=helgrind ./philo 1 200 100 100
echo

echo -e "${YELLOW}Test: no die, finish the meal${RESET}"
echo -e "${GREEN}./philo 5 800 200 200 4${RESET}"
valgrind --tool=helgrind./philo 5 800 200 200 4
echo

echo -e "${YELLOW}Test: die or finish the meal ?${RESET}"
echo -e "${GREEN}./philo 4 310 200 100 1${RESET}"
valgrind --tool=helgrind ./philo 4 310 200 100
echo

echo -e "${YELLOW}Test: die${RESET}"
echo -e "${GREEN}./philo 4 310 200 100${RESET}"
valgrind --tool=helgrind ./philo 4 310 200 100
echo
