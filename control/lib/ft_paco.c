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
			printf("%s %s", GREEN, paco);
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
			printf("%s %s", GREEN, paco);
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
			printf("%s %s", GREEN, paco);
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
			printf("%s %s", GREEN, paco);
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
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_z \"abc\" | cat -e\n", RED);
		printf("%s %s", RED, paco);
	}
	free(paco);
	paco = paco_argv1("aff_z", "\"dubO a POIL\"");
	if ((strncmp(paco, "z", 1) == 0) && (strlen(paco) == 2))
	{
		if (show == 1)
		{
			printf("%s ./aff_z \"dubO a POIL\" | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
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
			printf("%s %s", GREEN, paco);
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
			printf("%s %s", GREEN, paco);
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
			printf("%s %s", GREEN, paco);
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
	void   ft_putstr(char *str)
	{

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
			printf("%s %d", GREEN, i_ft_strlen);
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
	int	ft_strlen(char *str)
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
			printf("%s %s", GREEN, paco);
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
			printf("%s %s", GREEN, paco);
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
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./rev_print | cat -e\n", RED);
		printf("%s %s", RED, paco);
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
			printf("%s%s", GREEN, paco);
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
int	paco_buzzfizz(int k, int show)
{
	char	*paco;

	paco = paco_argv0("buzzfizz");
	if ((strncmp(paco, " 1\n2\n3\nbuzz\n5\n6\nfizz\nbuzz\n9\n10\n11\nbuzz\n13\nfizz\n15\nbuzz\n17\n18\n19\nbuzz\nfizz\n22\n23\nbuzz\n25\n26\n27\nfizzbuzz\n29\n30\n31\nbuzz\n33\n34\nfizz\nbuzz\n37\n38\n39\nbuzz\n41\nfizz\n43\nbuzz\n45\n46\n47\nbuzz\nfizz\n50\n51\nbuzz\n53\n54\n55\nfizzbuzz\n57\n58\n59\nbuzz\n61\n62\nfizz\nbuzz\n65\n66\n67\nbuzz\n69\nfizz\n71\nbuzz\n73\n74\n75\nbuzz\nfizz\n78\n79\nbuzz\n81\n82\n83\nfizzbuzz\n85\n86\n87\nbuzz\n89\n90\nfizz\nbuzz\n93\n94\n95\nbuzz\n97\nfizz\n99\nbuzz", 0) == 0)
		 && (strlen(paco) == 378))
	{
		if (show == 1)
		{
			printf("%s ./buzzfizz | cat -e\n", GREEN);
			printf("%s%s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./buzzfizz | cat -e\n", RED);
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
			printf("%s %s", GREEN, paco);
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
			printf("%s %s", GREEN, paco);
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
			printf("%s %s", GREEN, paco);
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

int	paco_aff_last_param(int k, int show)
{
	char	*paco;

	paco = paco_argv1("aff_last_param", "\"zaz\" \"mange\" \"des\" \"chats\"");
	if ((strncmp(paco, "chats", 5) == 0) && (strlen(paco) == 6))
	{
		if (show == 1)
		{
			printf("%s ./aff_last_param \"zaz\" \"mange\" \"des\" \"chats\"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_last_param \"zaz\" \"mange\" \"des\" \"chats\"\"s'en\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("aff_last_param", "\"j'aime le savon\"");
	if ((strncmp(paco, "j'aime le savon", 15) == 0) && (strlen(paco) == 16))
	{
		if (show == 1)
		{
			printf("%s ./aff_last_param \"j'aime le savon\" | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_last_param \"j'aime le savon\" | cat -e\n", RED);
		printf("%s %s %ld\n", RED, paco, strlen(paco));
	}
	free(paco);
	paco = paco_argv0("aff_last_param");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./aff_last_param | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./aff_last_param | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	return (k);
}

int	paco_rotone(int k, int show)
{
	char	*paco;

	paco = paco_argv1("rotone", "\"abc\"");
	if ((strncmp(paco, "bcd", 3) == 0) && (strlen(paco) == 4))
	{
		if (show == 1)
		{
			printf("%s ./rotone \"abc\"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./rotone \"abc\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("rotone", "\"Les stagiaires du staff ne sentent pas toujours tres bon.\"");
	if ((strncmp(paco, "Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.", 57) == 0) && (strlen(paco) == 58))
	{
		if (show == 1)
		{
			printf("%s ./rotone \"Les stagiaires du staff ne sentent pas toujours tres bon.\" | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./rotone \"Les stagiaires du staff ne sentent pas toujours tres bon.\" | cat -e\n", RED);
		printf("%s %s %ld\n", RED, paco, strlen(paco));
	}
	free(paco);
	paco = paco_argv1("rotone", "\"AkjhZ zLKIJz , 23y \"");
	if ((strncmp(paco, "BlkiA aMLJKa , 23z ", 19) == 0) && (strlen(paco) == 20))
	{
		if (show == 1)
		{
			printf("%s ./rotone \"AkjhZ zLKIJz , 23y \"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./rotone \"AkjhZ zLKIJz , 23y \" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("rotone", "\"\"");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./rotone \"\"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./rotone \"\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv0("rotone");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./rotone | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./rotone | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	return (k);
}

int	paco_first_word(int k, int show)
{
	char	*paco;

	paco = paco_argv1("first_word", "\"FOR PONY\"");
	if ((strncmp(paco, "FOR", 3) == 0) && (strlen(paco) == 4))
	{
		if (show == 1)
		{
			printf("%s ./first_word \"FOR PONY\"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./first_word \"FOR PONY\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("first_word", "\"this        ...       is sparta, then again, maybe    not\"");
	if ((strncmp(paco, "this", 4) == 0) && (strlen(paco) == 5))
	{
		if (show == 1)
		{
			printf("%s ./first_word \"this        ...       is sparta, then again, maybe    not\"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./first_word \"this        ...       is sparta, then again, maybe    not\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("first_word", "\"   \"");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./first_word \"   \"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./first_word \"   \" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("first_word", "\"a\" \"b\"");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./first_word \"a\" \"b\"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./first_word \"a\" \"b\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("first_word", "\"  lorem,ipsum  \"");
	if ((strncmp(paco, "lorem,ipsum", 11) == 0) && (strlen(paco) == 12))
	{
		if (show == 1)
		{
			printf("%s ./first_word \"  lorem,ipsum  \"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./first_word \"  lorem,ipsum  \" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	return (k);
}

int	paco_rot_13(int k, int show)
{
	char	*paco;

	paco = paco_argv1("rot_13", "\"abc\"");
	if ((strncmp(paco, "nop", 3) == 0) && (strlen(paco) == 4))
	{
		if (show == 1)
		{
			printf("%s ./rot_13 \"abc\"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./rot_13 \"abc\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("rot_13", "\"My horse is Amazing.\"");
	if ((strncmp(paco, "Zl ubefr vf Nznmvat.", 20) == 0) && (strlen(paco) == 21))
	{
		if (show == 1)
		{
			printf("%s ./rot_13 \"My horse is Amazing.\" | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./rot_13 \"My horse is Amazing.\" | cat -e\n", RED);
		printf("%s %s %ld\n", RED, paco, strlen(paco));
	}
	free(paco);
	paco = paco_argv1("rot_13", "\"AkjhZ zLKIJz , 23y \"");
	if ((strncmp(paco, "NxwuM mYXVWm , 23l ", 19) == 0) && (strlen(paco) == 20))
	{
		if (show == 1)
		{
			printf("%s ./rot_13 \"AkjhZ zLKIJz , 23y \"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./rot_13 \"AkjhZ zLKIJz , 23y \" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("rot_13", "\"\"");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./rot_13 \"\"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./rot_13 \"\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv0("rot_13");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./rot_13 | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./rot_13 | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	return (k);
}

int	paco_last_word(int k, int show)
{
	char	*paco;

	paco = paco_argv1("last_word", "\"FOR PONY\"");
	if ((strncmp(paco, "PONY", 4) == 0) && (strlen(paco) == 5))
	{
		if (show == 1)
		{
			printf("%s ./last_word \"FOR PONY\"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./last_word \"FOR PONY\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("last_word", "\"this        ...       is sparta, then again, maybe    not\"");
	if ((strncmp(paco, "not", 3) == 0) && (strlen(paco) == 4))
	{
		if (show == 1)
		{
			printf("%s ./last_word \"this        ...       is sparta, then again, maybe    not\"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./last_word \"this        ...       is sparta, then again, maybe    not\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("last_word", "\"   \"");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./last_word \"   \"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./last_word \"   \" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("last_word", "\"a\" \"b\"");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./last_word \"a\" \"b\"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./last_word \"a\" \"b\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("last_word", "\"  lorem,ipsum  \"");
	if ((strncmp(paco, "lorem,ipsum", 11) == 0) && (strlen(paco) == 12))
	{
		if (show == 1)
		{
			printf("%s ./last_word \"  lorem,ipsum  \"| cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./last_word \"  lorem,ipsum  \" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	return (k);
}

int	paco_inter(int k, int show)
{
	char	*paco;

	paco = paco_argv1("inter", "\"padinton\" \"paqefwtdjetyiytjneytjoeyjnejeyj\"");
	if ((strncmp(paco, "padinto", 7) == 0) && (strlen(paco) == 8))
	{
		if (show == 1)
		{
			printf("%s ./inter \"padinton\" \"paqefwtdjetyiytjneytjoeyjnejeyj\" | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./inter \"padinton\" \"paqefwtdjetyiytjneytjoeyjnejeyj\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("inter", "ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd");
	if ((strncmp(paco, "df6ewg4", 7) == 0) && (strlen(paco) == 8))
	{
		if (show == 1)
		{
			printf("%s ./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("inter", "\"rien\" \"cette phrase ne cache rien\"");
	if ((strncmp(paco, "rien", 4) == 0) && (strlen(paco) == 5))
	{
		if (show == 1)
		{
			printf("%s ./inter \"rien\" \"cette phrase ne cache rien\" | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./inter \"rien\" \"cette phrase ne cache rien\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv0("inter");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./inter | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./inter | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	return (k);
}

int	paco_union(int k, int show)
{
	char	*paco;

	paco = paco_argv1("union", "zpadinton \"paqefwtdjetyiytjneytjoeyjnejeyj\"");
	if ((strncmp(paco, "zpadintoqefwjy", 14) == 0) && (strlen(paco) == 15))
	{
		if (show == 1)
		{
			printf("%s ./union zpadinton \"paqefwtdjetyiytjneytjoeyjnejeyj\" | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./union zpadinton \"paqefwtdjetyiytjneytjoeyjnejeyj\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("union", "ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd");
	if ((strncmp(paco, "df6vewg4thras", 13) == 0) && (strlen(paco) == 14))
	{
		if (show == 1)
		{
			printf("%s ./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("union", "\"rien\" \"cette phrase ne cache rien\"");
	if ((strncmp(paco, "rienct phas", 11) == 0) && (strlen(paco) == 12))
	{
		if (show == 1)
		{
			printf("%s ./union \"rien\" \"cette phrase ne cache rien\" | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./union \"rien\" \"cette phrase ne cache rien\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("union", "\"rien\"");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./union \"rien\" | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./union \"rien\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv0("union");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./union | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./union | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	return (k);
}

#ifdef _FILE_FT_ITOA_C
int    paco_ft_itoa(int k, int show)
{
    #ifdef _FILE_FT_ITOA_C
	int ok;
	char *paco;

	ok = 0;
	paco = ft_itoa(-2147483648);
	if ((strncmp(paco, "-2147483648", 11) == 0) || (strlen(paco) == 12))
		ok = 1;
    if (ok == 1)
    {
        if (show == 1)
		{
			printf("%s ./ft_itoa(-2147483648) | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_itoa(-2147483648)\n", RED);
		printf("%s %s\n", RED, paco);
    }
	free(paco);		
	paco = ft_itoa(2147483647);
	if ((strncmp(paco, "2147483647", 10) == 0) || (strlen(paco) == 11))
		ok = 1;
    if (ok == 1)
    {
        if (show == 1)
		{
			printf("%s ./ft_itoa(2147483647) | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_itoa(2147483647)\n", RED);
		printf("%s %s\n", RED, paco);
    }		
	free(paco);	
	paco = ft_itoa(0);
	if ((strncmp(paco, "0", 1) == 0) || (strlen(paco) == 2))
		ok = 1;
    if (ok == 1)
    {
        if (show == 1)
		{
			printf("%s ./ft_itoa(0) | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_itoa(0)\n", RED);
		printf("%s %s\n", RED, paco);
    }
	free(paco);	
	paco = ft_itoa(123);
	if ((strncmp(paco, "2147483647", 10) == 0) || (strlen(paco) == 11))
		ok = 1;
    if (ok == 1)
    {
        if (show == 1)
		{
			printf("%s ./ft_itoa(123) | cat -e\n", GREEN);
			printf("%s %s\n", GREEN, paco);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_itoa(123)\n", RED);
		printf("%s %s\n", RED, paco);
    }	
	free(paco);	
	return (k);
    #else
    	printf("ft_itoa.c not found. Skipping test.\n");
    #endif
}
#else
    int     paco_ft_itoa(int k, int show)
    {
        return (0);
    }
	char	*ft_itoa(int nbr)
	{
		return (NULL);
	}
#endif

#ifdef _FILE_FT_RRANGE_C
int    paco_ft_rrange(int k, int show)
{
    #ifdef _FILE_FT_RRANGE_C
	int ok;
	int *prueba;

	ok = 0;
	prueba = ft_rrange(1, 3);
	if(prueba[0] != 3
		|| prueba[1] != 2
		|| prueba[2] != 1)
		ok = 1;
    if (ok == 0)
    {
        if (show == 1)
		{
			printf("%s ./ft_rrange(1, 3) | cat -e\n", GREEN);
			printf("%s %d, %d, %d\n", GREEN, prueba[0], prueba[1], prueba[2]);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_rrange(1, 3)\n", RED);
		printf("%s %d, %d, %d\n", RED, prueba[0], prueba[1], prueba[2]);
    }		
	free(prueba);	
	prueba = ft_rrange(-1, 2);
	if(prueba[0] != 2
		|| prueba[1] != 1
		|| prueba[2] != 0
		|| prueba[3] != -1)
		ok = 1;
    if (ok == 0)
    {
        if (show == 1)
		{
			printf("%s ./ft_rrange(-1, 2) | cat -e\n", GREEN);
			printf("%s %d, %d, %d, %d\n", GREEN, prueba[0], prueba[1], prueba[2], prueba[3]);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_rrange(-1, 2)\n", RED);
		printf("%s %d, %d, %d, %d\n", RED, prueba[0], prueba[1], prueba[2], prueba[3]);
    }
	free(prueba);
	prueba = ft_rrange(0, 0);
	if(prueba[0] != 0)
		ok = 1;
    if (ok == 0)
    {
        if (show == 1)
		{
			printf("%s ./ft_rrange(0, 0) | cat -e\n", GREEN);
			printf("%s %d\n", GREEN, prueba[0]);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_rrange(0, 0)\n", RED);
		printf("%s %d\n", RED, prueba[0]);
    }
	free(prueba);
	prueba = ft_rrange(0, -3);
	if(prueba[0] != -3
		|| prueba[1] != -2
		|| prueba[2] != -1
		|| prueba[3] != 0)
		ok = 1;
    if (ok == 0)
    {
        if (show == 1)
		{
			printf("%s ./ft_rrange(0, -3) | cat -e\n", GREEN);
			printf("%s %d, %d, %d, %d\n", GREEN, prueba[0], prueba[1], prueba[2], prueba[3]);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_rrange(0, -3)\n", RED);
		printf("%s %d, %d, %d, %d\n", RED, prueba[0], prueba[1], prueba[2], prueba[3]);
    }
	free(prueba);
	return (k);
    #else
    printf("ft_rrange.c not found. Skipping test.\n");
    #endif
}
#else
    int     paco_ft_rrange(int k, int show)
    {
        return (0);
    }
	int    *ft_rrange(int start, int end)
	{
		return (0);
	}
#endif

#ifdef _FILE_FT_RANGE_C
int    paco_ft_range(int k, int show)
{
    #ifdef _FILE_FT_RANGE_C
	int ok;
	int *prueba;

	ok = 0;
	prueba = ft_range(1, 3);
	if(prueba[0] != 1
		|| prueba[1] != 2
		|| prueba[2] != 3)
		ok = 1;
    if (ok == 0)
    {
        if (show == 1)
		{
			printf("%s ./ft_range(1, 3) | cat -e\n", GREEN);
			printf("%s %d, %d, %d\n", GREEN, prueba[0], prueba[1], prueba[2]);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_range(1, 3)\n", RED);
		printf("%s %d, %d, %d\n", RED, prueba[0], prueba[1], prueba[2]);
    }
	free(prueba);
	prueba = ft_range(-1, 2);
	if(prueba[0] != -1
		|| prueba[1] != 0
		|| prueba[2] != 1
		|| prueba[3] != 2)
		ok = 1;
    if (ok == 0)
    {
        if (show == 1)
		{
			printf("%s ./ft_range(-1, 2) | cat -e\n", GREEN);
			printf("%s %d, %d, %d, %d\n", GREEN, prueba[0], prueba[1], prueba[2], prueba[3]);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_range(-1, 2)\n", RED);
		printf("%s %d, %d, %d, %d\n", RED, prueba[0], prueba[1], prueba[2], prueba[3]);
    }
	free(prueba);
	prueba = ft_range(0, 0);
	if(prueba[0] != 0)
		ok = 1;
    if (ok == 0)
    {
        if (show == 1)
		{
			printf("%s ./ft_range(0, 0) | cat -e\n", GREEN);
			printf("%s %d\n", GREEN, prueba[0]);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_range(0, 0)\n", RED);
		printf("%s %d\n", RED, prueba[0]);
    }
	free(prueba);
	prueba = ft_range(0, -3);
	if(prueba[0] != 0
		|| prueba[1] != -1
		|| prueba[2] != -2
		|| prueba[3] != -3)
		ok = 1;
    if (ok == 0)
    {
        if (show == 1)
		{
			printf("%s ./ft_range(0, -3) | cat -e\n", GREEN);
			printf("%s %d, %d, %d, %d\n", GREEN, prueba[0], prueba[1], prueba[2], prueba[3]);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_range(0, -3)\n", RED);
		printf("%s %d, %d, %d, %d\n", RED, prueba[0], prueba[1], prueba[2], prueba[3]);
    }
	free(prueba);
	return (k);
    #else
    	printf("ft_range.c not found. Skipping test.\n");
    #endif
}
#else
    int     paco_ft_range(int k, int show)
    {
        return (0);
    }
	int    *ft_range(int start, int end)
	{
		return (0);
	}
#endif

int	paco_expand_str(int k, int show)
{
	char	*paco;

	paco = paco_argv1("expand_str", "\"vous   voyez   c'est   facile   d'afficher   la   meme   chose\"");
	if ((strncmp(paco, "vous   voyez   c'est   facile   d'afficher   la   meme   chose", 62) == 0) && (strlen(paco) == 63))
	{
		if (show == 1)
		{
			printf("%s ./expand_str \"vous   voyez   c'est   facile   d'afficher   la   meme   chose\" | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./expand_str \"vous   voyez   c'est   facile   d'afficher   la   meme   chose\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("expand_str", "\" seulement          la c'est      plus dur \"");
	if ((strncmp(paco, "seulement   la   c'est   plus   dur", 35) == 0) && (strlen(paco) == 36))
	{
		if (show == 1)
		{
			printf("%s ./expand_str \" seulement          la c'est      plus dur \" | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./expand_str \" seulement          la c'est      plus dur \" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("expand_str", "\"comme c'est cocasse\" \"vous avez entendu, Mathilde ?\"");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./expand_str \"comme c'est cocasse\" \"vous avez entendu, Mathilde ?\" | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./expand_str \"comme c'est cocasse\" \"vous avez entendu, Mathilde ?\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	paco = paco_argv1("expand_str", "");
	if (strcmp(paco, "\n") == 0)
	{
		if (show == 1)
		{
			printf("%s ./expand_str \"\" | cat -e\n", GREEN);
			printf("%s %s", GREEN, paco);
		}
		k++;
	}
	else
	{
		printf("%s ./expand_str \"\" | cat -e\n", RED);
		printf("%s %s\n", RED, paco);
	}
	free(paco);
	return (k);
}

#ifdef _FILE_FT_SPLIT_C
int    paco_ft_split(int k, int show)
{
    #ifdef _FILE_FT_SPLIT_C
	int ok;
	char **paco;

	ok = 0;
	paco = ft_split("Hola Mundo");
	if((strncmp(paco[0], "Hola", 4) == 0)
		&& (strncmp(paco[1], "Mundo", 5) == 0))
		ok = 1;
    if (ok == 1)
    {
        if (show == 1)
		{
			printf("%s ./ft_split(\"Hola Mundo\") | cat -e\n", GREEN);
			printf("%s %s \n", GREEN, paco[0]);
			printf("%s %s \n", GREEN, paco[1]);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_split(\"Hola Mundo\") | cat -e\n", RED);
		printf("%s %s \n", RED, paco[0]);
		printf("%s %s \n", RED, paco[1]);
    }
	free(paco);
	paco = ft_split("Cada palabra una linea");
	if((strncmp(paco[0], "Cada", 4) == 0)
		&& (strncmp(paco[1], "palabra", 7) == 0)
		&& (strncmp(paco[2], "una", 3) == 0)
		&& (strncmp(paco[3], "linea", 15) == 0))
		ok = 1;
    if (ok == 1)
    {
        if (show == 1)
		{
			printf("%s ./ft_split(\"Cada palabra una linea\") | cat -e\n", GREEN);
			printf("%s %s \n", GREEN, paco[0]);
			printf("%s %s \n", GREEN, paco[1]);
			printf("%s %s \n", GREEN, paco[2]);
			printf("%s %s \n", GREEN, paco[3]);
		}
		k++;
    }
    else
    {
		printf("%s ./ft_split(\"Cada palabra una linea\") | cat -e\n", RED);
		printf("%s %s \n", RED, paco[0]);
		printf("%s %s \n", RED, paco[1]);
		printf("%s %s \n", RED, paco[2]);
		printf("%s %s \n", RED, paco[3]);
    }
	free(paco);
	return (k);
    #else
    	printf("ft_split.c not found. Skipping test.\n");
    #endif
}
#else
    int     paco_ft_split(int k, int show)
    {
        return (0);
    }
	char    **ft_split(char *str)
	{
		return (NULL);
	}
#endif

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