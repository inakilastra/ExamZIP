/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:43:56 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/10 11:24:07 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libzip.h"

static int	n_dig(int n)
{
	int	i;
	int	tmp;

	tmp = n;
	i = 1;
	if (tmp < 0)
	{
		tmp *= -1;
		i++;
	}
	while (tmp >= 10)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

char	*ft_myitoa(int n)
{
	int		dig;
	char	*str;

	if (n == -2147483648)
		return (strdup("-2147483648"));
	if (n == 0)
		return (strdup("0"));
	dig = n_dig(n);
	str = (char *)malloc(sizeof(char) * (dig + 1));
	if (!str)
		return ("");
	str[dig--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[dig--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
