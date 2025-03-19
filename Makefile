# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: williamcapt <williamcapt@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 13:14:48 by wcapt             #+#    #+#              #
#    Updated: 2025/03/10 16:22:05 by williamcapt      ###   ########.fr        #
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
		$(SRC_DIR)/sort.c

# Fichiers objets
OBJ = $(SRC:.c=.o)

# Dépendances
all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
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