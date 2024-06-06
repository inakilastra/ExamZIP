/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grademe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:37:09 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/06 14:50:36 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define _FILE_FT_INPUT_OK_C
//#define _FILE_FT_PUTSTR_C
/* #include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h> */
#include "libzip.h"


/* #define DEF_COLOR "\033[0;39m"
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
#define BUFFER_SIZE 128 */

void	remove_directory(const char *path)
{
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL)
    {
        perror("opendir");
        return;
    }
    while ((entry = readdir(dir)) != NULL)
    {
        char file_path[1024];
        struct stat statbuf;

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);
        if (stat(file_path, &statbuf) == 0) 
        {
            if (S_ISDIR(statbuf.st_mode))
                remove_directory(file_path);
            else
                if (unlink(file_path) != 0)
                    perror("unlink");
        }
    }
    closedir(dir);
    if (rmdir(path) != 0)
        perror("rmdir");
}

int new_folder(const char *dir)
{
	if (mkdir(dir, 0755) == -1)
		if (errno != EEXIST)
			return (1);
	return (0);
}

int	check_file(const char *str)
{
    char check_path[1024];

    snprintf(check_path, sizeof(check_path), "%s", str);  
    if (access(check_path, F_OK) != 0)
        return (1);
    return (0);
}

int copy_file(const char *src, const char *dst)
{
    FILE *source, *destination;
    char buffer[1024];
    size_t bytes;

    source = fopen(src, "rb");
    if (source == NULL) 
	{
        perror("Error al abrir el archivo de origen");
        return 1;
    }
    destination = fopen(dst, "wb");
    if (destination == NULL)
	{
        perror("Error al abrir el archivo de destino");
        fclose(source);
        return 1;
    }
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0)
	{
        fwrite(buffer, 1, bytes, destination);
    }
    fclose(source);
    fclose(destination);
    return 0;
}

