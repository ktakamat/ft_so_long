/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:12:23 by machi             #+#    #+#             */
/*   Updated: 2024/04/17 16:15:20 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	num_chara_goal(t_game *game)
{
	int	p_count = 0;
	int	e_count = 0;
	size_t	hei = 0;

	while (hei < game->hei)
	{
		size_t	wid = 0;
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
	int	c_count = 0;
	size_t hei = 0;

	while (hei < game->hei)
	{
		size_t wid = 0;
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
	size_t	index = game->hei - 1;
	size_t	expected_width = game->wid;
	size_t	last_width = 0;
	size_t	i = index * game->wid;

	while(game->str_line[i] != '\0')
	{
		last_width++;
		i++;
	}
	if (last_width != expected_width)
		ft_exit();
	char	*last_line_start = &(game->str_line[index * game->wid]);
	char	*last_line_end = last_line_start + expected_width;
	char	*ptr = last_line_start;

	while	(ptr < last_line_end)
	{
		if (*ptr != '1')
			ft_exit();
		ptr++;
	}
}

void	ft_exit(void)
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}
