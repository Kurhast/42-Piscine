/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <nibouniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:41:53 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/24 20:28:09 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <fcntl.h>

#include <stdio.h>

t_file_param	*setup_stuct(char *file_name)
{
	t_file_param	*file_p;

	file_p = malloc(sizeof(t_file_param));
	file_p->size_file = length_file(file_name);
	file_p->file_name = ft_strdup(file_name);
	return (file_p);
}

int	rush(char *argv)
{
	char				*file_name;
	t_file_param		*file_p;
	t_dictio			*dictio_p;
	t_number			*number_p;

	file_name = ft_strdup("numbers.dict");
	if (check_error(argv) == 0)
		return (0);
	file_p = setup_stuct(file_name);
	dictio_p = get_dictio(file_p);
	number_p = setup_nbstruct(argv);
	dictio_p = ft_check_dict(dictio_p);
	dictio_p = corr_dictio(dictio_p);
	write_nb(dictio_p, number_p);
	return (1);
}

int	rush_w_dict(char *argv1, char *argv2)
{
	char				*file_name;
	t_file_param		*file_p;
	t_dictio			*dictio_p;
	t_number			*number_p;

	file_name = ft_strdup(argv1);
	if (check_error(argv2) == 0)
		return (0);
	file_p = setup_stuct(file_name);
	dictio_p = get_dictio(file_p);
	number_p = setup_nbstruct(argv2);
	dictio_p = ft_check_dict(dictio_p);
	dictio_p = corr_dictio(dictio_p);
	write_nb(dictio_p, number_p);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rush(argv[1]);
	else if (argc == 3)
		rush_w_dict(argv[1], argv[2]);
	else
		ft_putstr("error");
}
