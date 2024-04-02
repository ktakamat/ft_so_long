/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machi <machi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:09:07 by ktakamat          #+#    #+#             */
/*   Updated: 2024/04/01 17:02:44 by machi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	void *mlx;
	void *win;
	int img_width;
	int img_height;
	t_game game;

	ft_memset(&game, 0, sizeof(t_game));
	map_read(av[1], &game);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 50 * game.wid, 50 * game.hei, "my_mlx");
	game.img.land = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &img_width, &img_height);
	game.img.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	game.img.chara = mlx_xpm_file_to_image(mlx, "./images/chara.xpm", &img_width, &img_height);
	game.img.chest = mlx_xpm_file_to_image(mlx, "./images/chest.xpm", &img_width, &img_height);
	game.img.chest_open = mlx_xpm_file_to_image(mlx, "./images/chest_open.xpm", &img_width, &img_height);
	game.img.rune = mlx_xpm_file_to_image(mlx, "./images/rune.xpm", &img_width, &img_height);
	game.img.runl = mlx_xpm_file_to_image(mlx, "./images/rune_light.xpm", &img_width, &img_height);
	game.mlx.m_ptr = mlx;
	game.mlx.w_ptr = win;
	mlx_key_hook(win, &press_key, &game);
	(void)ac;
	setting_img(game);
	game.all_col = 1;
	mlx_loop(mlx);
	return (0);
}
