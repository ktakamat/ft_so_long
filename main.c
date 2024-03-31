/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:09:07 by ktakamat          #+#    #+#             */
/*   Updated: 2024/03/31 17:29:08 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	// void *mlx;
	// void *win;
	// void *img;
	// void *img2;
	// void *img3;
	// void *img4;
	// void *img5;
	// void *img6;
	// void *img7;
	// int img_width;
	// int img_height;

	// mlx = mlx_init();
	
	// win = mlx_new_window(mlx, 500, 500, "my_mlx");
	// img = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &img_width, &img_height);
	// img2 = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	// img3 = mlx_xpm_file_to_image(mlx, "./images/chara.xpm", &img_width, &img_height);
	// img4 = mlx_xpm_file_to_image(mlx, "./images/chest.xpm", &img_width, &img_height);
	// img6 = mlx_xpm_file_to_image(mlx, "./images/rune.xpm", &img_width, &img_height);
	// img7 = mlx_xpm_file_to_image(mlx, "./images/rune_light.xpm", &img_width, &img_height);
	t_game game;
	// mlx_loop(mlx);
	printf("filename = [%s]\n", av[1]);
	map_read(av[1], &game);

	(void)ac;
	// (void)img5;
	return (0);
}