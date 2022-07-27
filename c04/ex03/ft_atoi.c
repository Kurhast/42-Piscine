/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:26:34 by nibouniq          #+#    #+#             */
/*   Updated: 2022/07/17 16:01:18 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	long int	nb;
	int			i;
	int			sign;

	i = 0;
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i])
		i++;
	sign = 1;
	while ((str[i] == 45 || str[i] == 43) && str[i])
	{
		if (str[i] == 45)
			sign = sign * -1;
		i++;
	}
	nb = 0;
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	nb = nb * sign;
	return (nb);
}