char *ctr_txt(const char *sfile_txt, const char get_write, char mode, int question , const char *question_name) 
{
    char	line[MAX_LINE_LENGTH];
    char	*line_get = NULL;
    char    *line_new = NULL;
    int     i = 0;
    time_t      current_time;
    struct tm   *time_info;
    char        date_start[256];

    FILE *control_fp = fopen(sfile_txt, "r");

    if (!control_fp)
    {
        perror("Error opening file");
        return (0);
    }
    while (fgets(line, sizeof(line), control_fp))
    {
		line_get = strdup(line); 
    }
    if (strcmp(sfile_txt, "control/ctrl_penal.txt") == 0
        || strcmp(sfile_txt, "control/ctrl_question.txt") == 0)
    {
        i = atoi(line_get);
    }
    fclose(control_fp);
    if (get_write == 'W')
    {
       	if (strcmp(sfile_txt, "control/ctrl_mode.txt") == 0)
        {
            if (mode == 'P' || mode == 'p')
                line_new = strdup("P");
            else
                line_new = strdup("R");
        }
        if (strcmp(sfile_txt, "control/ctrl_penal.txt") == 0)
        {
            i += i;
            if (mode == 'P' || mode == 'p')
                if (question == 0)
                    line_new = strdup(ft_itoa(15));
                else
                    line_new = strdup(ft_itoa(i));
            else
                if (question == 0)
                    line_new = strdup(ft_itoa(60));
                else
                    line_new = strdup(ft_itoa(i)); 
        }
        if (strcmp(sfile_txt, "control/ctrl_question.txt") == 0)
        {
            if (question == i)
                line_new = strdup(ft_itoa(i));
            else
                line_new = strdup(ft_itoa(question));
        }
        if (strcmp(sfile_txt, "control/ctrl_question_name.txt") == 0)
        {
            line_new = strdup(question_name);
        }        
        if (strcmp(sfile_txt, "control/ctrl_time.txt") == 0)
        {   
            if (question == 0)
            {
                time(&current_time);
                time_info = localtime(&current_time);
                snprintf(date_start, sizeof(date_start), "%d/%d/%d %d:%d:%d\n", 
                         time_info->tm_mday, time_info->tm_mon + 1, time_info->tm_year + 1900, 
                         time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
                if (line_new)
                    free(line_new);
                line_new = strdup(date_start);
            } 
        }   
        FILE *final_fp = fopen(sfile_txt, "w");
        if (!final_fp)
        {
            perror("Error opening files for final writing");
            return ("X");
        }
        if (line_new)
        {
            fputs(line_new, final_fp);
            free(line_new);
        }
        fclose(final_fp); 
        (void)question;
        return (line_new);      
    }
    return (line_get);
}

char *get_date(void) 
{
    struct tm start_tm = {0};
	FILE *control_fp = fopen("control/ctrl_time.txt", "r");

    if (!control_fp)
    {
        perror("Error opening file control/ctrl_time.txt");
        return ("");
    }

    char	line[MAX_LINE_LENGTH];
    char	*line_t = NULL;
    
    while (fgets(line, sizeof(line), control_fp))
    {
        line_t = strdup(line);
    }
    fclose(control_fp);
	    if (sscanf(line_t, "%d/%d/%d %d:%d:%d",
               &start_tm.tm_mday, &start_tm.tm_mon, &start_tm.tm_year,
               &start_tm.tm_hour, &start_tm.tm_min, &start_tm.tm_sec) != 6)
	{
        fprintf(stderr, "Error parsing date string\n");
        return ("");
    }
    return (line_t);
}

void calculate_time_difference(const char *start_str) 
{
    struct tm start_tm = {0};
    struct tm end_tm = {0};
    time_t start_time, end_time;
    double seconds_difference;
    int hours, minutes, seconds;

    // Extract date and time components from the string
    if (sscanf(start_str, "%d/%d/%d %d:%d:%d",
               &start_tm.tm_mday, &start_tm.tm_mon, &start_tm.tm_year,
               &start_tm.tm_hour, &start_tm.tm_min, &start_tm.tm_sec) != 6)
	{
        fprintf(stderr, "Error parsing date string\n");
        return;
    }

    // Adjust the month and year
    start_tm.tm_mon -= 1;   // tm_mon is 0-based
    start_tm.tm_year -= 1900; // tm_year is years since 1900

    // Convert struct tm to time_t (seconds since epoch)
    start_time = mktime(&start_tm);
    if (start_time == -1)
	{
        fprintf(stderr, "Error converting start time to time_t\n");
        return;
    }
    // Add 3 hours to start_time
    end_time = start_time + 2 * 3600;
    // Convert end_time back to struct tm
    end_tm = *localtime(&end_time);
    // Calculate the difference between the end time and the current time
    time_t current_time = time(NULL);
    if (current_time == -1)
	{
        fprintf(stderr, "Error getting current time\n");
        return;
    }
    seconds_difference = difftime(end_time, current_time);
    if (seconds_difference < 0) {
        fprintf(stderr, "End time is in the past\n");
        return;
    }
    // Calculate hours, minutes, and seconds from seconds_difference
    hours = (int)seconds_difference / 3600;
    seconds_difference -= hours * 3600;
    minutes = (int)seconds_difference / 60;
    seconds = (int)seconds_difference % 60;
    // Print the results
	printf("%s End date: %s%02d/%02d/%04d %02d:%02d:%02d\n", WHITE, GREEN,
           end_tm.tm_mday, end_tm.tm_mon + 1, end_tm.tm_year + 1900,
           end_tm.tm_hour, end_tm.tm_min, end_tm.tm_sec);
	printf("%s Left time: %s%d hrs, %d min, and %d sec\n\n", WHITE, GREEN, hours, minutes, seconds);
}

int	check_norminette(const char *filename, char mode)
{
	char		buffer[128];
	FILE		*pipe;
	int			error_count;
	char		command[256];
	int			i;

	error_count = 0;
	snprintf(command, sizeof(command), "norminette %s", filename);
	pipe = popen(command, "r");
	if (!pipe)
	{
		fprintf(stderr, "Error al ejecutar norminette.\n");
		return (-1);
	}
	i = atoi(ctr_txt("control/ctrl_question.txt", 'G', 'P', 0, ""));
	if (i > 0 && (mode == 'P' ||  mode == 'p'))
		printf("%s\n NORMINETTE:\n\n", CYAN);
	while (fgets(buffer, sizeof(buffer), pipe) != NULL)
	{
		if (i > 0)
		{
			if(mode == 'P' ||  mode == 'p')
            {
                if (strstr(buffer, ".c: OK!") != NULL)
				    printf("%s %s", GREEN, buffer);
			    else
				    printf("%s %s", RED, buffer);
            }
			if (strstr(buffer, "Error") != NULL)
				error_count++;
		}
	}
	if (pclose(pipe) == -1) 
	{
		fprintf(stderr, "Error al cerrar la tubería.\n");
		return (-1);
	}
	if (error_count > 1)
		error_count--;
	return (error_count);
}

int mypaco_write(char *name, char *argv1, char *argv2, char *argv3)
{
    FILE    *fp;
    char    buffer[BUFFER_SIZE];
    char    result[BUFFER_SIZE] = "";
    int     ret;
    //int     pruebas = 0;

    // Construir el comando de compilación
    char compile_c[256];
    snprintf(compile_c, sizeof(compile_c), "gcc -o rendu/%s/%s rendu/%s/%s.c -Wall -Wextra -Werror", name, name, name, name);
    //printf("\n compile_c: %s\n\n", compile_c);

    // Compilar aff_z.c
    //  ret = system("gcc -o aff_z aff_z.c");
    ret = system(compile_c);
    if (ret != 0) {
        fprintf(stderr, "Error compiling %s.c\n", name);
        return 1;
    }

    // Construir el comando de ejecución
    char rendu_c[256];
    if (strncmp(name, "aff_a", 5) == 0
        || strncmp(name, "rev_print", 9) == 0)
        snprintf(rendu_c, sizeof(rendu_c), "rendu/%s/./%s %s", name, name, argv1);
	else
    	snprintf(rendu_c, sizeof(rendu_c), "rendu/%s/./%s", name, name);
    //rev_print
    //printf("\n rendu_c: %s\n\n", rendu_c);   
    // Ejecutar el comando y abrir un pipe para leer su salida
    fp = popen(rendu_c, "r");
    if (fp == NULL) {
        perror("popen");
        return 1;
    }

    // Leer la salida del comando y guardarla en el buffer
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		strcat(result, buffer);
    }
	//printf("argv1 --> %s result --> %s\n", argv1, result);
    // Cerrar el pipe
    if (pclose(fp) == -1) {
        perror("pclose");
        return 1;
    }
    

    // Imprimir la salida capturada
    //printf("Captured : %s", result);
    if ((strncmp(name, "aff_a", 5) == 0) 
        && (strncmp(argv1, "zz sent le poney", 16) == 0)
        && (strncmp(result, "\n", 1) == 0))
    {
        return (1);
    } 
    if ((strncmp(name, "aff_a", 5) == 0) 
        && ((strncmp(argv1, "abc", 3) == 0) 
			|| (strncmp(argv1, "dubO a POIL", 11) == 0)
			|| (strncmp(argv1, "", 0) == 0))
        && (strncmp(result, "a", 1) == 0))
    {
        return (1);
    }
    if ((strncmp(name, "rev_print", 9) == 0) 
        && (strncmp(argv1, "zaz", 3) == 0)
        && (strncmp(result, "zaz", 3) == 0))
    {
		return (1);
    }
    if ((strncmp(name, "rev_print", 9) == 0) 
        && (strncmp(argv1, "dub0 a POIL", 11) == 0)
        && (strncmp(result, "LIOP a 0bud", 11) == 0))
    {
		return (1);
	}
    if ((strncmp(name, "rev_print", 9) == 0) 
        && (strncmp(argv1, "", 0) == 0)
        && (strncmp(result, "", 0) == 0))
    {
		return (1);
    } 	
    (void)argv1;
    (void)argv2;
    (void)argv3;
    if ((strncmp(name, "aff_z", 5) == 0) 
		&& (strncmp(result, "z", 1) == 0))
    {
        return (1);
    }
    return (0);
}

