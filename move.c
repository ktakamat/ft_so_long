/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machi <machi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:11:59 by ktakamat          #+#    #+#             */
/*   Updated: 2024/04/01 17:18:04 by machi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx.m_ptr, game->mlx.w_ptr);
	exit(0);
}

int	clear_game(t_game *game)
{
	mlx_destroy_window(game->mlx.m_ptr, game->mlx.w_ptr);
	exit(0);
}

void	move_w(t_game *g)
{
	size_t	i;

	i = 0;
	while(i++ < ft_strlen(g->str_line))
	{
		if(g->str_line[i] == 'P')
			break;
	}
	if(g->str_line[i - g->wid] == 'C')
		g->col_cnt++;
	if(g->str_line[i - g->wid] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if(g->str_line[i - g->wid] != '1' && g->str_line[i - g->wid] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - g->wid] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		setting_img(*g);
	}
}

void	move_s(t_game *g)
{
	size_t	i;

	i = 0;
	while(i++ < ft_strlen(g->str_line))
	{
		if(g->str_line[i] == 'P')
			break;
	}
	if(g->str_line[i + g->wid] == 'C')
		g->col_cnt++;
	if(g->str_line[i + g->wid] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if(g->str_line[i + g->wid] != '1' && g->str_line[i + g->wid] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + g->wid] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		setting_img(*g);
	}
}

void	move_a(t_game *g)
{
	size_t	i;

	i = 0;
	while(i++ < ft_strlen(g->str_line))
	{
		if(g->str_line[i] == 'P')
			break;
	}
	if(g->str_line[i - 1] == 'C')
		g->col_cnt++;
	if(g->str_line[i - 1] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if(g->str_line[i - 1] != '1' && g->str_line[i - 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - 1] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		setting_img(*g);
	}
}

void	move_d(t_game *g)
{
	size_t	i;

	i = 0;
	while(i++ < ft_strlen(g->str_line))
	{
		if(g->str_line[i] == 'P')
			break;
	}
	if(g->str_line[i + 1] == 'C')
		g->col_cnt++;
	if(g->str_line[i + 1] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if(g->str_line[i + 1] != '1' && g->str_line[i + 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + 1] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		setting_img(*g);
	}
}

int	press_key(int key_code, t_game *game)
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
