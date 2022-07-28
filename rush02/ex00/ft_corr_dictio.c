/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <nibouniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:08:26 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/24 20:36:15 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

char    *ft_strcat(char *dest, char *src)
{
    int        lendest;
    int        lensrc;
    char       sep;

    sep = ' ';
    lendest = ft_strlen(dest);
    lensrc = 0;
    while (src[lensrc])
    {
        dest[lendest] = src[lensrc];
        dest[lendest] = sep;
        lensrc++;
    }
    dest[lendest + lensrc] = '\0';
    return (dest);
}

t_dictio    *corr_dictio(t_dictio *dictio_p)
{
    int        i;
    char    sep;
    int        j;

    i = 0;
    j = 0;
    sep = ' ';
    
            while (dictio_p->dictio_parsed[i] && dictio_p->dictio_parsed[i + 1] != '\0')
            {
                if (((dictio_p->dictio_parsed[i][j] >= 97 && dictio_p->dictio_parsed[i][j] <= 122) && (dictio_p->dictio_parsed[i + 1][j] >= 97 && dictio_p->dictio_parsed[i + 1][j] <= 122)))
                {
                    while (!(dictio_p->dictio_parsed[i][j] >= 48 && dictio_p->dictio_parsed[i][j] <= 57))
                    {
                        dictio_p->dictio_parsed[i] = ft_strcat(dictio_p->dictio_parsed[i], dictio_p->dictio_parsed[i + 1]);                        
                        dictio_p->dictio_parsed[i] = ft_strcat(dictio_p->dictio_parsed[i], dictio_p->dictio_parsed[i + 1]);
                        i++;
                    }
                }
                i++;
            }
    return (dictio_p);
}

t_dictio	*ft_check_dict(t_dictio *dictio)
{
	int	i;

	i = 0;
	while (dictio->dictio_parsed[i])
	{
		dictio->dictio_parsed[i] = ft_atoi_char(dictio->dictio_parsed[i]);
		if (dictio->dictio_parsed[i][0] == '-')
		{
			ft_putstr("Dict Error\n");
			return (NULL);
		}
		i = i + 2;
	}
	return (dictio);
}