/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machi <machi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:14:14 by ktakamat          #+#    #+#             */
/*   Updated: 2024/04/01 14:18:32 by machi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	uc;
	size_t			len;
	size_t			i;

	if (!s)
		return (NULL);
	ptr = NULL;
	uc = (unsigned char)c;
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (*s == uc)
		{
			ptr = (char *)(s);
			return (ptr);
		}
		s++;
		i++;
	}
	return (ptr);
}