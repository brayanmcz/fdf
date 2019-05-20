/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:11:06 by brayan            #+#    #+#             */
/*   Updated: 2019/05/19 22:09:22 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../includes/drawer.h"
# include "../includes/rotations.h"
# include "stdlib.h"
# include "stdio.h" //DELETE THIS before project submitted
# include "unistd.h"
# include "math.h"

typedef struct s_fdf
{
    void *mlx_ptr;
}              t_fdf;


void fdf(char *file_name);

#endif
