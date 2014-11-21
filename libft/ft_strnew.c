/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:50:00 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/11 13:58:23 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnew(size_t size)
{
	char *s;

	if (!(s = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
