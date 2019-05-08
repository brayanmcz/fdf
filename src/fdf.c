/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brayan <brayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:56:39 by brayan            #+#    #+#             */
/*   Updated: 2019/05/08 16:52:32 by brayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

// Bresenham Line Algorithm
void line(t_point start, t_point end, void *mlx_ptr, void *win_ptr)
{
  int dx = abs(end.x - start.x);          //The difference between x1 and x0
  int dy = abs(end.y - start.y);          //The difference between y1 and y0

  int sx = start.x < end.x ? 1 : -1;      //Is the line rising/horizontal or falling/vertical
  int sy = start.y < end.y ? 1 : -1;      //Is the line rising/horizontal or falling/vertical

  int err = (dx>dy ? dx : -dy) / 2;       //The amount of error from where the line is to the center of the pixel
 
  while(start.x!=end.x || start.y!=end.y) //While the current pixel has not met the ending pixel
  {
    mlx_pixel_put(mlx_ptr, win_ptr, start.x, start.y, 0xFFFFFF); //Place a pixel on the screen
    
    if (2 * err > -dx)  //Determine if you should advance to the next pixel horizontally          
    { 
      err -= dy; 
      start.x += sx; 
    }
    if (2 * err < dy)   //Determine if you should advance to the next pixel vertically
    { 
      err += dx; 
      start.y += sy; 
    }
  }
}
// END Bresenham Line Algorithm

// FDF Read File
void	fdf(char *file_name)
{


}
// END FDF Read file