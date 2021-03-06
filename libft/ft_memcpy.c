/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:49:23 by rlechapt          #+#    #+#             */
/*   Updated: 2014/11/30 16:09:08 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tmp;

	tmp = (char*)dst;
	i = 0;
	while (i < n)
	{
		tmp[i] = ((const char*)src)[i];
		i++;
	}
	return (dst);
}
