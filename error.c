/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machi <machi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:12:23 by machi             #+#    #+#             */
/*   Updated: 2024/04/03 14:56:21 by machi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

void	num_chara(t_game *game)
{
	int	p_count = 0;
	int	e_count = 0;
	size_t	hei = 0;
	size_t	wid = 0;

	while (hei < game->hei)
	{
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
	if (p_count == 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	else if(p_count > 1)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (e_count == 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	else if(e_count > 1)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
