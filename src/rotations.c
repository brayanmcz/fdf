/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:53:18 by bcastro           #+#    #+#             */
/*   Updated: 2019/05/19 13:48:21 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

/*
** Rotations for a point in 3D space
*/

double deg_to_rad(int deg)
{
	double rad;

	rad = deg * (M_PI / 180);
	return (rad);
}

t_point rotate(t_point point, int x, int y, int z)
{
	point = x_axis_rotation(point, deg_to_rad(x));
	point = y_axis_rotation(point, deg_to_rad(y));
	point = z_axis_rotation(point, deg_to_rad(z));
	return (point);
}

t_point x_axis_rotation(t_point point, double rad)
{
	t_point new_point;

	new_point.x = point.x;
	new_point.y = point.y * cos(rad) + point.z * sin(rad);
	new_point.z = -point.y * sin(rad) + point.z * cos(rad);
	return (new_point);
}

t_point y_axis_rotation(t_point point, double rad)
{
	t_point new_point;

	new_point.x = point.x * cos(rad) + point.z * sin(rad);
	new_point.y = point.y;
	new_point.z = -point.x * sin(rad) + point.z * cos(rad);
	return (new_point);
}

t_point z_axis_rotation(t_point point, double rad)
{
	t_point new_point;

	new_point.x = point.x * cos(rad) - point.y * sin(rad);
	new_point.y = point.x * sin(rad) + point.y * cos(rad);
	new_point.z = point.z;

	return (new_point);
}