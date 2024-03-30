/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machi <machi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:14:14 by ktakamat          #+#    #+#             */
/*   Updated: 2023/05/25 00:36:42 by machi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	a;

	a = (char)c;
	str = (char *)s;
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
