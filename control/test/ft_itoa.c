/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:17:03 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/10 11:34:50 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	nlen(int nbr)
{
	int	n;

	n = 0;
	if (nbr <= 0)
		n++;
	while (nbr != 0)
	{
		n++;
		nbr = nbr / 10;
	}
	return (n);
}

char	*ft_itoa(int nbr)
{
	char	*digits;
	int		len;
	char	*str;

	digits = "0123456789";
	len = nlen(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nbr == -2147483648)
		return ("-2147483648\0");
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[--len] = digits[nbr % 10];
		nbr = nbr / 10;
	}
	return (str);
}
