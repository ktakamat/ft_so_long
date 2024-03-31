/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machi <machi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:43:02 by machi             #+#    #+#             */
/*   Updated: 2023/05/25 00:37:18 by machi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (size != '\0' && (size * count) / size != count)
	{
		return (0);
	}
	a = malloc(size * count);
	if (a == NULL)
	{
		return (NULL);
	}
	ft_bzero(a, size * count);
	return (a);
}
