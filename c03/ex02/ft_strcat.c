/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:59:29 by nibouniq          #+#    #+#             */
/*   Updated: 2022/07/13 16:37:39 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (src[i])
	{
		i++;
	}
	j = 0;
	while (dest[j])
	{
		j++;
	}
	k = 0;
	while (src[k])
	{
		dest[j] = src[k];
		k++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
