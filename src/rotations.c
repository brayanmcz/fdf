/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:53:18 by bcastro           #+#    #+#             */
/*   Updated: 2019/05/16 20:19:46 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

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