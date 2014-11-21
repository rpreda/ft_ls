/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:54:04 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/08 19:08:03 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int neg;
	int numar;

	numar = 0;
	i = 0;
	neg = 1;
	while (*(str + i) == 32 || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i++] == 45)
		neg = -1;
	else if (str[--i] == 43)
		i++;
	while ((str[i] != '\0') || (numar != 0))
	{
		if ((*(str + i) >= 48) && (*(str + i) <= 57))
			numar = numar * 10 + (*(str + i) - 48);
		else
			return (numar * neg);
		i++;
	}
	return (0);
}
