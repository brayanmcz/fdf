# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 20:05:48 by bcastro           #+#    #+#              #
#    Updated: 2019/04/29 12:54:19 by bcastro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ./lib/libft
MINILIBX_DIR  = ./lib/minilibx

all:
	@echo ""
	@$(MAKE) -w -s -C $(LIBFT_DIR)
	@echo ""
	@$(MAKE) -w -s -C $(MINILIBX_DIR)
	@echo ""
	@gcc ./src/main.c ./lib/minilibx/libmlx.a -framework OpenGL -framework AppKit -o fdf
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

	@echo "Removed compiled fdf file"

.PHONY: re