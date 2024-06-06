/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paco.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:01:41 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/06 17:00:32 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libzip.h"

int	ft_paco_aff_a(int k, int show)
{
	char	*paco;

	paco = ft_paco_argv1("aff_a", "abc");
	if (strncmp(paco, "a", 1) == 0)
	{
		if (show == 1)
		{
			printf("%s ./aff_a \"abc\" | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_a \"abc\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = ft_paco_argv1("aff_a", "\"dubO a POIL\"");
	if (strncmp(paco, "a", 1) == 0)
	{
		if (show == 1)
		{
			printf("%s ./aff_a \"dubO a POIL\" | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_a \"dubO a POIL\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = ft_paco_argv1("aff_a", "\"zz sent le poney\"");
	if (strncmp(paco, "", 0) == 0)
	{
		if (show == 1)
		{
			printf("%s ./aff_a \"zz sent le poney\" | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_a \"zz sent le poney\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = ft_paco_argv0("aff_a");
	if (strncmp(paco, "a", 1) == 0)
	{
		if (show == 1)
		{
			printf("%s ./aff_a | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_a | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	return (k);
}

int	ft_paco_aff_z(int k, int show)
{
	char	*paco;

	paco = ft_paco_argv1("aff_z", "abc");
	if (strncmp(paco, "z", 1) == 0)
	{
		if (show == 1)
		{
			printf("%s ./aff_z \"abc\" | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_z \"abc\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = ft_paco_argv1("aff_z", "\"dubO a POIL\"");
	if (strncmp(paco, "z", 1) == 0)
	{
		if (show == 1)
		{
			printf("%s ./aff_z \"dubO a POIL\" | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_az \"dubO a POIL\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = ft_paco_argv1("aff_z", "\"zz sent le poney\"");
	if (strncmp(paco, "z", 1) == 0)
	{
		if (show == 1)
		{
			printf("%s ./aff_z \"zz sent le poney\" | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_z \"zz sent le poney\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = ft_paco_argv0("aff_z");
	if (strncmp(paco, "z", 1) == 0)
	{
		if (show == 1)
		{
			printf("%s ./aff_z | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_z | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	return (k);
}

int	ft_paco_rev_print(int k, int show)
{
	char	*paco;
/* $> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$ */
	paco = ft_paco_argv1("rev_print", "zaz");
	if (strncmp(paco, "zaz", 3) == 0)
	{
		if (show == 1)
		{
			printf("%s ./rev_print \"zaz\" | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./rev_print \"zaz\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = ft_paco_argv1("rev_print", "\"dubO a POIL\"");
	if (strncmp(paco, "LIOP a Obud", 11) == 0)
	{
		if (show == 1)
		{
			printf("%s ./rev_print \"dubO a POIL\" | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./rev_print \"dubO a POIL\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = ft_paco_argv0("rev_print");
	if (strncmp(paco, "", 0) == 0)
	{
		if (show == 1)
		{
			printf("%s ./rev_print | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./rev_print | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	return (k);
}
int	ft_paco_ok(char *name, char *argv1, int i, int show)
{
	int		k;
	char	*paco;

	k = i;
	paco = ft_paco_argv1(name, argv1);
	if (strncmp(paco, "a", 1) == 0)
	{
		if (show == 1)
			printf("%s ./%s %s\n", GREEN, name, argv1);
		k++;
	}
	else
		printf("%s ./%s %s\n", RED, name, argv1);
	free(paco);
	return (k);
}

char	*ft_paco_argv0(char *name)
{
	FILE	*fp;
	char	buffer[BUFFER_SIZE];
	char	*result;
	int		ret;
	char	compile_c[256];
	char	rendu_c[256];

	snprintf(compile_c, sizeof(compile_c), "gcc -o rendu/%s/%s rendu/%s/%s.c -Wall -Wextra -Werror", name, name, name, name);
	//printf("\n compile_c: %s\n\n", compile_c);
	ret = system(compile_c);
	if (ret != 0)
	{
		fprintf(stderr, "Error compiling %s.c\n", name);
		return (NULL);
	}
	snprintf(rendu_c, sizeof(rendu_c), "rendu/%s/./%s", name, name);
	//printf("\n rendu_c: %s\n\n", rendu_c);   
	fp = popen(rendu_c, "r");
	if (fp == NULL)
	{
		perror("popen");
		return (NULL);
	}
	result = malloc(BUFFER_SIZE * sizeof(char));
	if (result == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	result[0] = '\0';
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		if (strlen(result) + strlen(buffer) + 1 > BUFFER_SIZE)
		{
			result = realloc(result, strlen(result) + strlen(buffer) + 1);
			if (result == NULL)
			{
				perror("realloc");
				return (NULL);
			}
		}
		strcat(result, buffer);
	}
	//printf("result --> %s\n", result);
	if (pclose(fp) == -1)
	{
		perror("pclose");
		free(result);
		return (NULL);
	}
	//printf("Captured : %s", result);
	return (result);
}

char	*ft_paco_argv1(char *name, char *argv1)
{
	FILE	*fp;
	char	buffer[BUFFER_SIZE];
	char	*result;
	int		ret;
	char	compile_c[256];
	char	rendu_c[256];

	snprintf(compile_c, sizeof(compile_c), "gcc -o rendu/%s/%s rendu/%s/%s.c -Wall -Wextra -Werror", name, name, name, name);
	//printf("\n compile_c: %s\n\n", compile_c);
	ret = system(compile_c);
	if (ret != 0)
	{
		fprintf(stderr, "Error compiling %s.c\n", name);
		return (NULL);
	}
	snprintf(rendu_c, sizeof(rendu_c), "rendu/%s/./%s %s", name, name, argv1);
	//printf("\n rendu_c: %s\n\n", rendu_c);   
	fp = popen(rendu_c, "r");
	if (fp == NULL)
	{
		perror("popen");
		return (NULL);
	}
    result = malloc(BUFFER_SIZE * sizeof(char));
    if (result == NULL)
    {
        perror("malloc");
        return (NULL);
    }
    result[0] = '\0';

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        if (strlen(result) + strlen(buffer) + 1 > BUFFER_SIZE)
        {
            result = realloc(result, strlen(result) + strlen(buffer) + 1);
            if (result == NULL)
            {
                perror("realloc");
                return (NULL);
            }
        }
        strcat(result, buffer);
    }
    // Elimina el carácter de salto de línea si existe
/* 	size_t result_len = strlen(result);
    if (result_len > 0 && result[result_len - 1] == '\n')
    {
        result[result_len - 1] = '\0';
    } */
	//printf("result --> %s argv1 --> %s\n", result, argv1);
    if (pclose(fp) == -1)
    {
        perror("pclose");
        free(result);
        return (NULL);
    }
	//printf("Captured : %s", result);
	return (result);
}