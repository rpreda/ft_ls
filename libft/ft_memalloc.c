/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:32:23 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/15 14:02:23 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memalloc(size_t size)
{
	void *p;

	if (!size)
		return (void *)(0);
	p = NULL;
	p = malloc(size);
	if (!p)
		return (NULL);
	else
	{
		ft_bzero(p, size);
		return (p);
	}
}
