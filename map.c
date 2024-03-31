/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:39:06 by ktakamat          #+#    #+#             */
/*   Updated: 2024/03/31 17:32:32 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"


void map_read(char *filename, t_game *game)
{
	int	fd;
	char *line;

	fd = open(filename, O_RDONLY);
	printf("koko fd = [%d]\n", fd);
	line = get_next_line(fd);
	printf("koko2\n");
	game->hei = 0;
	game->wid = ft_strlen(line) - 1;
	game->str_line = ft_strdup(line);
	printf("%s\n", game->str_line);
	free(line);
	while(line)
	{
		game->hei++;
		line = get_next_line(fd);
		if(line)
		{
			game->str_line = ft_strjoin(game->str_line, line);
		}
	}
	close(fd);
	printf("%s\n", game->str_line);
}

// void	setting_img(t_map game)
// {
// 	int		hei;
// 	int		wid;

// 	hei = 0;
// 	while (hei < game.height)
// 	{
// 		wid = 0;
// 		while (wid < game.width)
// 		{
// 			if (game.str_line[hei * game.width + wid] == '1')
// 			{
// 				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.wall, wid * 64, hei * 64);
// 			}
// 			else if (game.str_line[hei * game.width + wid] == 'C')
// 			{
// 				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.chest, wid * 64, hei * 64);
// 			}
// 			else if (game.str_line[hei * game.width + wid] == 'P')
// 			{
// 				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.chara, wid * 64, hei * 64);
// 			}
// 			else if (game.str_line[hei * game.width + wid] == 'E')
// 			{
// 				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.rune, wid * 64, hei * 64);
// 			}
// 			else
// 			{
// 				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.land, wid * 64, hei * 64);
// 			}
// 			wid++;
// 		}
// 		hei++;
// 	}
// }
