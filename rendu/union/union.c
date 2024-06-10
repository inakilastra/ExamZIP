/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:41:14 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/10 12:42:26 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	not_seen_before(char *str, char c, int max_pos)
{
	int	i;

	i = 0;
	while (i < max_pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (not_seen_before(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}
	while (s2[j])
	{
		if (not_seen_before(s1, s2[j], i) && not_seen_before(s2, s2[j], j))
			write(1, &s2[j], 1);
		j++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