void    print_msg (const char *str1, const char *sfile)
{
	char        *username = getlogin();
    char        currentPath[MAX_PATH];
    char        *currentDirPath = getcwd(currentPath, MAX_PATH);
    char         *mode;

    mode = ctr_txt("control/ctrl_mode.txt", 'G', 'P', 0, "");
	if (strncmp(str1, "start", 5) == 0)
    {
		printf("%s\n Para empezar prueba con cualquiera de estos comandos:\n\n", RED);
        printf("%s ./grademe start P%s --> MODE PRACTICE\n", CYAN, WHITE);
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
            printf("%s PRACTICE ZIP\n\n", MAGENTA);
        else
            printf("%s REAL ZIP\n\n", MAGENTA);
	}
	if (strncmp(str1, "questionX", 9) == 0)
	{
		print_msg ("empezamos", "");
		printf("%s Assignement: %s%s.c\n\n", WHITE, GREEN, sfile);
		printf("%s Subject location: %s%s/subjects/%s.txt\n", WHITE, GREEN, currentDirPath, sfile); 
		printf("%s Exercice location: %s%s/rendu/%s/\n", WHITE, RED, currentDirPath, sfile); 
		printf("%s Here you %sdon't need%s to use git.\n\n", WHITE, RED, WHITE); 
		calculate_time_difference(get_date());
		printf("%s =====================================================================================\n", WHITE);
		printf("%s You can work on your assignesent.\n When you are sure you're done with it, use the \"./grademe\" command to be graded.\n\n\n", WHITE);
	}
}

