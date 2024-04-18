/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tansaku_error2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 03:33:22 by machi             #+#    #+#             */
/*   Updated: 2024/04/18 18:08:21 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	reach_goal(t_game *game, size_t x, size_t y)
{
	return (game->str_line[x + (y * game->wid)] == 'E');
}

size_t	find_p(t_game *game)
{
	size_t	i;

	i = 0;
	if (!game->str_line)
		return (0);
	while (game->str_line[i])
	{
		if (game->str_line[i] == 'P')
			return (i);
		i++;
	}
	return (0);
}

bool	pass_find1(t_game *game, bool *visited, t_stack *stack)
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
		if (reach_goal(game, cur.x, cur.y))
			return (true);
		while (i < 4)
		{
			game->xi = cur.x + dx[i];
			game->yi = cur.y + dy[i];
			can_pass(game, visited, stack);
			i++;
		}
	}
	return (false);
}

bool	reach_e(t_game *game)
{
	t_stack	stack[MAX_SIZE];
	t_stack	start;
	bool	visited[MAX_SIZE * MAX_SIZE];
	size_t	start_index;

	start_index = find_p(game);
	start.x = start_index % game->wid;
	start.y = start_index / game->wid;
	game->top = 0;
	game->xi = 0;
	game->yi = 0;
	ft_memset(visited, false, sizeof(visited));
	stack[game->top] = start;
	visited[start.x + (start.y * game->wid)] = true;
	return (pass_find1(game, visited, stack));
}
