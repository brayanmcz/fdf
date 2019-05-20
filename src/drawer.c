/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 20:26:38 by bcastro           #+#    #+#             */
/*   Updated: 2019/05/19 20:32:05 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	line(t_point orig, t_point dest, void *mlx_ptr, void *win_ptr)
{
	t_line line;

	line.dx = abs(dest.x - orig.x);
	line.dy = -abs(dest.y - orig.y);
	line.sx = orig.x < dest.x ? 1 : -1;
	line.sy = orig.y < dest.y ? 1 : -1;
	line.e1 = line.dx + line.dy;
	while (!(orig.x == dest.x && orig.y == dest.y))
	{
		line.e2 = 2 * line.e1;
		if (line.e2 >= line.dy)
		{
			line.e1 += line.dy;
			orig.x += line.sx;
		}
		if (line.e2 <= line.dx)
		{
			line.e1 += line.dx;
			orig.y += line.sy;
		}
		mlx_pixel_put(mlx_ptr, win_ptr, orig.x, orig.y, 0xFFFFFF);
	}
}
