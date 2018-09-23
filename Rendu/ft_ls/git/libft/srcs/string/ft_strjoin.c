/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 00:12:07 by juthomas          #+#    #+#             */
/*   Updated: 2018/07/10 01:05:32 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*cpy;

	cpy = NULL;
	if (!(cpy = ft_stralloc(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	cpy = ft_strcpy(cpy, s1);
	cpy = ft_strcat(cpy, s2);
	return (cpy);
}
