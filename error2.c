/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:47:38 by ktakamat          #+#    #+#             */
/*   Updated: 2024/04/17 16:12:54 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	have_ber(const char *filename)
{
	const char	*ext = ft_strrchr(filename, '.');
	if (ext != NULL && strcmp(ext, FILE_EXTENSION) == 0)
		return (true);
	return (false);
}

void	map_word(char *map_str)
{
	while(*map_str && map_str)
	{
	if (*map_str == '\n')
			return ;
		if (*map_str != '1' && *map_str != 'C' && *map_str != 'P' && *map_str != 'E'
			&& *map_str != '0' && *map_str != '\n')
			ft_exit();
		map_str++;
	}
}

void check_map_edges(t_game *game)
{
	char *left_ptr = game->str_line;
	char *right_ptr = game->str_line + game->wid - 1;

	size_t row = 0;
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
