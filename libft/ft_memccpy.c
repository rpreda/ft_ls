/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:51:13 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/08 19:09:19 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptr1;
	unsigned char		*ptr2;

	ptr1 = (unsigned char*)dest;
	ptr2 = (unsigned char*)src;
	if (dest == NULL || src == NULL)
		return (NULL);
	i = 0;
	while (i < n && ptr2[i] != (unsigned char)c)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	if (ptr2[i] == (unsigned char)c && i != n)
	{
		ptr1[i] = ptr2[i];
		return (&ptr1[i + 1]);
	}
	return (NULL);
}
