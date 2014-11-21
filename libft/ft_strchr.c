/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:22:50 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/08 17:46:19 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *str, int character)
{
	int i;
	int ok;

	i = ft_strlen(str);
	ok = 0;
	while ((ok == 0) && (i >= 0))
	{
		if (str[i] == character)
			ok = 1;
		else
			i--;
	}
	if (ok == 0)
		return (0);
	else
		return ((char *)(str + i));
	return (0);
}
