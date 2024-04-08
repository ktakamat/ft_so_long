/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tansaku_error1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machi <machi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:13:14 by machi             #+#    #+#             */
/*   Updated: 2024/04/08 19:32:30 by machi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

bool	check_o(t_game *game, size_t x, size_t y)
{
	return (x >= 0 && x < game->wid && y >= 0
		&& y < game->hei && game->str_line[x + (y * game->wid)] != '1');
}

bool	check_E(t_game *game, size_t x, size_t y)
{
	return (x >= 0 && x < game->wid && y >= 0
		&& y < game->hei && game->str_line[x + (y * game->wid)] != '1'
		&& y < game->hei && game->str_line[x + (y * game->wid)] != 'E');
}

void	can_pass(t_game *game, bool *visited, t_stack *stack)
{
	t_stack next;

	next.x = game->xi;
	next.y = game->yi;
	if (check_o(game, game->xi, game->yi) == true && !visited[game->xi + (game->yi * game->wid)])
	{
		game->top++;
		stack[game->top] = next;
		visited[game->xi + (game->yi * game->wid)] = true;
	}
}

void	terms_pass(t_game *game, bool *visited, t_stack *stack)
{
	t_stack next;

	next.x = game->xi;
	next.y = game->yi;
	if (check_E(game, game->xi, game->yi) == true && !visited[game->xi + (game->yi * game->wid)])
	{
		game->top++;
		stack[game->top] = next;
		visited[game->xi + (game->yi * game->wid)] = true;
	}
}
