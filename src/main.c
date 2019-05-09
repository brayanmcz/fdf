/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:17:14 by bcastro           #+#    #+#             */
/*   Updated: 2019/05/08 18:16:08 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int		main(int argc, char **argv)
{
	int		file_desc;
	char	*file_str;
	int		ret;

	file_desc = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(file_desc, &file_str)) == 1)
	{
		printf("%s\n", file_str);
	}
	if (ret == -1)
		printf("ERROR: There was an error reading your file.\n");
	return (0);
}

// int main(int argc, char **argv)
// {
//   if (argc == 2)
//   {
//     fdf(argv[1]);
//   }

//   // void *mlx_ptr;
//   // void *win_ptr;
//   // mlx_ptr = mlx_init();
//   // win_ptr = mlx_new_window(mlx_ptr, 500, 500 + 1, "mlx 42");
//   // mlx_loop(mlx_ptr);
//   return (0);
// }
