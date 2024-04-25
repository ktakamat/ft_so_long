/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:39:06 by ktakamat          #+#    #+#             */
/*   Updated: 2024/04/25 19:55:41 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_new(char *s1, const char *s2)
{
	char	*a;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = (char *)ft_calloc(sizeof(*a), (len_s1 + len_s2) + 1);
	if (a == NULL)
		ft_exit();
	ft_strlcpy(a, s1, len_s1 + 1);
	ft_strlcat(a, s2, len_s1 + len_s2 + 1);
	if (a[len_s1 + len_s2 - 1] == '\n')
		a[len_s1 + len_s2 - 1] = '\0';
	free(s1);
	s1 = NULL;
	return (a);
}

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	game->error_item = 0;
	line = get_next_line(fd);
	if (line == NULL || *line == '\0' || *line == '\n')
		ft_exit();
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	game->hei = 0;
	game->wid = ft_strlen(line);
	game->str_line = ft_strdup(line);
	free(line);
	while (line)
	{
		game->hei++;
		line = get_next_line(fd);
		map_word(line);
		if (line)
			game->str_line = ft_strjoin_new(game->str_line, line);
		free(line);
	}
	close(fd);
}

void	put_img(t_game *game, char alpha, size_t x, size_t y)
{
	if (alpha == '1')
		mlx_put_image_to_window(game->mlx.m_ptr, game->mlx.w_ptr,
			game->img.wall, x * 50, y * 50);
	else if (alpha == 'C')
		mlx_put_image_to_window(game->mlx.m_ptr,
			game->mlx.w_ptr, game->img.chest, x * 50, y * 50);
	else if (alpha == 'P')
		mlx_put_image_to_window(game->mlx.m_ptr, game->mlx.w_ptr,
			game->img.chara, x * 50, y * 50);
	else if (alpha == 'E')
		mlx_put_image_to_window(game->mlx.m_ptr, game->mlx.w_ptr,
			game->img.rune, x * 50, y * 50);
	else
		mlx_put_image_to_window(game->mlx.m_ptr, game->mlx.w_ptr,
			game->img.land, x * 50, y * 50);
}

int	setting_img(t_game *game)
{
	size_t	hei;
	size_t	wid;
	char	alpha;

	hei = 0;
	while (hei < game->hei)
	{
		wid = 0;
		while (wid < game->wid)
		{
			alpha = game->str_line[hei * game->wid + wid];
			put_img(game, alpha, wid, hei);
			wid++;
		}
		hei++;
	}
	return (0);
}
