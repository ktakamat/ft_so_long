/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:08:29 by machi             #+#    #+#             */
/*   Updated: 2024/04/25 19:57:10 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(int fd, char *save)
{
	char	*buf;
	ssize_t	result;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		ft_exit();
	while (!ft_strchr(save, '\n'))
	{
		result = read(fd, buf, BUFFER_SIZE);
		if (result == -1)
		{
			free(buf);
			free(save);
			return (NULL);
		}
		if (result == 0)
			break ;
		buf[result] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_line(char *save)
{	
	char	*line;
	size_t	i;

	i = 0;
	while (save[i] && save[i] != '\n')
	{
		i++;
	}
	line = (char *)malloc((sizeof(char) * (i + 2)));
	if (!line)
		ft_exit();
	ft_strlcpy(line, save, i + 2);
	return (line);
}

char	*reset_save(char *save)
{
	char	*save_new;
	size_t	i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	save_new = (char *)malloc(sizeof(char) * (ft_strlen(save) - i));
	if (!save_new)
		ft_exit();
	ft_strlcpy(save_new, &save[i + 1], ft_strlen(save) - i);
	free(save);
	return (save_new);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	save = read_file(fd, save);
	if (!save || !(*save))
	{
		free(save);
		return (NULL);
	}
	line = get_line(save);
	if (!line)
		return (NULL);
	save = reset_save(save);
	return (line);
}
