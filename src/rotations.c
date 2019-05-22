/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:53:18 by bcastro           #+#    #+#             */
/*   Updated: 2019/05/22 00:12:14 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Rotations for a point in 3D space
**
** Comments:
*/

t_point		rotate(t_point point, int x, int y, int z)
{
	double x_deg;
	double y_deg;
	double z_deg;

	x_deg = x * (M_PI / 180);
	y_deg = y * (M_PI / 180);
	z_deg = z * (M_PI / 180);
	point = x_axis_rotation(point, x_deg);
	point = y_axis_rotation(point, y_deg);
	point = z_axis_rotation(point, z_deg);
	return (point);
}

t_point		iso_axis_rotation(t_point point)
{
	t_point new_point;

	new_point.x = (point.x + point.y) * cos(0.523599);
	new_point.y = (point.x - point.y) * -sin(0.523599) + point.z;
	return (new_point);
}

t_point		x_axis_rotation(t_point point, double rad)
{
	t_point new_point;

	new_point.x = point.x;
	new_point.y = point.y * cos(rad) + point.z * sin(rad);
	new_point.z = -point.y * sin(rad) + point.z * cos(rad);
	return (new_point);
}

t_point		y_axis_rotation(t_point point, double rad)
{
	t_point new_point;

	new_point.x = point.x * cos(rad) + point.z * sin(rad);
	new_point.y = point.y;
	new_point.z = -point.x * sin(rad) + point.z * cos(rad);
	return (new_point);
}

t_point		z_axis_rotation(t_point point, double rad)
{
	t_point new_point;

	new_point.x = point.x * cos(rad) - point.y * sin(rad);
	new_point.y = point.x * sin(rad) + point.y * cos(rad);
	new_point.z = point.z;
	return (new_point);
}
