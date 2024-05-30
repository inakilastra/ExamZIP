/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:53:40 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/29 12:03:04 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_itoa(int n)
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
