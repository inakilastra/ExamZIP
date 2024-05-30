/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grademe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:50:00 by inaki             #+#    #+#             */
/*   Updated: 2024/05/29 17:06:37 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "control/control.c"
#include "control/movefile.c"

int control(const char get_write, int question);
int	checkfile(const char *str);
int	movefile(const char *src, const char *dst);
int new_folder(const char *dir);
	
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

const char* get_color(int value)
{
    switch (value) 
	{
        case 0:
            return GRAY;
        case 1:
            return RED;
        case 2:
            return GREEN;
        case 3:
            return YELLOW;
        case 4:
            return BLUE;
        case 5:
            return MAGENTA;
        case 6:
            return CYAN;
        case 7:
            return WHITE;												
        default:
            return DEF_COLOR;
    }
}

int	main(int argc, char **argv)
{
	char		c[5] = "start";    
    const char *color;
    int         i;
    int         second;
    time_t      current_time;
    struct tm   *time_info;
    char        *username = getlogin();
    char currentPath[MAX_PATH];
    char *currentDirPath = getcwd(currentPath, MAX_PATH);

	printf("\033[H\033[J");
    color = get_color(7);
	printf("%s******************************************************\n", color);
	printf("%s**********************GRADEME ZIP*********************\n", color);
	printf("%s******************************************************\n", color);		
	if (argc > 2)
	{
		printf("\033[0;91m\nError en el número de argumentos\n");
		printf("\033[0;92mPrueba con: ./grademe o con ./grademe \"start\"\n\n");
		return (0);
	}
    time(&current_time); // Obtener el tiempo acual
    time_info = localtime(&current_time); // Convertir el tiempo actual a una estructura tm
	i = control('G', 0);
    second = time_info->tm_sec;	
	second = second % 10;    
    if (argc == 2 && i == 0)
    {
        if (strncmp(argv[1], c, 5) == 0)
        {
            printf("%s\nYou're connected: %s%s\n", WHITE, GREEN, username); 
            printf("%s\nYou can log out at any time.\n", WHITE); 
            printf("%s\nIf this program tells you you earned points ", WHITE);
            printf("%sthen they will be counted whatever happens.\n", WHITE);
            printf("%s\nYou would have 3hrs to complete this project.\n", WHITE);
            printf("%s\nStart exam ZIP --> ", WHITE);
             //REVISAR
            if (second > 0 && second <= 5)
                control('W', 11);
            else
                control('W', 12);     
            printf("%s%d/%d/%d %d:%d:%d\n\n", GREEN, time_info->tm_mday, time_info->tm_mon + 1, time_info->tm_year + 1900, time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
            printf("%s==========================================================\n", WHITE);
            printf("%sMode: %sZIP\n\n", WHITE, MAGENTA);
            new_folder("subjects");
            new_folder("rendu");
        }
        else
            printf("%s\n\tEl tiempo corre, prueba con ./grademe \"start\"\n", RED);
    }
    i = control('G', 0);
    if (i > 0)
    {
        

        if (i > 0 && i < 14)
            if ((second > 0 && second <= 5) && i == 11)
            {
                if (checkfile("rendu/aff_z/aff_a.c") == 0)
                {
                    //norminette
                }
                movefile("questions/aff_a.txt", "subjects/aff_a.txt");//11
                movefile("subjects/aff_z.txt", "questions/aff_z.txt");//12
                new_folder("rendu/aff_a");
                printf("%s\tAssignement: %saff_a.c\n", WHITE, GREEN);
                printf("%s\tSubject location: %s%s/subjects/aff_a.c.txt\n", WHITE, GREEN, currentDirPath); 
                printf("%s\tExercice location: %s%s/rendu/aff_a/\n", WHITE, RED, currentDirPath); 
                printf("%s\tHere you don't need to use git.\n", WHITE); 
                printf("%s==========================================================\n", WHITE);
            }
            else
            {
                movefile("questions/aff_z.txt", "subjects/aff_z.txt");//12
                movefile("subjects/aff_a.txt", "questions/aff_a.txt");//11
                new_folder("rendu/aff_z");
                printf("%s\tAssignement: %saff_z.c\n", WHITE, GREEN);
                printf("%s\tSubject location: %s%s/subjects/aff_z.c.txt\n", WHITE, GREEN, currentDirPath); 
                printf("%s\tExercice location: %s%s/rendu/aff_z/\n", WHITE, RED, currentDirPath); 
                printf("%s\tHere you don't need to use git.\n", WHITE); 
                printf("%s==========================================================\n", WHITE);
            }
        else if (i > 20 && i < 24)
            if (second > 0 && second <= 3)
                printf("%s23 rev_print.c\n", color);
            else if (second >= 4 && second <= 6)
                printf("%s21 ft_putstr.c\n", color);
            else
                printf("%s22 ft_strlen.c\n", color);
        else if (i > 30 && i < 34)
            printf("%s31 fizzbuzz.c\t\t32 buzzfizz.c\n", color);
        else if (i > 40 && i < 44)
            printf("%s41 aff_first_param.c\t42 aff_last_param.c\n", color);
        else if (i > 50 && i < 54)
            printf("%s51 first_word.c\t\t52 rot_13.c\t\t53 rotone.c\n", color);
        else if (i > 60 && i < 64)
            printf("%s61 inter.c\t\t62 union.c\t\t62 last_word.c\n", color);
        else if (i > 70 && i < 74)
            printf("%s71 ft_itoa.c\t\t72 ft_range.c\t\t73 ft_rrange_z.c\n", color);
        else if (i > 80 && i < 84)
            printf("%s81 expand_str.c\t\t82 ft_split.c\n", color);
        else
            printf("%sSUCCESS\n\n", GREEN);
    }
    else
	    printf("%s\n\tPrueba a poner: ./grademe \"start\" para empezar\n\n", RED);
    printf("\n");
    (void)currentDirPath;
    //printf("Current path: %s\n", currentDirPath);
	return (0);
}
