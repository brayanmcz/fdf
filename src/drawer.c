/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 20:26:38 by bcastro           #+#    #+#             */
/*   Updated: 2019/05/21 15:28:06 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void draw_line(t_point orig, t_point dest, void *mlx_ptr, void *win_ptr)
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

void show_cols(t_fdf fdf, int col, int row)
{
	fdf.orig.x = (col * fdf.camera.zoom);
	fdf.orig.y = (row * fdf.camera.zoom);
	fdf.orig.z = -1 * fdf.map[row][col] * fdf.camera.zoom;

	fdf.dest.x = ((col - 1) * fdf.camera.zoom);
	fdf.dest.y = (row * fdf.camera.zoom);
	fdf.dest.z = -1 * fdf.map[row][col - 1] * fdf.camera.zoom;

	if (fdf.camera.projection == ISO)
	{
		fdf.orig = iso_axis_rotation(fdf.orig);
		fdf.dest = iso_axis_rotation(fdf.dest);
	}
	else
	{
		fdf.orig = rotate(fdf.orig,
											fdf.camera.x_rot,
											fdf.camera.y_rot,
											fdf.camera.z_rot);
		fdf.dest = rotate(fdf.dest,
											fdf.camera.x_rot,
											fdf.camera.y_rot,
											fdf.camera.z_rot);
	}

	draw_line(fdf.orig, fdf.dest, fdf.mlx_ptr, fdf.win_ptr);
}

void show_rows(t_fdf fdf, int col, int row)
{
	fdf.orig.x = (col * fdf.camera.zoom);
	fdf.orig.y = (row * fdf.camera.zoom);
	fdf.orig.z = -1 * fdf.map[row][col] * fdf.camera.zoom;

	fdf.dest.x = (col * fdf.camera.zoom);
	fdf.dest.y = ((row - 1) * fdf.camera.zoom);
	fdf.dest.z = -1 * fdf.map[row - 1][col] * fdf.camera.zoom;

	if (fdf.camera.projection == ISO)
	{
		fdf.orig = iso_axis_rotation(fdf.orig);
		fdf.dest = iso_axis_rotation(fdf.dest);
	}
	else
	{
		fdf.orig = rotate(fdf.orig,
											fdf.camera.x_rot,
											fdf.camera.y_rot,
											fdf.camera.z_rot);
		fdf.dest = rotate(fdf.dest,
											fdf.camera.x_rot,
											fdf.camera.y_rot,
											fdf.camera.z_rot);
	}
	draw_line(fdf.dest, fdf.orig, fdf.mlx_ptr, fdf.win_ptr);
}

void show_map(t_fdf fdf, int col, int row)
{
	int col_origin = col;
	int row_origin = row;

	while (row >= 0)
	{
		col = col_origin;
		while (col - 1 >= 0)
		{
			show_cols(fdf, col, row);

			col--;
		}
		row--;
	}

	col = col_origin;
	row = row_origin;

	while (row - 1 >= 0)
	{
		col = col_origin;
		while (col >= 0)
		{
			show_rows(fdf, col, row);
			col--;
		}
		free(fdf.map[row]);
		row--;
	}
	free(fdf.map[row]);
	free(fdf.map);
	mlx_loop(fdf.mlx_ptr);
}
