/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:33:00 by rlechapt          #+#    #+#             */
/*   Updated: 2014/11/30 16:18:09 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if ((s2 = (char*)malloc(sizeof(*s2) * (ft_strlen(s1)))) == NULL)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
