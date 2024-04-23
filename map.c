/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:39:06 by ktakamat          #+#    #+#             */
/*   Updated: 2024/04/22 17:10:13 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_new(char const *s1, char const *s2)
{
	char	*a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = (char *)ft_calloc(sizeof(*a), (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (a == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		a[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		a[i] = s2[j];
		i++;
		j++;
	}
	if (a[i - 1] == '\n')
		a[i - 1] = '\0';
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
	}
	close(fd);
	printf("%s\n", game->str_line);
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

void	setting_img(t_game *game)
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
}

void	check_first_line(t_game *game)
{
	size_t	wid;
	char	alpha;

	wid = 0;
	while (wid < game->wid)
	{
		alpha = game->str_line[wid];
		if (alpha != '1' && alpha != 'C' && alpha != 'P' && alpha != 'E')
			ft_exit();
		wid++;
	}
}
