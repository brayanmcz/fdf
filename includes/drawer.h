/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:49:01 by bcastro           #+#    #+#             */
/*   Updated: 2019/05/22 17:50:56 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWER_H
# define DRAWER_H
# include "fdf.h"

typedef struct	s_point
{
	int x;
	int y;
	int z;
}				t_point;

typedef struct	s_line
{
	int dx;
	int dy;
	int sx;
	int sy;
	int e1;
	int e2;
}				t_line;

typedef enum	e_projection
{
	ISO,
	ORTHO
}				t_project;

typedef struct	s_camera
{
	int				x_rot;
	int				y_rot;
	int				z_rot;
	int				zoom;
	int				x_offset;
	int				y_offset;
	int				z_intensity;
	t_project		projection;
}				t_camera;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			**map;
	t_camera	camera;
	t_point		orig;
	t_point		dest;
}				t_fdf;

void			draw_line(t_point orig,
				t_point dest, void *mlx_ptr, void *win_ptr);
void			show_map(t_fdf fdf, int col, int row);
void			show_cols(t_fdf fdf, int col, int row);
void			show_rows(t_fdf fdf, int col, int row);

#endif
