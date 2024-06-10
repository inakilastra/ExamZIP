/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaki <inaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:30:57 by inaki             #+#    #+#             */
/*   Updated: 2024/06/10 00:07:16 by inaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;

	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		j = 0;
		while (str[i])
		{
			if ((str[i] == ' ' || str[i] == '\t')
				&& (str[i + 1] >= 33 && str[i + 1] <= 126))
				j = i + 1;
			i++;
		}
		while (str[j] >= 33 && str[j] <= 126)
			write(1, &str[j++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
