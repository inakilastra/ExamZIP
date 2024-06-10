/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:57:21 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/10 08:27:17 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libzip.h"

int	ft_success_del_subject(char *name, int show, int i, int grade)
{
	char	subject[128];

	snprintf(subject, sizeof(subject), "subjects/%s.txt", name);
	if (ft_check_file(subject) == 0)
	{
		if (remove(subject) == 0)
			printf(" ");
		else
			perror("Error deleting the file");
	}
	if (show == 1)
		ctr_txt("control/ctrl_penal.txt", 'W', 'P', 0, "");
	else
		ctr_txt("control/ctrl_penal.txt", 'W', 'R', 0, "");
	grade += 25;
	ctr_txt("control/ctrl_grade.txt", 'W', 'P', grade, "");
	ctr_txt("control/ctrl_try.txt", 'W', 'P', 0, "");		
	printf("%s >>>>>>>>>> SUCCESS <<<<<<<<<<\n", GREEN);
	return (i);
}

void	ft_failure(int show, int try)
{
	if (show == 1)
		ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, "");
	else
		ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
	try += 1;
	ctr_txt("control/ctrl_try.txt", 'W', 'P', try, "");		
	printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n", RED);
	printf("%s You have falled the assignement. Try: %s %d\n\n", WHITE, YELLOW, try);
}
void	ft_failure_check_file(char *name, int show, int try)
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
		try++;
		ctr_txt("control/ctrl_try.txt", 'W', 'P', try, "");				
		printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n", RED);
		printf("%s You have falled the assignement. Try: %s %d\n\n", WHITE, YELLOW, try); 
	}
	if (ft_check_file(subject) != 0)
		ft_copy_file(question, subject);
	if (ft_check_file(rendu) != 0)
		ft_new_folder(rendu); 
}
