/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <nibouniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:43:28 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/24 20:39:18 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	length_file(char *file_name)
{
	int				file;
	int				index;
	int				i;
	char			buf[2];

	i = 0;
	index = 1;
	file = open(file_name, O_RDONLY);
	if (file == -1)
	{
		ft_putstr("Dict Error\n");
		return (-1);
	}
	while (index)
	{
		index = read(file, buf, 1);
		buf[index] = '\0';
		i += 1;
	}
	if (close(file) == -1)
	{
		ft_putstr("Dict Error\n");
		return (-1);
	}
	return (i);
}

t_dictio	*get_dictio(t_file_param *file_p)
{
	char		*buf;
	int			file;
	int			ret;
	t_dictio	*dictio_p;

	buf = malloc(file_p->size_file + 1);
	buf[0] = 0;
	dictio_p = malloc(sizeof(char));
	file = open(file_p->file_name, O_RDONLY);
	if (file == -1)
	{
		ft_putstr("Dict error\n");
		return (NULL);
	}
	ret = read(file, buf, file_p->size_file);
	buf[ret] = '\0';
	dictio_p->dictio = buf;
	dictio_p->dictio_parsed = ft_split(buf, " :\n");
	if (close(file) == -1)
	{
		ft_putstr("Dict error\n");
		return (NULL);
	}
	return (dictio_p);
}


