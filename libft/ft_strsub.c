/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:05:47 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/12 17:04:04 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	ln;

	ln = ft_strlen(s);
	if (len > ln || ((start > ln) || (start + len > ln)))
		return (NULL);
	if (!(dst = ft_strnew(len)))
		return (NULL);
	dst = ft_strncpy(dst, s + start, len);
	dst[len] = '\0';
	return (dst);
}