void ft_file(const char *sfile)
{
    char 	*questions_txt = strdup("questions/");
    char 	*subjects_txt = strdup("subjects/");
    char 	*rendu_txt = strdup("rendu/");

	strcat(questions_txt, sfile);
	strcat(questions_txt, ".txt");
    strcat(subjects_txt, sfile);
	strcat(subjects_txt, ".txt");
    strcat(rendu_txt, sfile);
    
    copy_file(questions_txt, subjects_txt);//11
    if (check_file(rendu_txt) != 0)
        new_folder(rendu_txt);
    print_msg ("questionX", sfile);
}

void    ctrl_txt_show(const char c)
{
    char	*line_g = NULL;

    line_g = ctr_txt("control/ctrl_mode.txt", 'G', c, 0, "");
    if (line_g)
        printf("%s %s\n", line_g, WHITE);
    if (line_g)        
        free(line_g);
    line_g = ctr_txt("control/ctrl_penal.txt", 'G', c, 0, "");
    if (line_g)
        printf("%s %s\n", line_g, WHITE);
    if (line_g)        
        free(line_g);
    line_g = ctr_txt("control/ctrl_question.txt", 'G', c, 0, "");
    if (line_g)
        printf("%s %s\n", line_g, WHITE);
    if (line_g)        
        free(line_g);
    line_g = ctr_txt("control/ctrl_time.txt", 'G', c, 0, "");
    if (line_g)
        printf("%s %s\n", line_g, WHITE);
    if (line_g)        
        free(line_g);
}

void    ctrl_txt_reset()
{
    ctr_txt("control/ctrl_mode.txt", 'W', 'P', 0, "");// Mode P
    ctr_txt("control/ctrl_penal.txt", 'W', 'P', 0, "");// Penal 0 reinicia 1 en P 5 en R
    ctr_txt("control/ctrl_question.txt", 'W', 'P', 0, "");// Mode P
}

void    ctrl_txt_start(const char c)
{
    int i;
    i = atoi(ctr_txt("control/ctrl_question.txt", 'G', 'P', 0, ""));
    ctr_txt("control/ctrl_time.txt", 'W', c, i, "");// Mode P
}

void	ft_start(const char c)
{
    //ctrl_txt_reset();
    ctrl_txt_start(c);
    new_folder("subjects");
    new_folder("rendu");
}

void	ft_help(void)
{
	int	    i = 0;
	char    *q_text = ctr_txt("control/ctrl_question.txt", 'G', 'X', 0, "");
    if (q_text)
    {
        i = atoi(q_text);
        free(q_text);
    }
	if (i > 0)
    {
		print_msg ("questionX", "");
    }
	printf("%s ./grademe help\n\n", CYAN);
    printf("%s Instruccciones:\n\n", WHITE);
	printf("%s Copia todo en la carpeta que quieras.\n\n", WHITE);
	printf("%s Compila %sgcc -o grademe grademe.c -Wall -Wextra -Werror\n\n", WHITE, CYAN);
	printf("%s Para comenzar una simulación ejecuta %s./grademe start R%s o %s./grademe start P\n", WHITE, CYAN, WHITE, CYAN);
	printf("%s  ./grademe start R %sModo REAL te penaliza más tiempo y no ves el motivo del fallo\n", CYAN, WHITE);
	printf("%s  ./grademe start P %sModo PRACTICE te penaliza menos tiempo y ves el motivo del fallo:\n", CYAN, WHITE);
	printf("%s    Tanto Norminette como lo que se esperaba recibir vs lo que devuelve tu cógigo\n\n", WHITE);
	printf("%s Para evaluar cada ejercicio ejecuta %s./grademe\n\n", WHITE, CYAN);
	printf("%s Para reiniciar una simulación ejecuta %s./grademe reset R%s o %s./grademe reset P\n", WHITE, CYAN, WHITE, CYAN);
	printf("%s  OJO ESTO BORRA LA CARPETA %s\"rendu\"%s, si quieres conservar tus ficheros muevelos antes\n\n", WHITE, RED, WHITE);
	printf("%s Para ver la ayuda ejecuta %s./grademe help\n\n", WHITE, CYAN);
}

