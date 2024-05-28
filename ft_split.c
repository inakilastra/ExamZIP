// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------
// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.
// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.
// Your function must be declared as follows:
// char    **ft_split(char *str);

#include <stdlib.h>

char *ft_strncopy(char *s1, char *s2, int n)
{
	int i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

int is_space(char ch)
{
	return(ch == ' ' || ch == '\t' || ch == '\n');
}

int number_words(char *str)
{
	int i = 0;
	int number = 0;

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
	if (!str)
		return (NULL);
	int i = 0;
	int k = 0;
	int initword;
	int n_words = number_words(str);
	char **split;
	split = (char **)malloc(sizeof(char *) * (n_words + 1));
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
	return(split);
}

//  #include <stdio.h>
// int	main()
// {
// 	char **frase = ft_split("hola que tal");
// 	int i = 0;

// 	while (frase[i])
// 	{
// 		printf("string %d: %s\n", i, frase[i]);
// 		i++;
// 	}
// 	return (0);
// }