/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:03:09 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/11 16:03:13 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*ret;
	const char	*ptr;

	ret = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	*(ret + ft_strlen(s)) = '\0';
	ptr = s;
	while (*s++)
		*(ret + (s - ptr - 1)) = f((s - ptr - 1), *(s - 1));
	return (ret);
}
