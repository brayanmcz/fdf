/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:17:14 by bcastro           #+#    #+#             */
/*   Updated: 2019/04/29 15:51:29 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx/mlx.h"

int main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");

	for (int i = 0; i < 50; i++){
		for (int j = 0; i < 50; i++){
	        mlx_pixel_put(mlx_ptr, win_ptr, i + 250, i + 250, 0xFFFFFF);
		}
	}

	mlx_loop(mlx_ptr);

	return (0);
}
