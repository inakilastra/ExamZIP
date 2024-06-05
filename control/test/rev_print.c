/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:20:22 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/05 11:22:21 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int	main(int argc, char **argv)
{
	int	len;

	if (argc == 2)
	{
		len = str_len(argv[1]) - 1;
		while (len >= 0)
			write(1, &argv[1][len--], 1);
	}
	write(1, "\n", 1);
	return (0);
}
