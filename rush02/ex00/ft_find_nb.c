/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:29:10 by nibouniq          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:03 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <fcntl.h>

#include <stdio.h>

t_number	*setup_nbstruct(char *argv)
{
	t_number	*number;

	number = malloc(sizeof(t_number) + 1);
	number->number_length = ft_strlen(argv);
	number->number_array = argv;
	return (number);
}

int	getindex_10(char *number, t_dictio *dictio, int start_pos)
{
	int j;
	int i;

	j = 0;
	i = start_pos;
	while (ft_strcmp(dictio->dictio_parsed[j], "10") != 0)
			j++;
	i++;
	while (ft_charcmp(number[i], dictio->dictio_parsed[j]) != 0)
        	j++;
	return (j);
}

int	getindex_20(char *number, t_dictio *dictio, int start_pos)
{
	int j;
	int i;

	j = 0;
	i = start_pos;
	while (ft_strcmp(dictio->dictio_parsed[j], "20") != 0)
			j++;
	while (ft_charcmp(number[i], dictio->dictio_parsed[j]) != 0)
        	j++;
	return (j);
}



void	write_nb(t_dictio *dictio, t_number *number)
{
	if (number->number_length == 1)
		print_u(number->number_array[0], dictio);
	if (number->number_length == 2)
		print_d(dictio, number->number_array, 0);
	if (number->number_length == 3)
		print_h(dictio, number->number_array, 0);
	if (number->number_length >= 4)
	{
		if (number->number_length == 4)
			print_th(dictio, number->number_array, 0);
	}
}