void	ft_reset()
{
	ctrl_txt_reset();
    if (check_file("rendu") == 0)
    {
        remove_directory("rendu");
    }
    if (check_file("subjects") == 0)
    {
        remove_directory("subjects");
    }
    printf("%s Reinicializado.\n", GREEN);
    print_msg ("start", "");
}

int get_second(void)
{
    time_t      current_time;
    struct tm   *time_info;
    int         second;

    time(&current_time);
    time_info = localtime(&current_time);
    second = time_info->tm_sec;	
	second = second % 10;
    return (second);
}

char *get_rendu_c(const char *name)
{
    if (name == NULL)
	{
        return NULL; // Verifica que el nombre no sea NULL
    }

    // Calcula el tamaño necesario para la cadena resultante
    size_t total_length = strlen("rendu/") + strlen(name) + strlen("/") + strlen(name) + strlen(".c") + 1;

    // Asigna memoria suficiente
    char *rendu_c = (char *)malloc(total_length * sizeof(char));
    if (rendu_c == NULL)
	{
        perror("Error asignando memoria");
        exit(EXIT_FAILURE);
    }

    // Construye la cadena completa usando snprintf
    snprintf(rendu_c, total_length, "rendu/%s/%s.c", name, name);
    return (rendu_c);
}

void	ft_grademe(void)
{
	char        *name;
    char        *mode;
    char 	    *rendu_c;
    int         penal=0;
    int         second;
    int         i = 0;
	int			k = 0;
    int         show = 0;
    char        *paco;

    second = get_second();
    i = atoi(ctr_txt("control/ctrl_question.txt", 'G', 'P', 0, ""));
    name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
    mode = ctr_txt("control/ctrl_mode.txt", 'G', 'P', 0, "");
    penal = atoi(ctr_txt("control/ctrl_penal.txt", 'G', 'P', 0, ""));
    if ((strncmp(mode, "P", 1) == 0) || (strncmp(mode, "p", 1) == 0))
        show = 1;
    print_msg ("questionX", name);
    rendu_c = get_rendu_c(name);
    printf("%s\n Please be patient, this CAN take several minutes...\n (10 seconds is fast, 30 seconds is expected, 3 minutes is a maximum)\n\n", WHITE);
    printf("%s waiting...\n\n", YELLOW);
    sleep(penal);
    if (i > 0)
    {
        if (i > 0 && i < 14)
        {
            if (((second > 0 && second <= 5) || (i == 11)) &&  (i != 12))
            {
                if (check_file(rendu_c) == 0)
                {
                    if (check_norminette(rendu_c,mode[0]) == 0)
                    {    
                        if (strncmp(name, "aff_a", 5) == 0)
                        {
							k = 0;
							printf("%s\n PACO:\n\n", CYAN);
                            k = ft_paco_aff_a(k, show);                        
							if (k == 7)
							{
								printf("%s\n >>>>>>>>>> SUCCESS <<<<<<<<<<\n\n", GREEN);
								if (check_file("subjects/aff_a.txt") == 0)
								{
									if (remove("subjects/aff_a.txt") == 0)
										printf("\n");
									else
										perror("Error deleting the file");
								}
								i = 20;
                                ctr_txt("control/ctrl_penal.txt", 'W', 'P', 0, ""); 
							}
							else
							{
								if (show == 1)
									ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, ""); 
								else
									ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
								printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n%s You have falled the assignement.\n\n", RED, WHITE);
							}
                        }

                    }
                    else
                    {
                        if (show == 1)
                        {
                            ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, ""); 
                        }
                        else
                        {
                            ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
                        }
                        printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n%s You have falled the assignement.\n\n", RED, WHITE); 
                    }
                }
                else
                {
                    if ((check_file("subjects/aff_a.txt") == 0)
                        && (check_file("rendu/aff_a") == 0) 
                        && (check_file("rendu/aff_a/aff_a.c") != 0))
                    {
                        if (show == 1)
                            {
                                ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, ""); 
                                printf(" No existe: %s\n\n", rendu_c);
                            }
                            else
                            {
                                ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
                            }
                            printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n%s You have falled the assignement.\n\n", RED, WHITE); 
                    }           
                    if (check_file("subjects/aff_a.txt") != 0)
                        copy_file("questions/aff_a.txt", "subjects/aff_a.txt");//11
                    if (check_file("rendu/aff_a") != 0)
                        new_folder("rendu/aff_a");
                }
            }
            else
            {
                if (check_file(rendu_c) == 0)
                {
                    if (check_norminette(rendu_c,mode[0]) == 0)
                    {    
                        if (strncmp(name, "aff_z", 5) == 0)
                        {
                            k = 0;
							printf("%s\n PACO:\n\n", CYAN);
                            paco = ft_paco_argv0("aff_z");
                            if (strncmp(paco, "z", 1) == 0)
                            {
                            	if (show == 1)
									printf("%s ./aff_z \"z\"\n", GREEN);
								k++;
							}                           
							else
								printf("%s ./aff_z \"z\"\n", RED);
                            free(paco);
                            paco = ft_paco_argv1("aff_z", "");
                             if (strncmp(paco, "", 0) == 0)
                            {
                            	if (show == 1)
									printf("%s ./aff_z\n", GREEN);
								k++;
							}                           
							else
								printf("%s ./aff_z\n", RED);
                            free(paco);                            
/* 							if (mypaco_write(name, "", "", "") == 1)
							{
                            	if (show == 1)
									printf("%s ./aff_z \n", GREEN);
								k++;
							}
							else
								printf("%s ./aff_z \n", RED); */
							if (k == 2)
							{
								printf("%s\n >>>>>>>>>> SUCCESS <<<<<<<<<<\n\n", GREEN);
								if (check_file("subjects/aff_z.txt") == 0)
								{
									if (remove("subjects/aff_z.txt") == 0)
										printf(" ");
									else
										perror("Error deleting the file");
								}
								i = 20;
                                ctr_txt("control/ctrl_penal.txt", 'W', 'P', 0, ""); 
							}
							else
							{
								if (show == 1)
									ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, ""); 
								else
									ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
								printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n%s You have falled the assignement.\n\n", RED, WHITE);
							}
                        }

                    }
                    else
                    {
                        if (show == 1)
                        {
                            ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, ""); 
                        }
                        else
                        {
                            ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
                        }
                        printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n%s You have falled the assignement.\n\n", RED, WHITE); 
                    }
                }
                else
                {
                    if ((check_file("subjects/aff_z.txt") == 0)
                        && (check_file("rendu/aff_z") == 0) 
                        && (check_file("rendu/aff_z/aff_z.c") != 0))
                    {
                        if (show == 1)
                            {
                                ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, ""); 
                                printf(" No existe: %s\n\n", rendu_c);
                            }
                            else
                            {
                                ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
                            }
                            printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n%s You have falled the assignement.\n\n", RED, WHITE); 
                    }           
                    if (check_file("subjects/aff_z.txt") != 0)
                        copy_file("questions/aff_z.txt", "subjects/aff_z.txt");//11
                    if (check_file("rendu/aff_z") != 0)
                        new_folder("rendu/aff_z");
                }
            }
        }
        
        if (i == 20)
        {
            ft_input_ok();
second = 5;
            if (second >= 0 && second <= 3)
            {
                ft_file("rev_print");//23
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 23, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 23, "rev_print");
            }
            else if (second >= 4 && second <= 6)
            {
                ft_file("ft_putstr");//21
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 21, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 21, "ft_putstr");              
            }
            else
            {
                ft_file("ft_strlen");//22
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 22, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 22, "ft_strlen");                
            }
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            mode = ctr_txt("control/ctrl_mode.txt", 'G', 'P', 0, "");

    		rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);         
        }

        if (i > 20 && i < 24)
        {
            if (i == 23)
            {
                if (check_file(rendu_c) == 0)
                {
                    if (check_norminette(rendu_c,mode[0]) == 0)
                    {
                        if (strncmp(name, "rev_print", 9) == 0)
                        {
                            k = 0;
							printf("%s\n PACO:\n\n", CYAN);
							if (mypaco_write(name, "zaz", "", "") == 1)
							{
                            	if (show == 1)
									printf("%s ./rev_print \"zaz\"\n", GREEN);
								k++;
							}
							else
								printf("%s ./rev_print \"zaz\"\n", RED);
							if (mypaco_write(name, "\"dub0 a POIL\"", "", "") == 1)
							{
                            	if (show == 1)
									printf("%s ./rev_print \"dub0 a POIL\"\n", GREEN);
								k++;
							}
							else
								printf("%s ./rev_print \"dub0 a POIL\"\n", RED);
							if (mypaco_write(name, "", "", "") == 1)
							{
                            	if (show == 1)
									printf("%s ./rev_print \n", GREEN);
								k++;
							}
							else
								printf("%s ./rev_print \n", RED);																
							if (k == 3)
							{
								printf("%s\n >>>>>>>>>> SUCCESS <<<<<<<<<<\n\n", GREEN);
								if (check_file("subjects/rev_print.txt") == 0)
								{
									if (remove("subjects/rev_print.txt") == 0)
										printf("\n");
									else
										perror("Error deleting the file");
								}
								i = 20;
                                ctr_txt("control/ctrl_penal.txt", 'W', 'P', 0, ""); 
							}
							else
							{
								if (show == 1)
									ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, ""); 
								else
									ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
								printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n%s You have falled the assignement.\n\n", RED, WHITE);
							}
                        }

                    }
                    else
                    {
                        if (show == 1)
                        {
                            ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, ""); 
                        }
                        else
                        {
                            ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
                        }
                        printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n%s You have falled the assignement.\n\n", RED, WHITE); 
                    }
                }
                else
                {
                    if ((check_file("subjects/rev_print.txt") == 0)
                        && (check_file("rendu/rev_print") == 0) 
                        && (check_file("rendu/rev_print/rev_print.c") != 0))
                    {
                        if (show == 1)
                            {
                                ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, ""); 
                                printf(" No existe: %s\n\n", rendu_c);
                            }
                            else
                            {
                                ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
                            }
                            printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n%s You have falled the assignement.\n\n", RED, WHITE); 
                    }           
                    if (check_file("subjects/rev_print.txt") != 0)
                        copy_file("questions/rev_print.txt", "subjects/rev_print.txt");//11
                    if (check_file("rendu/rev_print") != 0)
                        new_folder("rendu/rev_print");
                }                
            }
            else if (i == 21)
            {
				if (check_file(rendu_c) == 0)
                {
                    if (check_norminette(rendu_c,mode[0]) == 0)
                    {
                        if (strncmp(name, "ft_putstr", 9) == 0)
                        {
                            k = 0;
							printf("%s\n PACO:\n\n", CYAN);
							if (mypaco_write(name, "abcdefg", "", "") == 1)
							{
                            	if (show == 1)
									printf("%s ./ft_putstr \"abcdefg\"\n", GREEN);
								k++;
							}
							else
								printf("%s ./ft_putstr \"abcdefg\"\n", RED);																
							if (k == 1)
							{
								printf("%s\n >>>>>>>>>> SUCCESS <<<<<<<<<<\n\n", GREEN);
								if (check_file("subjects/ft_putstr.txt") == 0)
								{
									if (remove("subjects/ft_putstr.txt") == 0)
										printf("\n");
									else
										perror("Error deleting the file");
								}
								i = 20;
                                ctr_txt("control/ctrl_penal.txt", 'W', 'P', 0, ""); 
							}
							else
							{
								if (show == 1)
									ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, ""); 
								else
									ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
								printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n%s You have falled the assignement.\n\n", RED, WHITE);
							}
                        }

                    }
                    else
                    {
                        if (show == 1)
                        {
                            ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, ""); 
                        }
                        else
                        {
                            ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
                        }
                        printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n%s You have falled the assignement.\n\n", RED, WHITE); 
                    }
                }
                else
                {
                    if ((check_file("subjects/ft_putstr.txt") == 0)
                        && (check_file("rendu/ft_putstr") == 0) 
                        && (check_file("rendu/ft_putstr/ft_putstr.c") != 0))
                    {
                        if (show == 1)
                            {
                                ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, ""); 
                                printf(" No existe: %s\n\n", rendu_c);
                            }
                            else
                            {
                                ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
                            }
                            printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n%s You have falled the assignement.\n\n", RED, WHITE); 
                    }           
                    if (check_file("subjects/ft_putstr.txt") != 0)
                        copy_file("questions/ft_putstr.txt", "subjects/ft_putstr.txt");//11
                    if (check_file("rendu/ft_putstr") != 0)
                        new_folder("rendu/ft_putstr");
                }  				
            }
            else if (i == 22)
            {
                printf("%s22 ft_strlen.c\n", WHITE);//22
            }
        }
        
        if (i >= 30 && i < 34)
        {
            ft_input_ok();
            printf("%s31 fizzbuzz.c\t\t32 buzzfizz.c\n", WHITE);
        }

        if (i >= 40 && i < 44)
        {
            ft_input_ok();
            printf("%s41 aff_first_param.c\t42 aff_last_param.c\n", WHITE);
        }

        if (i >= 50 && i < 54)
        {
            ft_input_ok();
            printf("%s51 first_word.c\t\t52 rot_13.c\t\t53 rotone.c\n", WHITE);
        }

        if (i >= 60 && i < 64)
        {
            ft_input_ok();
           printf("%s61 inter.c\t\t62 union.c\t\t62 last_word.c\n", WHITE);
        }

        if (i >= 70 && i < 74)
        {
            ft_input_ok();
            printf("%s71 ft_itoa.c\t\t72 ft_range.c\t\t73 ft_rrange_z.c\n", WHITE);
        }
        
        if (i >= 80 && i < 84)
        {
            ft_input_ok();
            printf("%s81 expand_str.c\t\t82 ft_split.c\n", WHITE);
        }
        if (i >= 90)
            printf("%s SUCCESS\n\n", GREEN);
    }
    else
    {
        if (show == 1)
        {
            ctr_txt("control/ctrl_penal.txt", 'W', 'P', 1, ""); 
            printf(" No existe: %s\n\n", rendu_c);
        }
        else
        {
            ctr_txt("control/ctrl_penal.txt", 'W', 'R', 1, "");
        }
        printf("%s\n >>>>>>>>>> FAILURE <<<<<<<<<<\n\n%s You have falled the assignement.\n\n", RED, WHITE); 
    }
		free(rendu_c);
}


