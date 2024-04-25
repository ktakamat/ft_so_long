/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:47:38 by ktakamat          #+#    #+#             */
/*   Updated: 2024/04/25 19:56:00 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	have_ber(const char *filename)
{
	const char	*ext;

	ext = ft_strrchr(filename, '.');
	if (ext != NULL && ft_strcmp(ext, FILE_EXTENSION) == 0)
		return (true);
	return (false);
}

void	map_word(char *map_str)
{
	if (!map_str)
		return ;
	while (*map_str && map_str)
	{
		if (*map_str == '\n')
			return ;
		if (*map_str != '1' && *map_str != 'C'
			&& *map_str != 'P' && *map_str != 'E'
			&& *map_str != '0' && *map_str != '\n')
			ft_exit();
		map_str++;
	}
}

void	check_map_edges(t_game *game)
{
	char	*left_ptr;
	char	*right_ptr;
	size_t	row;

	left_ptr = game->str_line;
	right_ptr = game->str_line + game->wid - 1;
	row = 0;
	while (row < game->hei)
	{
		if (*left_ptr != '1')
			ft_exit();
		left_ptr += game->wid;
		row++;
	}
	row = 0;
	while (row < game->hei)
	{
		if (*right_ptr != '1')
			ft_exit();
		right_ptr += game->wid;
		row++;
	}
}

size_t	count_coin(t_game *game)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	while (game->str_line[index] != '\0')
	{
		if (game->str_line[index] == 'C')
			count++;
		index++;
	}
	return (count);
}

void	map_limit(t_game *game)
{
	if (game->hei >= MAX_HEI || game->wid >= MAX_WID)
		ft_exit();
}
