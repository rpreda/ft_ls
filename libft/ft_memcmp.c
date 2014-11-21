/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:52:26 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/07 18:03:18 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		a;
	int		b;

	i = 0;
	while (i < n)
	{
		a = *((unsigned char*)(s1 + i));
		b = *((unsigned char*)(s2 + i));
		if (a != b)
			return (a - b);
		i++;
	}
	return (0);
}
