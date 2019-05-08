/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brayan <brayan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:17:14 by bcastro           #+#    #+#             */
/*   Updated: 2019/05/08 16:50:54 by brayan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int main(int argc, char **argv)
{
  if (argc == 2)
  {
    fdf(argv[1]);
  }

  // void *mlx_ptr;
  // void *win_ptr;
  // mlx_ptr = mlx_init();
  // win_ptr = mlx_new_window(mlx_ptr, 500, 500 + 1, "mlx 42");
  // mlx_loop(mlx_ptr);
  return (0);
}