int	main(int argc, char **argv)
{ 
	int i;
    int         second;
    time_t      current_time;
    struct tm   *time_info;

    time(&current_time);
    time_info = localtime(&current_time);
    second = time_info->tm_sec;	
	second = second % 10;
    printf("\033[H\033[J");
    printf("%s\n Exam_42_ZIP v1.0\n\n", WHITE);
	if (argc >= 2 && (strncmp(argv[1], "help", 5) == 0) )  
    {
    	if (strncmp(argv[1], "help", 5) == 0) 
			ft_help();
        return(0);  
    }
    if (argc >= 2 && (strncmp(argv[1], "reset", 5) == 0) )  
    {
		if (strncmp(argv[1], "reset", 5) == 0)
			ft_reset();	
		return(0); 
    }
    i = atoi(ctr_txt("control/ctrl_question.txt", 'G', 'P', 0, ""));
    if (argc == 3 
        && (strncmp(argv[1], "start", 5) == 0)
        && (argv[2][0] == 'P' || argv[2][0] == 'R' || argv[2][0] == 'p' || argv[2][0] == 'r'))
    {
		if (strncmp(argv[1], "start", 5) == 0)
        {
            if (i == 0)
            {
                ft_start(argv[2][0]);
                if (second > 0 && second <= 5)
                {
                    ft_file("aff_a");//11
                    ctr_txt("control/ctrl_question.txt", 'W', argv[2][0], 11, "");
                    ctr_txt("control/ctrl_question_name.txt", 'W', argv[2][0], 11, "aff_a");
                }
                else
                {
                    ft_file("aff_z");//12
                    ctr_txt("control/ctrl_question.txt", 'W', argv[2][0], 12, "");
                    ctr_txt("control/ctrl_question_name.txt", 'W', argv[2][0], 11, "aff_z");
                }
                return (0);
            }
            else
		        ft_grademe(); 
        }
	}
    
    if (i == 0)
        print_msg ("start", "");
    else
	    ft_grademe();  
	return (0);
}
