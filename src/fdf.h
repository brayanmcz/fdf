/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:11:06 by brayan            #+#    #+#             */
/*   Updated: 2019/05/08 18:23:44 by brayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "stdlib.h"
# include "stdio.h" //DELETE THIS before project submitted
# include "unistd.h"
# include "math.h"
// # define PI 3.14159265358979323846


typedef	struct	s_point {
	int x;   //x position on map
 	int y;   //y position on map
	int z;   //z poistion on map
} t_point;

// Bresenham Line Algorithm
void	line(t_point start, t_point end, void *mlx_ptr, void *win_ptr);
void	fdf(char *file_name);

#endif