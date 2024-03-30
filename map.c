/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:39:06 by ktakamat          #+#    #+#             */
/*   Updated: 2024/03/30 19:57:59 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void map_read(char *filename, t_map *game)
{
	int	fd;
	char *line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->str_line = ft_strdup(line);
	free(line);
	while(line)
	{
		game->height++;
		line = ge_next_line(fd);
		if(line)
		{
			game->str_line = ft_strjoin(game->str_line, line);
		}
	}
	close(fd);
	printf("%s\n", game->str_line);
}

void	setting_img(t_map game)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < game.height)
	{
		wid = 0;
		while (wid < game.width)
		{
			if (game.str_line[hei * game.width + wid] == '1')
			{
				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.wall, wid * 64, hei * 64);
			}
			else if (game.str_line[hei * game.width + wid] == 'C')
			{
				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.chest, wid * 64, hei * 64);
			}
			else if (game.str_line[hei * game.width + wid] == 'P')
			{
				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.chara, wid * 64, hei * 64);
			}
			else if (game.str_line[hei * game.width + wid] == 'E')
			{
				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.rune, wid * 64, hei * 64);
			}
			else
			{
				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.land, wid * 64, hei * 64);
			}
			wid++;
		}
		hei++;
	}
}
