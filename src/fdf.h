/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:11:06 by brayan            #+#    #+#             */
/*   Updated: 2019/05/08 18:09:00 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include "stdlib.h"
# include "stdio.h" //DELETE THIS before project submitted

typedef	struct	s_point {
	unsigned char x;         //x position on map
 	unsigned char y;         //y position on map
	unsigned char z;         //z poistion on map
	struct s_point *nbrs[2]; //2 possible neighbors (down and right)
} t_point;

// Bresenham Line Algorithm
void	line(t_point start, t_point end, void *mlx_ptr, void *win_ptr);
void	fdf(char *file_name);

#endif