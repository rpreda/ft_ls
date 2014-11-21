/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:34:59 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/08 12:47:12 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	ld;
	size_t	ls;
	size_t	siz_orig;

	siz_orig = siz;
	ld = ft_strlen(dst);
	ls = ft_strlen(src);
	while (*dst && siz)
	{
		dst++;
		siz--;
	}
	if (!siz)
		return (siz_orig + ls);
	while (*src && siz > 1)
	{
		siz--;
		*dst++ = *src++;
	}
	*dst = '\0';
	return (ld + ls);
}
