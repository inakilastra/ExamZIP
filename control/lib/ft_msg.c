/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:57:21 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/06 16:00:14 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libzip.h"

int	ft_success_del_subject(char *name, int show, int i)
{
	char	subject[128];

	snprintf(subject, sizeof(subject), "subjects/%s.txt", name);
	if (ft_check_file(subject) == 0)
	{
		if (remove(subject) == 0)
			printf("\n");
		else
			perror("Error deleting the file");
	}
	if (show == 1)
		ctr_txt("control/ctrl_penal.txt", 'W', 'P', 0, "");
	else
		ctr_txt("control/ctrl_penal.txt", 'W', 'R', 0, "");
	printf("%s\n >>>>>>>>>> SUCCESS <<<<<<<<<<\n\n", GREEN);
	return (i);
}

void	ft_failure(int show)
{
	if (show == 1)
		ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, "");
	else
		ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
	printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n", RED);
	printf("%s You have falled the assignement.\n\n", WHITE);
}
void	ft_failure_check_file(char *name, int show)
{
	char	subject[128];
	char	rendu[128];
	char	rendu_c[128];
	char	question[128];

	snprintf(subject, sizeof(subject), "subjects/%s.txt", name);
	snprintf(rendu, sizeof(rendu), "rendu/%s", name);
	snprintf(rendu_c, sizeof(rendu_c), "rendu/%s/%s.c", name, name);
	snprintf(question, sizeof(question), "questions/%s.txt", name);
	if ((ft_check_file(subject) == 0)
		&& (ft_check_file(rendu) == 0)
		&& (ft_check_file(rendu_c) != 0))
	{
		if (show == 1)
		{
			ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, "");
			printf(" No existe: %s\n\n", rendu_c);
		}
		else
			ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
		printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n", RED);
		printf("%s You have falled the assignement.\n\n", WHITE); 
	}
	if (ft_check_file(subject) != 0)
		ft_copy_file(question, subject);
	if (ft_check_file(rendu) != 0)
		ft_new_folder(rendu); 
}
