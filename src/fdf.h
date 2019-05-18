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

typedef	struct	s_point {
	int x;   //x position on map
 	int y;   //y position on map
	int z;   //z poistion on map
} t_point;

void	line(t_point start, t_point end, void *mlx_ptr, void *win_ptr);
void	fdf(char *file_name);

t_point x_axis_rotation(t_point point, long double rad);
t_point y_axis_rotation(t_point point, long double rad);
t_point z_axis_rotation(t_point point, long double rad);
t_point rotate(t_point point, int x, int y, int z);
double deg_to_rad(int deg);


#endif