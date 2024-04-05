/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machi <machi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:39:06 by ktakamat          #+#    #+#             */
/*   Updated: 2024/04/03 18:49:34 by machi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

char	*ft_strjoin_new(char const *s1, char const *s2)
{
	char	*a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = (char *)ft_calloc(sizeof(*a), (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (a == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		a[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		a[i] = s2[j];
		i++;
		j++;
	}
	if (a[i - 1] == '\n')
		a[i - 1] = '\0';
	return (a);
}

void map_read(char *filename, t_game *game)
{
	int	fd;
	char *line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if(line == NULL || *line == '\0')
	{
		printf("empty_Error\n");
		exit(EXIT_FAILURE);
	}
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	game->hei = 0;
	game->wid = ft_strlen(line);
	game->str_line = ft_strdup(line);
	free(line);
	while(line)
	{
		game->hei++;
		line = get_next_line(fd);
		if(line)
		{
			game->str_line = ft_strjoin_new(game->str_line, line);
		}
	}
	close(fd);
	printf("%s\n", game->str_line);
}

void	setting_img(t_game game)
{
	size_t		hei;
	size_t		wid;

	hei = 0;
	while (hei < game.hei)
	{
		wid = 0;
		while (wid < game.wid)
		{			
			char alpha = game.str_line[hei * game.wid + wid];
			if (alpha == '1')
			{
				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.wall, wid * 50, hei * 50);
			}
			else if (alpha == 'C')
			{
				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.chest, wid * 50, hei * 50);
			}
			else if (alpha == 'P')
			{
				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.chara, wid * 50, hei * 50);
			}
			else if (alpha == 'E')
			{
				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.rune, wid * 50, hei * 50);
			}
			// else if (alpha != '1' && alpha != 'C' && alpha != 'P' && alpha != 'E')
			// {
			// 	printf("henamozi_Error\n");
			// 	exit(EXIT_FAILURE);
			// }
			else
			{
				mlx_put_image_to_window(game.mlx.m_ptr, game.mlx.w_ptr, game.img.land, wid * 50, hei * 50);
			}
			wid++;
		}
		hei++;
	}
}

void check_first_line(t_game *game) {
    size_t wid = 0;
	
    while (wid < game->wid) {
        char alpha = game->str_line[wid];
        if (alpha != '1' && alpha != 'C' && alpha != 'P' && alpha != 'E') {
            printf("Invalid character encountered at the first line\n");
            exit(EXIT_FAILURE);
        }
        wid++;
    }
}
