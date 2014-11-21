/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:28:04 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/11 15:57:28 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	char		*ret;
	const char	*ptr;

	ret = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	*(ret + ft_strlen(s)) = '\0';
	ptr = s;
	while (*s++)
		*(ret + (s - ptr - 1)) = f(*(s - 1));
	return (ret);
}
