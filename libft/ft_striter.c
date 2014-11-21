/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:56:16 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/11 14:57:49 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_striter(char *s, void (*f)(char *))
{
	while (*s++)
		f(s - 1);
}