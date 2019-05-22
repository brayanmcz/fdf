/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:11:06 by brayan            #+#    #+#             */
/*   Updated: 2019/05/22 16:19:34 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "stdlib.h"
# include "unistd.h"
# include "math.h"
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "drawer.h"
# include "rotations.h"
# include "read.h"

void	fdf(char *file_name);
int		safe_open(char *file);
int safe_close(int param);

#endif
