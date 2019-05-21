/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:06:24 by bcastro           #+#    #+#             */
/*   Updated: 2019/05/21 16:03:04 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_arr_len(char *line)
{
	int		len;
	int		i;
	char	**arr;

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

void	get_content(int fd, char **map_arr, int *length, int *width)
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
		temp = ft_strjoin(line, " ");
		file_content = ft_strjoin(file_content, temp);
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

int		**create_map(int cols, int rows)
{
	int	i;
	int	**map;

	i = 0;
	map = (int **)malloc((rows) * sizeof(int *));
	while (i < rows)
		map[i++] = (int *)malloc(cols * sizeof(int));
	return (map);
}

void	populate_map(int ***map, char *content, int x, int y)
{
	int		x_iter;
	int		y_iter;
	int		m_iter;
	char	**map_content;
	char	*temp;

	x_iter = 0;
	y_iter = 0;
	m_iter = 0;
	temp = ft_strjoin(content, "\0");
	map_content = ft_strsplit(temp, ' ');
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

int		**get_map(char *file_name, int *x, int *y)
{
	int		fd;
	int		x_len;
	int		y_len;
	int		**map;
	char	*file_content;

	fd = safe_open(file_name);
	get_content(fd, &file_content, &x_len, &y_len);
	map = create_map(x_len, y_len);
	populate_map(&map, file_content, x_len, y_len);
	*x = x_len;
	*y = y_len;
	return (map);
}
