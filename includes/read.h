/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:19:32 by bcastro           #+#    #+#             */
/*   Updated: 2019/05/20 15:22:17 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
#define READ_H
#include "fdf.h"

int get_arr_len(char *line);
void get_content(int fd, char **map_arr, int *length, int *width);
int **create_map(int cols, int rows);
void populate_map(int ***map, char *content, int x, int y);
int **get_map(char *file_name, int *x, int *y);

#endif