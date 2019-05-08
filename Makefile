# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brayan <brayan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 20:05:48 by bcastro           #+#    #+#              #
#    Updated: 2019/05/08 16:52:20 by brayan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ./lib/libft
MINILIBX_DIR  = ./lib/minilibx
SRCS = ./src/main.c ./src/fdf.c

#ECHO COLORS
NOC=\033[0m
GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m

all:
	@echo ""
	@$(MAKE) -w -s -C $(LIBFT_DIR)
	@echo ""
	@$(MAKE) -w -s -C $(MINILIBX_DIR)
	@echo ""
	@gcc -Wall -Wextra -Werror $(SRCS) ./lib/minilibx/libmlx.a -framework OpenGL -framework AppKit -o fdf
	@ ./fdf

re: fclean all

clean: 
	@echo ""
	@make clean -s -C $(LIBFT_DIR)
	@echo ""
	@make clean -s -C $(MINILIBX_DIR)
	@echo ""

fclean:
	@rm fdf
	@make fclean -s -C $(LIBFT_DIR)
	@make fclean -s -C $(MINILIBX_DIR)

	@echo "$(RED) ✗ FDF: Removed compiled fdf file $(NOC)"

.PHONY: re