/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:56:39 by brayan            #+#    #+#             */
/*   Updated: 2019/05/16 20:19:06 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

// Bresenham Line Algorithm
void	line(t_point orig, t_point dest, void *mlx_ptr, void *win_ptr)
{
	int dx; 	//The difference between x1 and x0
	int dy; 	//The difference between y1 and y0
	int sx; 	//Is the line rising/horizontal or falling/vertical
	int sy;		//Is the line rising/horizontal or falling/vertical
	int err;	//The amount of err from line is to center of pixel

	dx = abs(dest.x - orig.x);
	dy = abs(dest.y - orig.y);
	sx = orig.x < dest.x ? 1 : -1;
	sy = orig.y < dest.y ? 1 : -1;
	err = (dx>dy ? dx : -dy) / 2;
	while(orig.x!=dest.x || orig.y!=dest.y) //While the current pixel has not met the ending pixel
	{
		mlx_pixel_put(mlx_ptr, win_ptr, orig.x, orig.y, 0xFFFFFF); //Place a pixel on the screen
		if (2 * err > -dx)  //Determine if you should advance to the next pixel horizontally
		{
			err -= dy;
			orig.x += sx;
		}
		if (2 * err < dy)   //Determine if you should advance to the next pixel vertically
		{
			err += dx;
			orig.y += sy;
		}
	}
}

int safe_open(char *file){
	int fd;
	
	fd = open(file, O_RDONLY);
	if (fd == -1){
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
		i++;
		len++;
	}

	return (len);
}

// Return the whole file as a single line
void	get_content(int fd, char **map_arr, int *length, int *width){	
	int		ret;
	char	*line;
	char 	*file_content;
	char 	*tmp;
	int len;
	int wth;

	wth = 0;
	file_content = ft_strnew(0);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		wth++;
		len = get_arr_len(line);
		tmp = file_content;
		file_content = ft_strjoin(file_content, ft_strjoin(line, " "));
		ft_strdel(&tmp);
	}
	if (ret == -1){
		perror("read");
		exit(ret);
	}
	*map_arr = file_content;
	*length = len;
	*width = wth;
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

//THERE IS SOMETHING WRONG HERE>
void populate_map(int ***map, char *content, int x, int y)
{
	int x_iter = 0;
	int y_iter = 0;
	int m_iter = 0;
	char **map_content;

	map_content = ft_strsplit(ft_strjoin(content, "\0"), ' ');
	
	while (y_iter < y)
	{
		x_iter = 0;
		while (x_iter < x)
		{
			(*map)[y_iter][x_iter] = ft_atoi(map_content[m_iter++]);
			x_iter++;
		}
		y_iter++;
	}
}


int **get_map(char *file_name, int *x, int *y)
{
	int		fd;
	int		x_len;
	int		y_len;
	int 	**map;
	char 	*file_content;

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
	size_mult = 20;
	
	double theta_x = 0 * M_PI;
	double theta_y = 0 * M_PI;
	double theta_z = 0 * M_PI;

	void *mlx_ptr;
  void *win_ptr;
  mlx_ptr = mlx_init();
  win_ptr = mlx_new_window(mlx_ptr, 1000, 500, "fdf");

	t_point orig;
	t_point dest;

	col--;
	row--;

	int col_origin = col;
	int row_origin = row;

	while (col - 1 >= 0)
	{
		row = row_origin;
		while(row >= 0)
		{
			orig.x = (col * size_mult);
			orig.y = (row * size_mult);
			orig.z = -1 * map[row][col] * size_mult;

			dest.x =((col - 1) * size_mult);
			dest.y = (row * size_mult);
			dest.z = -1 * map[row][col - 1] * size_mult;	

			orig = x_axis_rotation(orig, theta_x);
			orig = y_axis_rotation(orig, theta_y);
			orig = z_axis_rotation(orig, theta_z);

			dest = x_axis_rotation(dest, theta_x);
			dest = y_axis_rotation(dest, theta_y);
			dest = z_axis_rotation(dest, theta_z);

			orig.x+=200;
			orig.y+=200;
			dest.x+=200;
			dest.y+=200;
			
			line (orig, dest, mlx_ptr, win_ptr);
			row--;
		}
		col--;
	}

	col = col_origin;
	row = row_origin;

	while (col >= 0)
	{
		row = row_origin;
		while(row - 1 >= 0)
		{
			orig.x = (col * size_mult);
			orig.y = (row * size_mult);
			orig.z = -1 * map[row][col] * size_mult;

			dest.x =(col * size_mult);
			dest.y = ((row - 1) * size_mult);
			dest.z = -1 * map[row - 1][col] * size_mult;

			orig = x_axis_rotation(orig, theta_x);
			orig = y_axis_rotation(orig, theta_y);
			orig = z_axis_rotation(orig, theta_z);

			dest = x_axis_rotation(dest, theta_x);
			dest = y_axis_rotation(dest, theta_y);
			dest = z_axis_rotation(dest, theta_z);

			orig.x+=200;
			orig.y+=200;
			dest.x+=200;
			dest.y+=200;
			
			line (orig, dest, mlx_ptr, win_ptr);
			row--;
		}
		col--;
	}
	mlx_loop(mlx_ptr);
}

void	fdf(char *file_name)
{
	int **map;
	int x;
	int y;
	map = get_map(file_name, &x, &y);
	show_map(map, x, y);
}