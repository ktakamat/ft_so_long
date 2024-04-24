/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:09:07 by ktakamat          #+#    #+#             */
/*   Updated: 2024/04/24 20:05:40 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_ma			ma;
	int				img_width;
	int				img_height;
	t_game			game;
	const char		*filename;

	filename = av[1];
	ft_memset(&game, 0, sizeof(t_game));
	map_read(av[1], &game);
	check1(filename, &game);
	ma.mlx = mlx_init();
	ma.win = mlx_new_window(ma.mlx, 50 * game.wid, 50 * game.hei, "my_mlx");
	init_textures(ma.mlx, &game, &img_width, &img_height);
	game.mlx.m_ptr = ma.mlx;
	game.mlx.w_ptr = ma.win;
	mlx_key_hook(ma.win, &press_key, &game);
	mlx_loop_hook(ma.mlx, setting_img, &game);
	mlx_hook(ma.win, 17, 0, close_window, &game);
	(void)ac;
	setting_img(&game);
	mlx_loop(ma.mlx);
	return (0);
}

void	init_textures(void *mlx, t_game *game, int *img_width, int *img_height)
{
	*img_width = 0;
	*img_height = 0;
	game->img.land = mlx_xpm_file_to_image(mlx, "./textures/land.xpm",
			img_width, img_height);
	game->img.wall = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm",
			img_width, img_height);
	game->img.chara = mlx_xpm_file_to_image(mlx, "./textures/chara.xpm",
			img_width, img_height);
	game->img.chest = mlx_xpm_file_to_image(mlx, "./textures/chest.xpm",
			img_width, img_height);
	game->img.chest_open = mlx_xpm_file_to_image(mlx,
			"./textures/chest_open.xpm", img_width, img_height);
	game->img.rune = mlx_xpm_file_to_image(mlx, "./textures/rune.xpm",
			img_width, img_height);
	game->img.runl = mlx_xpm_file_to_image(mlx, "./textures/rune_light.xpm",
			img_width, img_height);
}

bool	check1(const char *filename, t_game *game)
{
	if (!have_ber(filename))
		ft_exit();
	map_limit(game);
	last_line(game);
	num_chara_goal(game);
	no_item(game);
	check_first_line(game);
	check_map_edges(game);
	game->all_col = count_coin(game);
	if (!reach_e(game) || !reach_c(game))
		ft_exit();
	return (true);
}

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free(game->str_line);
	exit(0);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q so_long");
// }