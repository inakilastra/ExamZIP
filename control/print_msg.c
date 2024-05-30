/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:50:34 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/30 12:54:25 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

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

void    print_msg (const char *str1, const char *sfile)
{
	char        *username = getlogin();
    time_t      current_time;
    struct tm   *time_info;
    char        currentPath[MAX_PATH];
    char        *currentDirPath = getcwd(currentPath, MAX_PATH);
		
	time(&current_time);
    time_info = localtime(&current_time);
	if (strncmp(str1, "start", 5) == 0)
		printf("%s\n Prueba a poner: ./grademe \"start\" para empezar\n\n", RED);
	if (strncmp(str1, "empezamos", 9) == 0)
	{
		printf("%s\n You're connected: %s%s\n", WHITE, GREEN, username); 
		printf("%s You can log out at any time.", WHITE); 
		printf("%s If this program tells you you earned points\n", WHITE);
		printf("%s then they will be counted whatever happens.\n\n", WHITE);
		printf("%s You are about to start the project %sExam ZIP%s, in %sPRACTICE%s mode, at level.\n", WHITE, GREEN, WHITE, MAGENTA, WHITE);
		printf("%s You would have 3hrs to complete this project.\n", WHITE);
		printf("%s Start exam ZIP --> ", WHITE);     
		printf("%s %s\n\n", GREEN, control_date());
		printf("%s =====================================================================================\n", WHITE);
		printf("%s Mode: %sPRACTICE ZIP\n\n", WHITE, MAGENTA);
	}
	if (strncmp(str1, "questionX", 9) == 0)
	{
		print_msg ("empezamos", "");
		printf("%s Assignement: %s%s.c\n\n", WHITE, GREEN, sfile);
		printf("%s Subject location: %s%s/subjects/%s.txt\n", WHITE, GREEN, currentDirPath, sfile); 
		printf("%s Exercice location: %s%s/rendu/%s/\n", WHITE, RED, currentDirPath, sfile); 
		printf("%s Here you %sdon't need%s to use git.\n\n", WHITE, RED, WHITE); 
		printf("%s End date: %s06/09/2022 20:00:26\n", WHITE, GREEN);
		printf("%s Left time: %s2hrs, 59min and 48sec\n\n", WHITE, GREEN);
		printf("%s =====================================================================================\n", WHITE);
		printf("%s You can work on your assignesent.\n When you are sure you're done with it, use the \"./grademe\" command to be graded.\n", WHITE);
	}
}
