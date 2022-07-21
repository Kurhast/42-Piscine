/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:38:21 by nibouniq          #+#    #+#             */
/*   Updated: 2022/07/12 11:54:49 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	if (str[i] >= 97 && str[i] <= 122)
	{	
		str[i] = str[i] - 32;
	}
	i++;
	while (str[i] != '\0')
	{
		if (!((str[i - 1] >= 97 && str[i - 1] <= 122)
				|| (str[i - 1] >= 48 && str[i - 1] <= 57)
				|| (str[i - 1] >= 65 && str[i - 1] <= 90))
			&& (str[i] >= 97 && str[i] <= 122))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
