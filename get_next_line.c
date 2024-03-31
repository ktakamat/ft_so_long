/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:08:29 by machi             #+#    #+#             */
/*   Updated: 2024/03/31 18:03:08 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char	*read_file(int fd, char *save)
// {
// 	char	*buf;
// 	ssize_t	result;

// 	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buf)
// 		return (NULL);
// 	while (!strchr(save, '\n'))
// 	{
// 		printf("kokjkhgfdsghjkgfdhjklhgfdoko\n");
// 		printf("file 1\n");
// 		result = read(fd, buf, BUFFER_SIZE);
// 		if (result == -1)
// 		{
// 			free(buf);
// 			free(save);
// 			return (NULL);
// 		}
// 		if (result == 0)
// 			break ;
// 		buf[result] = '\0';
// 		save = ft_strjoin(save, buf);
// 	}
// 	free(buf);
// 	return (save);
// }

// char	*get_line(char *save)
// {	
// 	char	*line;
// 	size_t	i;

// 	i = 0;
// 	while (save[i] && save[i] != '\n')
// 	{
// 		i++;
// 	}
// 	line = (char *)malloc((sizeof(char) * (i + 2)));
// 	if (!line)
// 		return (NULL);
// 	ft_strlcpy(line, save, i + 2);
// 	return (line);
// }

// char	*reset_save(char *save)
// {
// 	char	*save_new;
// 	size_t	i;

// 	i = 0;
// 	while (save[i] && save[i] != '\n')
// 		i++;
// 	if (!save[i])
// 	{
// 		free(save);
// 		return (NULL);
// 	}
// 	save_new = (char *)malloc(sizeof(char) * (ft_strlen(save) - i));
// 	if (!save_new)
// 		return (NULL);
// 	ft_strlcpy(save_new, &save[i + 1], ft_strlen(save) - i);
// 	free(save);
// 	return (save_new);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*save;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE < 0)
// 		return (NULL);
// 	printf("hei4\n");
// 	save = read_file(fd, save);
// 	printf("hei3\n");
// 	if (!save || !(*save))
// 	{
// 		free(save);
// 		return (NULL);
// 	}
// 	printf("hei2\n");
// 	line = get_line(save);
// 	printf("hei\n");
// 	if (!line)
// 		return (NULL);
// 	save = reset_save(save);
// 	return (line);
// }

char	*fr_strjoin_free_temp(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin_kai(buffer, buf);
	if (buffer)
		free(buffer);
	return (temp);
}

char	*ft_left_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = (char *)ft_calloc_kai((ft_strlen_kai(buffer) - i + 1), sizeof(char));
	if (!line)
	{
		if (buffer)
			free(buffer);
		return (line);
	}
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_got_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)ft_calloc_kai(i + 2, sizeof(char));
	if (!line)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_file(int fd, char *one_fd_line)
{
	char	*buffer;
	long	byte_read;

	buffer = (char *)ft_calloc_kai(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (kusottare(&one_fd_line));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (kusottare(&one_fd_line));
		}
		buffer[byte_read] = '\0';
		one_fd_line = fr_strjoin_free_temp(one_fd_line, buffer);
		if (!one_fd_line || ft_strchr_kai(one_fd_line, '\n'))
			break ;
	}
	free(buffer);
	return (one_fd_line);
}

char	*get_next_line(int fd)
{
	static char	*many_fd[OPEN_MAX];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	many_fd[fd] = read_file(fd, many_fd[fd]);
	if (!many_fd[fd])
		return (NULL);
	line = ft_got_line(many_fd[fd]);
	many_fd[fd] = ft_left_line(many_fd[fd]);
	return (line);
}

size_t	ft_strlen_kai(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr_kai(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}

void	ft_bzero_kai(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc_kai(size_t number, size_t size)
{
	void	*ptr;

	if (number == 0 || size == 0)
	{
		number = 1;
		size = 1;
	}
	if (number > SIZE_MAX / size)
		return (NULL);
	ptr = (void *)malloc(number * size);
	if (!ptr)
		return (NULL);
	ft_bzero_kai(ptr, number * size);
	return (ptr);
}

char	*ft_strjoin_kai(const char *s1, const char *s2)
{
	char	*p;
	size_t	i;

	if (!s2)
		return (NULL);
	if (!s1)
		p = (char *)ft_calloc_kai((ft_strlen_kai(s2) + 1), sizeof(char));
	else
		p = (char *)ft_calloc_kai(ft_strlen_kai(s1)
				+ ft_strlen_kai(s2) + 1, sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	return (p);
}
