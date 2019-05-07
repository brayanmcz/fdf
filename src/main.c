/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brayan <brayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:17:14 by bcastro           #+#    #+#             */
/*   Updated: 2019/05/06 18:59:37 by brayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx/mlx.h"
#include "stdlib.h"

//Bad Code Monkey, no global variables!
//TODO: change this to be inside a function
void *mlx_ptr;
void *win_ptr;

// Bresenham Line Drawing Algorithm
// TODO: Change corresponding x and y values 
// into a struct that contains the two points
void line(int x0, int y0, int x1, int y1) {
 
  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;
 
  while(1){
    mlx_pixel_put(mlx_ptr,win_ptr,x0, y0,0xFFFFFF);
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}

int main()
{
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500 + 1, "mlx 42");

	line(150,250,350,250); //Horizonal
	line(250,150,250,350); //Vertical
	line(150,350,450,150); //Rising
	line(50,50,250,450); //Falling

	mlx_loop(mlx_ptr);

	return (0);
}
