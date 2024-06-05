/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_ok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaki <inaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:43:15 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/05 23:47:33 by inaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mylib.h"

int	ft_input_ok(void)
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

/** int	ft_input_ok(void)
 {
	char	input[100];

	printf("%s Escribe \"ok\" para que Molintte te deje", CYAN);
	printf("%s pasar al siguiente nivel.\n", CYAN);
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
*/
