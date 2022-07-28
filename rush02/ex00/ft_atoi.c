/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <nibouniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:53:37 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/24 20:38:35 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

int	getsign(char c, int *s)
{
	if (c == '-')
		*s *= -1;
	return (*s);
}

char	*ft_atoi_char(char *str)
{
	int		sign;
	int		i;
	int		k;
	char	*nb;

	sign = 1;
	nb = malloc(sizeof(char) * 20);
	i = 0;
	k = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		getsign(str[i], &sign);
		i++;
	}
	while (48 <= str[i] && str[i] <= 57)
	{
		if (sign < 0)
			nb[k++] = '-';
		nb[k++] = str[i++];
	}
	return (nb);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0 ;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] > s2[i])
		return (1);
	else if (s1[i] == s2[i])
		return (0);
	return (-1);
}

int	ft_charcmp(char c, char *s2)
{
	int	i;

	i = 0 ;
	while (s2[i] && c != s2[i])
		i++;
	if (c == s2[i])
		return (0);
	return (-1);
}
