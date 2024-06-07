/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paco.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaki <inaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:01:41 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/07 16:17:57 by inaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libzip.h"

int	paco_aff_a(int k, int show)
{
	char	*paco;

	paco = paco_argv1("aff_a", "abc");
	if ((strncmp(paco, "a", 1) == 0) && (strlen(paco) == 2))
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
	paco = paco_argv1("aff_a", "\"dubO a POIL\"");
	if ((strncmp(paco, "a", 1) == 0) && (strlen(paco) == 2))
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
	paco = paco_argv1("aff_a", "\"zz sent le poney\"");
	if ((strcmp(paco, "\n") == 0) && (strlen(paco) == 1))
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
	paco = paco_argv0("aff_a");
	if ((strncmp(paco, "a", 1) == 0) && (strlen(paco) == 2))
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

int	paco_aff_z(int k, int show)
{
	char	*paco;

	paco = paco_argv1("aff_z", "abc");
	if ((strncmp(paco, "z", 1) == 0) && (strlen(paco) == 2))
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
	paco = paco_argv1("aff_z", "\"dubO a POIL\"");
	if ((strncmp(paco, "z", 1) == 0) && (strlen(paco) == 2))
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
	paco = paco_argv1("aff_z", "\"zz sent le poney\"");
	if ((strncmp(paco, "z", 1) == 0) && (strlen(paco) == 2))
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
	paco = paco_argv0("aff_z");
	if ((strncmp(paco, "z", 1) == 0) && (strlen(paco) == 2))
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

#ifdef _FILE_FT_PUTSTR_C
int    paco_ft_putstr(int k, int show)
{
    #ifdef _FILE_FT_PUTSTR_C
    int stdout_fd = dup(STDOUT_FILENO);  // Duplicar stdout
    int pipe_fd[2];
    pipe(pipe_fd);
    dup2(pipe_fd[1], STDOUT_FILENO);  // Redirigir stdout al pipe
    close(pipe_fd[1]);

    // Llamar a la función ft_putstr
    ft_putstr("Hola Mundo!");

    // Restaurar stdout
    dup2(stdout_fd, STDOUT_FILENO);
    close(stdout_fd);

    // Leer desde el pipe
    char paco[100];
    int len = read(pipe_fd[0], paco, sizeof(paco) - 1);
    paco[len] = '\0';
    close(pipe_fd[0]);

    // Comparar la salida con el valor esperado
    if (strcmp(paco, "Hola Mundo!") == 0)
    {
        if (show == 1)
		{
			printf("%s ./ft_putstr(\"Hola Mundo!\") | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_putstr(\"Hola Mundo!\")\n", RED);
		printf("%s %s\n", RED, paco);
    }
	return (k);
    #else
    printf("ft_putstr.c not found. Skipping test.\n");
    #endif
}
#else
    int     paco_ft_putstr(int k, int show)
    {
        return (0);
    }
#endif

#ifdef _FILE_FT_STRLEN_C
int    paco_ft_strlen(int k, int show)
{
    #ifdef _FILE_FT_STRLEN_C
	 int i_ft_strlen;

	 i_ft_strlen = ft_strlen("Hola Mundo!");

    // Comparar la salida con el valor esperado
    if (i_ft_strlen == strlen("Hola Mundo!"))
    {
        if (show == 1)
		{
			printf("%s ./ft_strlen(\"Hola Mundo!\") | cat -e\n", GREEN);
			printf("%s %d\n", GREEN, i_ft_strlen);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_strlen(\"Hola Mundo!\")\n", RED);
		printf("%s %d\n", RED, i_ft_strlen);
    }
	return (k);
    #else
    printf("ft_strlen.c not found. Skipping test.\n");
    #endif
}
#else
    int     paco_ft_strlen(int k, int show)
    {
        return (0);
    }
#endif

int	paco_rev_print(int k, int show)
{
	
	char	*paco;

	paco = paco_argv1("rev_print", "zaz");
	if ((strncmp(paco, "zaz", 3) == 0) && (strlen(paco) == 4))
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
	paco = paco_argv1("rev_print", "\"dubO a POIL\"");
	if ((strncmp(paco, "LIOP a Obud", 11) == 0) && (strlen(paco) == 12))
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
	paco = paco_argv0("rev_print");
	if ((strcmp(paco, "\n") == 0) && (strlen(paco) == 1))
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

int	paco_fizzbuzz(int k, int show)
{
	char	*paco;

	paco = paco_argv0("fizzbuzz");
	if ((strncmp(paco, " 1\n2\nfizz\n4\nbbuzz\nfizz\n7\n8\nfizz\nbbuzz\n11\nfizz\n13\n14\nfizzbuzz\n16\n17\nfizz\n19\nbbuzz\nfizz\n22\n23\nfizz\nbbuzz\n26\nfizz\n28\n29\nfizzbuzz\n31\n32\nfizz\n34\nbbuzz\nfizz\n37\n38\nfizz\nbbuzz\n41\nfizz\n43\n44\nfizzbuzz\n46\n47\nfizz\n49\nbbuzz\nfizz\n52\n53\nfizz\nbbuzz\n56\nfizz\n58\n59\nfizzbuzz\n61\n62\nfizz\n64\nbbuzz\nfizz\n67\n68\nfizz\nbbuzz\n71\nfizz\n73\n74\nfizzbuzz\n76\n77\nfizz\n79\nbbuzz\nfizz\n82\n83\nfizz\nbbuzz\n86\nfizz\n88\n89\nfizzbuzz\n91\n92\nfizz\n94\nbbuzz\nfizz\n97\n98\nfizz\nbbuzz", 0) == 0)
		 && (strlen(paco) == 413))
	{
		if (show == 1)
		{
			printf("%s ./fizzbuzz | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./fizzbuzz | cat -e\n", RED);
		printf("%s %s %ld\n", RED, paco, strlen(paco));
	}
	free(paco);
	return (k);
}

int	paco_aff_first_param(int k, int show)
{
	char	*paco;

	paco = paco_argv1("aff_first_param", "vincent");
	if ((strncmp(paco, "vincent", 7) == 0) && (strlen(paco) == 8))
	{
		if (show == 1)
		{
			printf("%s ./aff_first_param vincent mit \"l'ane\" dans un pre et \"s'en\" vint | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_first_param vincent mit \"l'ane\" dans un pre et \"s'en\" vint | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("aff_first_param", "\"j'aime le fromage de chevre\"");
	if ((strncmp(paco, "j'aime le fromage de chevre", 27) == 0) && (strlen(paco) == 28))
	{
		if (show == 1)
		{
			printf("%s ./aff_first_param \"j'aime le fromage de chevre\" | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_first_param \"j'aime le fromage de chevre\" | cat -e\n", RED);
		printf("%s %s %ld\n", RED, paco, strlen(paco));
	}
	free(paco);
	paco = paco_argv0("aff_first_param");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./aff_first_param | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_first_param | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	return (k);
}

/******************************************** */
int	paco_ok(char *name, char *argv1, int i, int show)
{
	int		k;
	char	*paco;

	k = i;
	paco = paco_argv1(name, argv1);
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

char	*paco_argv0(char *name)
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

char	*paco_argv1(char *name, char *argv1)
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