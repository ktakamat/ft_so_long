/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:09:07 by ktakamat          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/16 22:24:50 by ktakamat         ###   ########.fr       */
=======
/*   Updated: 2024/04/16 15:47:47 by ktakamat         ###   ########.fr       */
>>>>>>> cf47c4f27049ff3f1c4520879c61bcd9881e6c5f
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

// int main(int ac, char **av)
// {
// 	void *mlx;
// 	void *win;
// 	int img_width;
// 	int img_height;
// 	t_game game;
// 	const char	*filename = av[1];

// 	ft_memset(&game, 0, sizeof(t_game));
// 	map_read(av[1], &game);
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 50 * game.wid, 50 * game.hei, "my_mlx");
// 	game.img.land = mlx_xpm_file_to_image(mlx, "./textures/land.xpm", &img_width, &img_height);
// 	game.img.wall = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &img_width, &img_height);
// 	game.img.chara = mlx_xpm_file_to_image(mlx, "./textures/chara.xpm", &img_width, &img_height);
// 	game.img.chest = mlx_xpm_file_to_image(mlx, "./textures/chest.xpm", &img_width, &img_height);
// 	game.img.chest_open = mlx_xpm_file_to_image(mlx, "./textures/chest_open.xpm", &img_width, &img_height);
// 	game.img.rune = mlx_xpm_file_to_image(mlx, "./textures/rune.xpm", &img_width, &img_height);
// 	game.img.runl = mlx_xpm_file_to_image(mlx, "./textures/rune_light.xpm", &img_width, &img_height);
// 	game.mlx.m_ptr = mlx;
// 	game.mlx.w_ptr = win;
// 	mlx_key_hook(win, &press_key, &game);
// 	(void)ac;
// 	if(!have_ber(filename))
// 		ft_exit();
// 	setting_img(game);
// 	printf("%zu\n", count_coin(&game));
// 	game.all_col = count_coin(&game);
// 	if (!reach_E(&game))
// 		ft_exit();
// 	if (!reach_c(&game))
// 		ft_exit();
// 	check_first_line(&game);
// 	num_chara_goal(&game);
// 	no_item(&game);
// 	last_line(&game);
// 	mlx_loop(mlx);
// 	return (0);
// } 



int main(int ac, char **av)
{
	void *mlx;
	void *win;
	int img_width;
	int img_height;
	t_game game;
	const char	*filename = av[1];

	ft_memset(&game, 0, sizeof(t_game));
	map_read(av[1], &game);
	check1(filename, &game);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 50 * game.wid, 50 * game.hei, "my_mlx");
	init_textures(mlx, &game, &img_width, &img_height);
	game.mlx.m_ptr = mlx;
	game.mlx.w_ptr = win;
	mlx_key_hook(win, &press_key, &game);
	(void)ac;
	check2(&game);
	printf("main : game.all_col = [%d]\n", game.all_col);
	mlx_loop(mlx);
	return (0);
} 

void init_textures(void *mlx, t_game *game, int *img_width, int *img_height)
{
    *img_width = 0;
    *img_height = 0;

    game->img.land = mlx_xpm_file_to_image(mlx, "./textures/land.xpm", img_width, img_height);
	game->img.wall = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", img_width, img_height);
	game->img.chara = mlx_xpm_file_to_image(mlx, "./textures/chara.xpm", img_width, img_height);
	game->img.chest = mlx_xpm_file_to_image(mlx, "./textures/chest.xpm", img_width, img_height);
	game->img.chest_open = mlx_xpm_file_to_image(mlx, "./textures/chest_open.xpm", img_width, img_height);
	game->img.rune = mlx_xpm_file_to_image(mlx, "./textures/rune.xpm", img_width, img_height);
	game->img.runl = mlx_xpm_file_to_image(mlx, "./textures/rune_light.xpm", img_width, img_height);
}

bool check1(const char *filename, t_game *game)
{
	if(!have_ber(filename))
		ft_exit();
    last_line(game);
    num_chara_goal(game);
	no_item(game);
    check_first_line(game);
	if (!reach_E(game) || !reach_c(game))
        ft_exit();
	return true;
}

bool check2(t_game *game)
{
    setting_img(game);
    printf("%zu\n", count_coin(game));
    game->all_col = count_coin(game);
	printf("game.all_col = [%d]\n", game->all_col);
    return true;
}
