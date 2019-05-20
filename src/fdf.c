/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:56:39 by brayan            #+#    #+#             */
/*   Updated: 2019/05/19 23:27:38 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int safe_open(char *file)
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

// Get the x length of the map
int get_arr_len(char *line)
{
	int len;
	int i;
	char **arr;

	arr = ft_strsplit(line, ' ');

	i = 0;
	len = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
		len++;
	}
	free(arr);

	return (len);
}

void get_content(int fd, char **map_arr, int *length, int *width)
{
	int		ret;
	char	*line;
	char	*file_content;
	char	*tmp;
	char	*temp;

	*width = 0;
	file_content = ft_strnew(0);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		*width = *width + 1;
		*length = get_arr_len(line);
		tmp = file_content;
		file_content = ft_strjoin(file_content, temp = ft_strjoin(line, " "));
		ft_strdel(&line);
		ft_strdel(&tmp);
		ft_strdel(&temp);
	}
	if (ret == -1)
	{
		perror("read");
		exit(ret);
	}
	*map_arr = file_content;
}

int **create_map(int cols, int rows)
{
	int i = 0;
	int **map;
	map = (int **)malloc((rows) * sizeof(int *));
	while (i < rows)
		map[i++] = (int *)malloc(cols * sizeof(int));

	return (map);
}

void populate_map(int ***map, char *content, int x, int y)
{
	int x_iter = 0;
	int y_iter = 0;
	int m_iter = 0;
	char **map_content;
	char *temp;

	map_content = ft_strsplit(temp = ft_strjoin(content, "\0"), ' ');
	free(temp);
	while (y_iter < y)
	{
		x_iter = 0;
		while (x_iter < x)
		{
			(*map)[y_iter][x_iter++] = ft_atoi(map_content[m_iter]);
			free(map_content[m_iter]);
			m_iter++;
		}
		y_iter++;
	}

	free(map_content);
	free(content);
}

int **get_map(char *file_name, int *x, int *y)
{
	int fd;
	int x_len;
	int y_len;
	int **map;
	char *file_content;

	fd = safe_open(file_name);
	get_content(fd, &file_content, &x_len, &y_len);
	map = create_map(x_len, y_len);
	populate_map(&map, file_content, x_len, y_len);

	*x = x_len;
	*y = y_len;
	return (map);
}

void show_map(int **map, int col, int row)
{
	int size_mult;
	size_mult = 2;

	int rx, ry, rz;
	rx = 0;
	ry = 0;
	rz = 45;

	void *mlx_ptr;
	void *win_ptr;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf");

	t_point orig;
	t_point dest;

	col--;
	row--;

	int col_origin = col;
	int row_origin = row;

	while (col - 1 >= 0)
	{
		row = row_origin;
		while (row >= 0)
		{

			orig.x = (col * size_mult);
			orig.y = (row * size_mult);
			orig.z = -1 * map[row][col] * size_mult;

			dest.x = ((col - 1) * size_mult);
			dest.y = (row * size_mult);
			dest.z = -1 * map[row][col - 1] * size_mult;

			orig = iso_axis_rotation(orig);
			dest = iso_axis_rotation(dest);

			// orig.x += 10;
			// orig.y += 350;
			// dest.x += 10;
			// dest.y += 350;

			line(orig, dest, mlx_ptr, win_ptr);

			row--;
		}
		col--;
	}

	col = col_origin;
	row = row_origin;

	while (row - 1 >= 0)
	{
		col = col_origin;
		while (col >= 0)
		{
			orig.x = (col * size_mult);
			orig.y = (row * size_mult);
			orig.z = -1 * map[row][col] * size_mult;

			dest.x = (col * size_mult);
			dest.y = ((row - 1) * size_mult);
			dest.z = -1 * map[row - 1][col] * size_mult;

			orig = iso_axis_rotation(orig);
			dest = iso_axis_rotation(dest);

			// orig.x += 10;
			// orig.y += 350;
			// dest.x += 10;
			// dest.y += 350;

			line(dest, orig, mlx_ptr, win_ptr);
			col--;
		}
		free(map[row]);
		row--;
	}
	free(map[row]);
	free(map);
	mlx_loop(mlx_ptr);
}

void fdf(char *file_name)
{
	int **map;
	int x;
	int y;
	map = get_map(file_name, &x, &y);
	show_map(map, x, y);
}