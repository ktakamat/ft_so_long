/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:11:59 by ktakamat          #+#    #+#             */
/*   Updated: 2024/03/30 20:44:44 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_key(int key_code, t_map *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	if (key_code == KEY_W)
		move_w(game);
	if (key_code == KEY_A)
		move_a(game);
	if (key_code == KEY_S)
		move_s(game);
	if (key_code == KEY_D)
		move_d(game);
	return(0);
}

void	move_w(t_map *g)
{
	int	i;

	i = 0;
	while(i++ < ft_strlen(g->str_line))
	{
		if(g->str_line[i] == 'P')
			break;
	}
	if(g->str_line[i - g->width] == 'C')
		g->col_cnt++;
	if(g->str_line[i - g->width] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if(g->str_line[i - g->width] != '1' && g->str_line[i - g->width] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - g->width] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}

void	move
