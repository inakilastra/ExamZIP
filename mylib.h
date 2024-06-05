/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:42:57 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/05 17:20:07 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRADEME_H
# define LIBGRADEME_H

# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>

#define DEF_COLOR "\033[0;39m"
#define GRAY "\033[0;90m"
#define RED "\033[0;91m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define BLUE "\033[0;94m"
#define MAGENTA "\033[0;95m"
#define CYAN "\033[0;96m"
#define WHITE "\033[0;97m"
#define MAX_PATH 4096
#define MAX_LINE_LENGTH 256
#define BUFFER_SIZE 128


#ifndef _FILE_FT_INPUT_OK_H
#define _FILE_FT_INPUT_OK_H

# ifdef _FILE_FT_INPUT_OK_C
#  define FT_INPUT_OK_C_PATH __FILE__ "/control/lib/ft_input_ok.c"
#  include FT_INPUT_OK_C_PATH
# else
	int	ft_input_ok_fallback(void)
	{
		char	input[100];

		printf("%s Sheldon Cooper dice:\n", CYAN);
		printf("%s Escribe \"ok\" para continuar... o te explicaré la", CYAN);
		printf("%s  teoría de la relatividad en detalle.\n", CYAN);
		while (1)
		{
			fgets(input, sizeof(input), stdin);
			input[strcspn(input, "\n")] = 0;
			if (strcmp(input, "ok") == 0)
			{
				printf("Perfecto Has escrito \"ok\".\n");
				break ;
			}
			else
				printf("Sólo escribe \"ok\":\n\n");
		}
		return (0);
	}
    #define ft_input_ok ft_input_ok_fallback
# endif
# endif

int ft_input_ok(void);

#endif
