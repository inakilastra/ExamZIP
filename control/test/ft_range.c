/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:04:33 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/10 11:04:35 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	long	i;
	long	len;
	int		*numbers;

	if (end > start)
		len = (long)end - (long)start + 1;
	if (start > end)
		len = (long)start - (long)end + 1;
	i = 0;
	numbers = (int *)malloc(sizeof(int) * len);
	if (!numbers)
		return (NULL);
	while (i < len)
	{
		if (start <= end)
			numbers[i++] = start++;
		else
			numbers[i++] = start--;
	}
	return (numbers);
}
