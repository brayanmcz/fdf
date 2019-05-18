# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 20:05:48 by bcastro           #+#    #+#              #
#    Updated: 2019/05/17 21:47:08 by bcastro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ./libft
MINILIBX_DIR  = ./minilibx
SRCS = ./src/main.c ./src/fdf.c ./src/rotations.c
LIBS = ./minilibx/libmlx.a ./libft/libft.a

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
	@gcc -Wall -Wextra -Werror $(SRCS) $(LIBS) -framework OpenGL -framework AppKit -o fdf -g
	@echo "$(GREEN) ✓ Executable Created: 'fdf' $(NOC)"
	@./fdf maps/42.fdf

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