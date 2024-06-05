/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaki <inaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:42:57 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/05 23:49:03 by inaki            ###   ########.fr       */
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


# ifdef _FILE_FT_INPUT_OK_C
#  include "control/lib/ft_input_ok.c"
# else
	int	ft_input_ok_fallback(void)
	{
		char	input[100];

		printf("%s Escribe \"ok\" para que Molintte te deje", CYAN);
		printf("%s pasar al siguiente nivel.\n", CYAN);
		while (1)
		{
			fgets(input, sizeof(input), stdin);
			input[strcspn(input, "\n")] = 0;
			if (strcmp(input, "ok") == 0)
			{
				printf("%s Excelente deducción. Al parecer, posees la ", GREEN);
				printf("%s capacidad básica de seguir instrucciones.\n", GREEN);
				break ;
			}
			else
			{
				printf("%s \"%s\" no cumple Norminette\n", YELLOW, input);
				printf("%s Escribe \"ok\" el tiempo corre...\n", YELLOW);
			}
		}
		return (0);
	}
    #define ft_input_ok ft_input_ok_fallback
# endif

int ft_input_ok(void);

#endif
