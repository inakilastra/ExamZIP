/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_ok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaki <inaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:43:15 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/09 17:18:32 by inaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libzip.h"

void	ft_input_write(void)
{
	printf("\n");
	printf("%s╔══════════════════════════════════════════════════╗\n", CYAN);
	printf("%s║ Escribe \"ok\"                                     ║\n", CYAN);
	printf("%s║ Para que Moulinette te deje avanzar al nivel 42. ║\n", CYAN);
	printf("%s╚══════════════════════════════════════════════════╝\n", CYAN);
	printf("\n");
}

void	ft_input_rewrite(void)
{
	printf("\n");
	printf("%s╔════════════════════════════════════════════════╗\n", YELLOW);
	printf("%s║ Tu respuesta no cumple Norminette.             ║\n", YELLOW);
	printf("%s║ Moulinette espera impaciente tu examen.        ║\n", YELLOW);
	printf("%s║ Escribe \"ok\" que el tiempo no corre, VUELA...  ║\n", YELLOW);
	printf("%s╚════════════════════════════════════════════════╝\n", YELLOW);
	printf("\n");
}

void	ft_input_go(void)
{
	printf("\n");
	printf("%s╔═════════════════════════════════════════════════════════════════╗\n", GREEN);
	printf("%s║ Excelente deducción.                                            ║\n", GREEN);
	printf("%s║ Al parecer, tienes la capacidad básica de seguir instrucciones. ║\n", GREEN);
	printf("%s║ Continuamos, agárrate a la silla.                               ║\n", GREEN);
	printf("%s╚═════════════════════════════════════════════════════════════════╝\n", GREEN);
	printf("\n");
}

int	ft_input_ok(void)
{
	char	input[100];

	ft_input_write();
	while (1)
	{
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = 0;
		if (strcmp(input, "ok") == 0)
		{
			ft_input_go();
			sleep(4);
			break ;
		}
		else
			ft_input_rewrite();
	}
	return (0);
}
