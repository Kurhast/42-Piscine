/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:38:10 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/24 23:38:15 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_u(char c, t_dictio *dictio)
{
	int j;

	j = 0;
	while (ft_charcmp(c, dictio->dictio_parsed[j]) != 0)
		j++;
	ft_putstr(dictio->dictio_parsed[j + 1]);
	ft_putchar(' ');
}


int	print_d(t_dictio *dictio, char *number, int start_pos)
{
	int j;
	int i;

	j = 0;
	i = start_pos;
	if(number[i] == 49)
	{
		j = getindex_10(number, dictio, i);
		ft_putstr(dictio->dictio_parsed[j + 1]);
		ft_putchar(' ');
		return (1);
	}
	if (number[i] >= 50)
	{
		j = getindex_20(number, dictio, i);
		ft_putstr(dictio->dictio_parsed[j + 1]);
		ft_putchar(' ');
		i++;
		if (number[i] != '0')
			print_u(number[i], dictio);
		return (1);
	}
	return (0);
}

void	print_h(t_dictio *dictio, char *number, int start_pos)
{
	int i;
	int j;

	i = start_pos;
	j = 0;
	print_u(number[i], dictio);
	while (ft_strcmp(dictio->dictio_parsed[j], "100"))
		j++;
	ft_putstr(dictio->dictio_parsed[j + 1]);
	ft_putchar(' ');
	print_d(dictio, number, i + 1);
}

void	print_th(t_dictio *dictio, char *number, int start_pos)
{
	int i;
	int j;

	i = start_pos;
	j = 0;
	print_u(number[i], dictio);
	while (ft_strcmp(dictio->dictio_parsed[j], "1000"))
		j++;
	ft_putstr(dictio->dictio_parsed[j + 1]);
	ft_putchar(' ');
	print_h(dictio, number, 1);
}
