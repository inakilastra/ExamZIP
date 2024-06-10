/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:11:33 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/10 13:45:49 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncopy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

int	is_space(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n');
}

int	number_words(char *str)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i])
			number++;
		while (str[i] && !is_space(str[i]))
			i++;
	}
	return (number);
}

char	**ft_split(char *str)
{
	int		i;
	int		k;
	int		initword;
	char	**split;

	i = 0;
	k = 0;
	split = (char **)malloc(sizeof(char *) * (number_words(str) + 1));
	if (!split)
		return (NULL);
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		initword = i;
		while (str[i] && !is_space(str[i]))
			i++;
		if (initword < i)
		{
			split[k] = (char *)malloc(sizeof(char) * ((i - initword) + 1));
			ft_strncopy(split[k++], &str[initword], i - initword);
		}
	}
	split[k] = NULL;
	return (split);
}
