/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:55:39 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/25 17:47:28 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

static void	ft_putnbr2(long n, int *i, char *str)
{
	char	c;

	if (n < 0)
	{
		n = -n;
		str[*i] = '-';
		(*i)++;
		ft_putnbr2(n, i, str);
	}
	else if (n > 9)
	{
		ft_putnbr2(n / 10, i, str);
		ft_putnbr2(n % 10, i, str);
	}
	else
	{
		c = n + 48;
		str[*i] = c;
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	int		new_n;
	long	num;

	i = 0;
	len = 0;
	new_n = n;
	num = n;
	while (new_n / 10 != 0)
	{
		len++;
		new_n /= 10;
	}
	if (n < 0)
		len++;
	str = malloc(len + 2);
	if (!str)
		return (NULL);
	ft_putnbr2(num, &i, str);
	str[i] = '\0';
	return (str);
}
