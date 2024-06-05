/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_ok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:43:15 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/05 17:15:47 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mylib.h"

int	ft_input_ok(void)
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
			printf("%s Excelente deducción. Al parecer, posees la ", GREEN);
			printf("%s capacidad básica de seguir instrucciones.\n", GREEN);
			printf("%s Bienvenid@ a mi humilde morada.\n", YELLOW);
			break ;
		}
		else
		{
			printf("%s ¡Oh, por el amor de Stephen Hawking!\n", YELLOW);
			printf("%s Escribe \"ok\" o te convertiré en un ", YELLOW);
			printf("%s experimento social.\n", YELLOW);
		}
	}
	return (0);
}
/** int	input_ok(void)
{
	char	input[100];

	printf("Escribe 'ok' para continuar:\n");
	// Leer la entrada del usuario
    while (1) 
	{
        // Limpiar el buffer de entrada
		fgets(input, sizeof(input), stdin);
        // Eliminar el carácter de nueva línea que fgets agrega
		input[strcspn(input, "\n")] = 0;
        // Comparar la entrada con "ok"
		if (strcmp(input, "ok") == 0)
		{
			printf("Has escrito 'ok'. Continuando...\n");
			break ;
        }
		else
			printf("Entrada no válida. Por favor, escribe 'ok':\n");
    }
    return (0);
}
*/


/**
 * "Escribe 'ok' para continuar... o te explicaré la teoría de la relatividad en detalle."
"Has escrito 'ok'. ¡Excelente! Ahora eres digno de entrar en mi guarida."
"Entrada no válida. Por favor, escribe 'ok' o te convertiré en un experimento social."
*/