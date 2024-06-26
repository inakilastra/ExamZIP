/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:57:21 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/26 15:09:39 by ilastra-         ###   ########.fr       */
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
	printf("%s\n >>>>>>>>>> SUCCESS <<<<<<<<<<\n", GREEN);
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

void replaceHomeWithTilde(char *path)
{
    char *homeDir = getenv("HOME");
    if (homeDir && strstr(path, homeDir) == path) {
        char tempPath[MAX_PATH];
        snprintf(tempPath, sizeof(tempPath), "~%s", path + strlen(homeDir));
        strcpy(path, tempPath);
    }
}

void    print_msg (const char *str1, const char *sfile)
{
	char        *username = getlogin();
    char        currentPath[MAX_PATH];
    char        *currentDirPath = getcwd(currentPath, MAX_PATH);
    char         *mode;
	char         *type;
    int         grade;
    int         try;

    mode = ctr_txt("control/ctrl_mode.txt", 'G', 'P', 0, "");
    grade = atoi(ctr_txt("control/ctrl_grade.txt", 'G', 'P', 0, ""));
    try = atoi(ctr_txt("control/ctrl_try.txt", 'G', 'P', 0, ""));
	type = ctr_txt("control/ctrl_type.txt", 'G', 'P', 0, "");
    replaceHomeWithTilde(currentDirPath);
	if (strncmp(str1, "start", 5) == 0)
    {
		printf("%s\n Para empezar prueba con cualquiera de estos comandos:\n\n", RED);
        printf("%s ./grademe start P%s --> MODE PRACTICE\n", CYAN, WHITE);
		printf("%s ./grademe start T%s --> MODE PRACTICE ALL QUESTIONS\n", CYAN, WHITE);
        printf("%s ./grademe start R%s --> MODE REAL\n\n", CYAN, WHITE);
    }
    if (strncmp(str1, "empezamos", 9) == 0)
	{
		printf("%s\n You're connected: %s%s\n", WHITE, GREEN, username); 
		printf("%s You can log out at any time.", WHITE); 
		printf("%s If this program tells you you earned points\n", WHITE);
		printf("%s then they will be counted whatever happens.\n\n", WHITE);
		printf("%s You are about to start the project %sExam_42_ZIP%s, in", WHITE, GREEN, WHITE);
        if ((strncmp(mode, "P", 1) == 0) || (strncmp(mode, "p", 1) == 0))
            printf("%s PRACTICE%s mode, at level.\n", MAGENTA, WHITE);
        else
            printf("%s REAL%s mode, at level.\n", MAGENTA, WHITE);
		printf("%s You would have 3hrs to complete this project.\n", WHITE);
		printf("%s Start Exam_42_ZIP --> ", WHITE);     
		printf("%s %s\n\n", GREEN, get_date());
		printf("%s =====================================================================================\n", WHITE);
		printf("%s Mode:", WHITE);
        if ((strncmp(mode, "P", 1) == 0) || (strncmp(mode, "p", 1) == 0))
            printf("%s PRACTICE ZIP", MAGENTA);
        else
            printf("%s REAL ZIP", MAGENTA);
		if ((strncmp(type, "T", 1) == 0) || (strncmp(type, "t", 1) == 0))
		{
			printf("%s | Current Grade: %s%d%s / 500", WHITE, GREEN, grade, WHITE);
			printf("%s | Level: %s%d%s / 20\n\n", WHITE, GREEN, grade / 25, WHITE);
		}
		else
		{
			printf("%s | Current Grade: %s%d%s / 200", WHITE, GREEN, grade, WHITE);
        	printf("%s | Level: %s%d%s / 8\n\n", WHITE, GREEN, grade / 25, WHITE);
		}
	}
	if (strncmp(str1, "questionX", 9) == 0)
	{
		print_msg ("empezamos", "");
		printf("%s Assignement: %s%s %sfor %s25%sxp\n\n", WHITE, GREEN, sfile, WHITE, GREEN, WHITE);
		printf("%s Subject location: %s%s/subjects/%s.txt\n", WHITE, GREEN, currentDirPath, sfile); 
		printf("%s Exercice location: %s%s/rendu/%s/\n", WHITE, RED, currentDirPath, sfile); 
		printf("%s Here you %sdon't need%s to use git.\n\n", WHITE, RED, WHITE); 
		calculate_time_difference(get_date());
		printf("%s =====================================================================================\n", WHITE);
		printf("%s You can work on your assignesent.\n", WHITE);
        if (strncmp(sfile, "ft_", 3) == 0)
            printf("%s En este caso en la primera comprobación usa \"make\" despues usa \"./grademe\" .\n", YELLOW);
        printf("%s When you are sure you're done with it, use the \"./grademe\" command to be graded.\n\n\n", WHITE);            
	}
}