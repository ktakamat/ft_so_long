/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:12:23 by machi             #+#    #+#             */
/*   Updated: 2024/04/25 18:59:34 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	num_chara_goal(t_game *game)
{
	int		p_count;
	int		e_count;
	size_t	hei;
	size_t	wid;

	p_count = 0;
	e_count = 0;
	hei = 0;
	while (hei < game->hei)
	{
		wid = 0;
		while (wid < game->wid)
		{
			if (game->str_line[hei * game->wid + wid] == 'P')
				p_count++;
			else if (game->str_line[hei * game->wid + wid] == 'E')
				e_count++;
			wid++;
		}
		hei++;
	}
	if (p_count == 0 || p_count > 1 || e_count == 0 || e_count > 1)
		ft_exit();
}

void	no_item(t_game *game)
{
	int		c_count;
	size_t	hei;
	size_t	wid;

	c_count = 0;
	hei = 0;
	while (hei < game->hei)
	{
		wid = 0;
		while (wid < game->wid)
		{
			if (game->str_line[hei * game->wid + wid] == 'C')
				c_count++;
			wid++;
		}
		hei++;
	}
	if (c_count == 0)
		ft_exit();
}

void	last_line(t_game *game)
{
	t_last	last;

	last.index = game->hei - 1;
	last.expected_width = game->wid;
	last.last_width = 0;
	last.i = last.index * game->wid;
	while (game->str_line[last.i] != '\0')
	{
		last.last_width++;
		last.i++;
	}
	if (last.last_width != last.expected_width)
		ft_exit();
	last.last_line_start = &(game->str_line[last.index * game->wid]);
	last.last_line_end = last.last_line_start + last.expected_width;
	last.ptr = last.last_line_start;
	while (last.ptr < last.last_line_end)
	{
		if (*last.ptr != '1')
			ft_exit();
		last.ptr++;
	}
}

void	ft_exit(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
