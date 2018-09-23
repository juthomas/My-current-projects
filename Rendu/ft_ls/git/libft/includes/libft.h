/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 14:24:40 by juthomas          #+#    #+#             */
/*   Updated: 2018/07/09 17:02:30 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <math.h>

/*
** Display fonctions
*/


void    ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(const char *str);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putnbr_fd(float nbr, int fd);

/*
** String fonctions
*/

void	ft_bzero(void *ptr, size_t n);
char	*ft_stralloc(size_t size);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*ft_strnew(size_t size);
int		ft_strcmp(const char *s1, const char *s2);



#endif