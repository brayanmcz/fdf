/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:56:39 by brayan            #+#    #+#             */
/*   Updated: 2019/05/22 18:33:58 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		safe_open(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(fd);
	}
	return (fd);
}

int		safe_close(int param)
{
	(void)param;
	exit(0);
	return (param);
}

int		key_pressed(int key)
{
	if (key == 53)
		safe_close(0);
	return (key);
}

void	fdf(char *file_name)
{
	t_fdf	fdf;
	int		x;
	int		y;

	fdf.map = get_map(file_name, &x, &y);
	fdf.camera.x_rot = 90;
	fdf.camera.y_rot = 64;
	fdf.camera.z_rot = 0;
	fdf.camera.zoom = 20;
	fdf.camera.projection = ISO;
	fdf.camera.x_offset = 10;
	fdf.camera.y_offset = 350;
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 500, 500, "fdf");
	show_map(fdf, x - 1, y - 1);
	mlx_loop(fdf.mlx_ptr);

}
