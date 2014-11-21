/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:16:32 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/08 17:49:59 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*found;

	i = 0;
	found = 0;
	while (s[i])
	{
		if (s[i] == c)
			found = (char *)(s + i);
		i++;
	}
	if (!c)
		return (char *)(s + ft_strlen(s));
	return (found);
}
