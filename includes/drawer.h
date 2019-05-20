/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:49:01 by bcastro           #+#    #+#             */
/*   Updated: 2019/05/19 20:32:13 by bcastro          ###   ########.fr       */
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

typedef struct	s_line{
	int dx;
	int dy;
	int sx;
	int sy;
	int e1;
	int e2;
}				t_line;

void			line(t_point orig, t_point dest, void *mlx_ptr, void *win_ptr);

#endif
