/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:14:14 by ktakamat          #+#    #+#             */
/*   Updated: 2024/03/31 17:56:01 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	a;

	a = (char)c;
	str = (char *)s;
	printf("ppap/n");
	while (*str != '\0')
	{
		if (*str == a)
		{
			return (str);
		}
		str++;
	}
	if (a == '\0')
	{
		return (str);
	}
	return (NULL);
}
