/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 18:03:42 by bcastro           #+#    #+#             */
/*   Updated: 2019/05/19 20:31:16 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATIONS_H
# define ROTATIONS_H
# include "fdf.h"

double	deg_to_rad(int deg);
t_point	iso_axis_rotation(t_point point);
t_point rotate(t_point point, int x, int y, int z);
t_point x_axis_rotation(t_point point, double rad);
t_point y_axis_rotation(t_point point, double rad);
t_point z_axis_rotation(t_point point, double rad);

#endif
