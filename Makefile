# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcapt <wcapt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 13:14:48 by wcapt             #+#    #+#              #
#    Updated: 2025/03/22 00:30:15 by wcapt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom des exécutables
NAME = push_swap

# Compilateur et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Dossiers
SRC_DIR	= src
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Fichiers sources
SRC = 	$(SRC_DIR)/checker.c $(SRC_DIR)/conditions.c $(SRC_DIR)/free.c	\
		$(SRC_DIR)/init.c $(SRC_DIR)/main.c $(SRC_DIR)/utils.c 	\
		$(SRC_DIR)/stack_a.c $(SRC_DIR)/stack_b.c $(SRC_DIR)/stack_ab.c \
		$(SRC_DIR)/sort1.c $(SRC_DIR)/sort2.c

# Fichiers objets
OBJ = $(SRC:.c=.o)

# Dépendances
all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[32m                                                                                       \033[0m"
	@echo "\033[32m ________  ___  ___  ________  ___  ___  ________  ___       __   ________  ________   \033[0m"
	@echo "\033[32m|\   __  \|\  \|\  \|\   ____\|\  \|\  \|\   ____\|\  \     |\  \|\   __  \|\   __  \  \033[0m"
	@echo "\033[32m\ \  \|\  \ \  \\\  \ \  \___|\ \  \\\  \ \  \___|\ \  \    \ \  \ \  \|\  \ \  \|\  \ \033[0m"
	@echo "\033[32m \ \   ____\ \  \\\  \ \_____  \ \   __  \ \_____  \ \  \  __\ \  \ \   __  \ \   ____\\033[0m"
	@echo "\033[32m  \ \  \___|\ \  \\\  \|____|\  \ \  \ \  \|____|\  \ \  \|\__\_\  \ \  \ \  \ \  \___|\033[0m"
	@echo "\033[32m   \ \__\    \ \_______\____\_\  \ \__\ \__\____\_\  \ \____________\ \__\ \__\ \__\   \033[0m"
	@echo "\033[32m    \|__|     \|_______|\_________\|__|\|__|\_________\|____________|\|__|\|__|\|__|   \033[0m"
	@echo "\033[32m                       \|_________|        \|_________|                                \033[0m"
	@echo "\033[32m                                                                                       \033[0m"
	@echo "\033[32m Push_swap compiled successfully!\033[0m"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[33m Object files removed!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[31m  Executable removed!\033[0m"

re: fclean all