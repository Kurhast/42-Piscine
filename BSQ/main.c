/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:46:20 by nibouniq          #+#    #+#             */
/*   Updated: 2022/07/27 11:49:05 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_map.h"

void	ft_putstr(char *str);
void	ft_putstr_fd(char *str, int fd);
int		process_map_file(char *filename);

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		if (!process_map_file(NULL))
			ft_putstr_fd("map error\n", 2);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!process_map_file(argv[i]))
			ft_putstr_fd("map error\n", 2);
		i++;
	}
	return (0);
}
