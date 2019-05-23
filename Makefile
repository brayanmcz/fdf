# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 20:05:48 by bcastro           #+#    #+#              #
#    Updated: 2019/05/22 16:53:06 by bcastro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ./libft
MINILIBX_DIR  = ./minilibx
SRCS = ./src/main.c ./src/fdf.c ./src/rotations.c ./src/drawer.c ./src/read.c
LIBS = ./minilibx/libmlx.a ./libft/libft.a

#ECHO COLORS
NOC=\033[0m
GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m

all:
	@echo "LIBFT:"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "MINILIBX:"
	@$(MAKE) -C $(MINILIBX_DIR)
	@echo "FDF:"
	@gcc -Wall -Wextra -Werror $(SRCS) $(LIBS) -framework OpenGL -framework AppKit -o fdf
	@echo "$(GREEN) ✓ FDF: Created executable 'fdf' $(NOC)"

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