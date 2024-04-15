/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:47:38 by ktakamat          #+#    #+#             */
/*   Updated: 2024/04/15 19:05:44 by ktakamat         ###   ########.fr       */
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