/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:04:42 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/10 10:07:56 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	long	len;
	long	i;
	int		*numbers;

	i = 0;
	if (end > start)
		len = (long)end - (long)start + 1;
	if (start > end)
		len = (long)start - (long)end + 1;
	numbers = (int *)malloc(sizeof(int) * len);
	if (!numbers)
		return (NULL);
	while (i < len)
	{
		if (start < end)
			numbers[i++] = end--;
		else
			numbers[i++] = end++;
	}
	return (numbers);
}
