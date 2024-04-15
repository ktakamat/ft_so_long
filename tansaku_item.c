/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tansaku_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machi <machi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:45:48 by machi             #+#    #+#             */
/*   Updated: 2024/04/13 19:03:25 by machi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	reach_item(t_game *game, size_t x, size_t y)
{
	return (game->str_line[x + (y * game->wid)] == 'C');
}

size_t	find_c(t_game *game)
{
	if (!game->str_line)
		return (0);
	while (game->str_line[game->now_col])
	{
		if (game->str_line[game->now_col] == 'C')
			return (game->now_col);
		game->now_col++;
	}
	return(0);
}

bool	pass_find(t_game *game, bool *visited, t_stack *stack)
{
	int			i;
	static int	dx[] = {-1, 0, 1, 0};
	static int	dy[] = {0, 1, 0, -1};
	t_stack		cur;

	while (game->top >= 0)
	{
		i = 0;
		cur = stack[game->top];
		game->top--;
		if (reach_item(game, cur.x, cur.y))
			return (true);
		while (i < 4)
		{
			game->xi = cur.x + dx[i];
			game->yi = cur.y + dy[i];
			terms_pass(game, visited, stack);
			i++;
		}
	}
	return (false);
}

bool	no_c(t_game *game)
{
	if (game->error_item == 0)
		return(true);
	return (false);
}

bool	reach_c(t_game *game)
{
	t_stack	stack[MAX_SIZE];
	t_stack start;
	bool visited[MAX_SIZE * MAX_SIZE];
	size_t start_index = find_c(game);
	int	i = 0;

	while(i++ > game->all_col)
	{
		if (start_index == 0)
			game->error_item++;
		start.x = start_index % game->wid;
		start.y = start_index / game->wid;
		game->top = 0;
		game->xi = 0;
		game->yi = 0;
		ft_memset(visited, false, sizeof(visited));
		stack[game->top] = start;
		visited[start.x + (start.y * game->wid)] = true;
		if (!pass_find(game, visited, stack))
			game->error_item++;
		game->now_col++;
	}
	return (no_c(game));
}
