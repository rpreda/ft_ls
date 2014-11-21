/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:47:57 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/08 16:33:28 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t n)
{
	char	*c;
	size_t	i;

	c = (char *)malloc(n * sizeof(char));
	i = 0;
	while (i < n)
	{
		*(c + i) = *(char *)(src + i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(c + i);
		i++;
	}
	return (dst);
}
