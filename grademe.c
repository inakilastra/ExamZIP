/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grademe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:50:00 by inaki             #+#    #+#             */
/*   Updated: 2024/05/30 16:49:37 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>


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

static int	n_dig(int n)// ft_itoa
{
	int	i;
	int	tmp;

	tmp = n;
	i = 1;
	if (tmp < 0)
	{
		tmp *= -1;
		i++;
	}
	while (tmp >= 10)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)// ft_itoa
{
	int		dig;
	char	*str;

	if (n == -2147483648)
		return (strdup("-2147483648"));
	if (n == 0)
		return (strdup("0"));
	dig = n_dig(n);
	str = (char *)malloc(sizeof(char) * (dig + 1));
	if (!str)
		return ("");
	str[dig--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[dig--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	check_file(const char *str)
{
    char check_path[256];

    snprintf(check_path, sizeof(check_path), "%s", str);  
    if (access(check_path, F_OK) != 0)
        return (1);
    return (0);
}
/** int	check_file(const char *str)
    {
        char check_path[256]; // Ajusta el tamaño según sea necesario

        // Construir la ruta del archivo actual
        snprintf(check_path, sizeof(check_path), "%s", str);  
        // Verificar si el archivo existe en la ruta original
        if (access(check_path, F_OK) != 0)
            return (1);
        return (0);
    }
*/

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

/** int copy_file(const char *src, const char *dst)
	{
		FILE *source, *destination;
		char buffer[1024];
		size_t bytes;

		// Abrir el archivo de origen
		source = fopen(src, "rb");
		if (source == NULL) {
			perror("Error al abrir el archivo de origen XX");
			return 1;
		}

		// Abrir el archivo de destino
		destination = fopen(dst, "wb");
		if (destination == NULL) {
			perror("Error al abrir el archivo de destino");
			fclose(source);
			return 1;
		}

		// Leer del archivo de origen y escribir en el archivo de destino
		while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
			fwrite(buffer, 1, bytes, destination);
		}

		// Cerrar los archivos
		fclose(source);
		fclose(destination);

		//printf("Archivo copiado correctamente de %s a %s\n", src, dst);
		return 0;
	}
*/

int	move_file(const char *src, const char *dst)
{
    char old_path[256];
    char new_path[256];

    snprintf(old_path, sizeof(old_path), "%s", src);
    snprintf(new_path, sizeof(new_path), "%s", dst);
    if (access(old_path, F_OK) != 0)
        return 1;
    if (rename(old_path, new_path) != 0)
        perror("Error moviendo el archivo");
    return (0);
}

/** int	move_file(const char *src, const char *dst)
    {
        char old_path[256]; // Ajusta el tamaño según sea necesario
        char new_path[256]; // Ajusta el tamaño según sea necesario


        // Construir la ruta del archivo actual
        snprintf(old_path, sizeof(old_path), "%s", src);
    //printf("old_path %s\n",old_path);    
        // Construir la nueva ruta del archivo
        snprintf(new_path, sizeof(new_path), "%s", dst);
    //printf("new_path %s\n",new_path);     
        // Verificar si el archivo existe en la ruta original
        if (access(old_path, F_OK) != 0)
        {
            //perror("El archivo no existe en la ruta especificada");
            return 1;
        }
        // Mover el archivo
        if (rename(old_path, new_path) != 0)
            //printf("El archivo se movió correctamente de %s a %s\n", old_path, new_path);
        //else
            perror("Error moviendo el archivo");
        return (0);
    }
*/

int new_folder(const char *dir)
{
	if (mkdir(dir, 0755) == -1)
		if (errno != EEXIST)
			return (1);
	return (0);
}

/** int new_folder(const char *dir)
    {
        // Crear la carpeta con permisos 0755 (rwxr-xr-x)
        if (mkdir(dir, 0755) == -1)
            // Verificar si hubo un error al crear la carpeta
            if (errno == EEXIST)
                printf(" "); //printf("La carpeta ya existe.\n");
            else
            {
                //perror("Error al crear la carpeta");
                return (1);
            }
        else
            printf(" "); //printf("Carpeta creada correctamente: %s\n", dir);
        return (0);
    }
*/

int control(const char get_write, int question) 
{
    time_t      current_time;
    struct tm   *time_info;
    char        date_start[256];
    FILE *control_fp = fopen("control/control.txt", "r");

    if (!control_fp)
    {
        perror("Error opening file control/control.txt");
        return (2);
    }

    char	line[MAX_LINE_LENGTH];
    char	*line_t = NULL;
	char	*line_p = NULL;
	char	*line_q = NULL;
    int		i_q = 0;
    
    while (fgets(line, sizeof(line), control_fp)) // Leer y procesar el archivo original
    {
        if (strncmp(line, "T:", 2) == 0)
            line_t = strdup(line);  // Guardar línea T:
        if (strncmp(line, "P:", 2) == 0)
            line_p = strdup(line);  // Guardar línea T:			
        else
		{
			line_q = strdup(line); 
            i_q = atoi(strdup(line));
		}
    }
    fclose(control_fp);

    if (get_write == 'W')
    {
        if (i_q == 0)
        {
            time(&current_time);
            time_info = localtime(&current_time);
            snprintf(date_start, sizeof(date_start), "T:%d/%d/%d %d:%d:%d\n", 
                     time_info->tm_mday, time_info->tm_mon + 1, time_info->tm_year + 1900, 
                     time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
            
            if (line_t)
                free(line_t);
            line_t = strdup(date_start);
        }
        if (question == 0)
			line_p = strdup("P:1\n");
		else
			line_p = strdup(line_p);
		
        if (question != i_q)
            line_q = strdup(ft_itoa(question));

        FILE *final_fp = fopen("control/control.txt", "w");

        if (!final_fp)
        {
            perror("Error opening files for final writing");
            return (2);
        }

        // Escribir las líneas T: y Q: en el archivo final primero
        if (line_t) {
            fputs(line_t, final_fp);
            free(line_t);
        }
        if (line_p) {
            fputs(line_p, final_fp);
            free(line_p);
        }		
        if (line_q) {
            fputs(line_q, final_fp);
            free(line_q);
        }

        fclose(final_fp);
		return (question);
    }
	else
	{
		//printf("Processing complete %d.\n", i_q);
		return (i_q);
	}

    //printf("Processing complete.\n");
    return (0);
}

void calculate_time_difference(const char *start_str) {
    struct tm start_tm = {0};
    struct tm end_tm = {0};
    time_t start_time, end_time;
    double seconds_difference;
    int hours, minutes, seconds;

    // Extract date and time components from the string
    if (sscanf(start_str, "T:%d/%d/%d %d:%d:%d",
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

char *control_date(void) 
{
    struct tm start_tm = {0};
	FILE *control_fp = fopen("control/control.txt", "r");

    if (!control_fp)
    {
        perror("Error opening file control/control.txt");
        return ("");
    }

    char	line[MAX_LINE_LENGTH];
    char	*line_t = NULL;
    
    while (fgets(line, sizeof(line), control_fp))
    {
        if (strncmp(line, "T:", 2) == 0)
            line_t = strdup(line);
    }
    fclose(control_fp);
	    if (sscanf(line_t, "T:%d/%d/%d %d:%d:%d",
               &start_tm.tm_mday, &start_tm.tm_mon, &start_tm.tm_year,
               &start_tm.tm_hour, &start_tm.tm_min, &start_tm.tm_sec) != 6)
	{
        fprintf(stderr, "Error parsing date string\n");
        return ("");
    }
    return (line_t);
}

char *control_penal(void) 
{
	printf("%s\n Please be patient, this CAN take several minutes...\n (10 seconds is fast, 30 seconds is expected, 3 minutes is a maximum)\n\n", WHITE);
	printf("%s waiting...\n\n", YELLOW);
	FILE *control_fp = fopen("control/control.txt", "r");

    if (!control_fp)
    {
        perror("Error opening file control/control.txt");
        return ("");
    }

    char	line[MAX_LINE_LENGTH];
	char	*line_t = NULL;
    char	*line_p = NULL;
	char	*line_q = NULL;
	char	*str_p = NULL;
	char 	*new_line_p = strdup("P:");
	int		penal = 0;
	
    while (fgets(line, sizeof(line), control_fp))
    {
        if (strncmp(line, "T:", 2) == 0)
            line_t = strdup(line);
        if (strncmp(line, "P:", 2) == 0)
            line_p = strdup(line);		
        else
			line_q = strdup(line); 		
    }
    fclose(control_fp);
	penal = atoi(line_p + 2);
	penal += penal;
	if (penal > 180)
		penal = 10;
	str_p = ft_itoa(penal);
	strcat(new_line_p, str_p);
	strcat(new_line_p, "\n");
	line_p = new_line_p;
	FILE *final_fp = fopen("control/control.txt", "w");
	if (!final_fp)
	{
		perror("Error opening files for final writing");
		return ("");
	}
	if (line_t) {
		fputs(line_t, final_fp);
		free(line_t);
	}
	if (line_p) {
		fputs(line_p, final_fp);
		free(line_p);
	}
	if (line_q) {
		fputs(line_q, final_fp);
		free(line_q);
	}		
	fclose(final_fp);
	
	sleep(penal);
	return ("");
}

void    print_msg (const char *str1, const char *sfile)
{
	char        *username = getlogin();
    char        currentPath[MAX_PATH];
    char        *currentDirPath = getcwd(currentPath, MAX_PATH);
		
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
		printf("%s %s\n\n", GREEN, control_date() + 2);
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
		calculate_time_difference(control_date());
		printf("%s =====================================================================================\n", WHITE);
		printf("%s You can work on your assignesent.\n When you are sure you're done with it, use the \"./grademe\" command to be graded.\n", WHITE);
	}
}

int	check_norminette(const char *filename)
{
	char		buffer[128];
	FILE		*pipe;
	int			error_count;
	char		command[256];

	error_count = 0;
	snprintf(command, sizeof(command), "norminette %s", filename);
	pipe = popen(command, "r");
	if (!pipe)
	{
		fprintf(stderr, "Error al ejecutar norminette.\n");
		return (-1);
	}
	while (fgets(buffer, sizeof(buffer), pipe) != NULL)
	{
		if (strstr(buffer, ".c: OK!") != NULL)
			printf("%s%s", GREEN, buffer);
		else
			printf("%s%s", RED, buffer);
		if (strstr(buffer, "Error") != NULL)
			error_count++;
	}
	if (pclose(pipe) == -1) 
	{
		fprintf(stderr, "Error al cerrar la tubería.\n");
		return (-1);
	}
	if (error_count > 1)
		error_count--;	
	if (error_count > 0)
		control_penal();
	return (error_count);
}

/*** Ejecuta norminette y abre una tubería para leer su salida
 * int	check_norminette(const char *filename)
 * Lee la salida de norminette línea por línea
 * Imprime la salida de norminette para depuración
 * Cuenta los errores (esto es una simplificación; deberías ajustar esto 
   según la salida real de norminette)
 * Cierra la tubería
*/

int mynorminette(const char *sfile)
{
    int         norminette;
    int         result;
    const char 	*color;

    printf("%s\n*********************NORMINETTE***********************\n", WHITE);
	norminette = 0;
		result = check_norminette(sfile);
		if (result == -1)
			printf("%sHubo un error al ejecutar norminette. ft_lstmap_bonus.c\n", RED);
		else
			norminette = norminette + result;
	if (norminette == 0)
        color = get_color(2);
	else
        color = get_color(1);
	if (norminette == 0)
		printf("%s\tNorminette: OK!\n", color);
	else
		printf("%sErrores Norminette: %d\n", color, norminette);
	printf("%s******************************************************\n", color);
    return (0);
}

void remove_directory(const char *path) 
{
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char file_path[1024];
        struct stat statbuf;

        // Omitir las entradas "." y ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);

        if (stat(file_path, &statbuf) == 0) {
            if (S_ISDIR(statbuf.st_mode)) {
                // Recursivamente eliminar subdirectorio
                remove_directory(file_path);
            } else {
                // Eliminar archivo
                if (unlink(file_path) != 0) {
                    perror("unlink");
                }
            }
        }
    }

    closedir(dir);

    // Eliminar el directorio en sí
    if (rmdir(path) != 0) {
        perror("rmdir");
    }
}

int	main(int argc, char **argv)
{ 
    const char *color;
    int         i;
    int         second;
    time_t      current_time;
    struct tm   *time_info;

	printf("\033[H\033[J");
    color = get_color(7);
	printf("%s\n EXAM ZIP v1.0\n", WHITE);		
    time(&current_time);
    time_info = localtime(&current_time);
	i = control('G', 0);
    second = time_info->tm_sec;	
	second = second % 10;
	if (argc == 2 && (strncmp(argv[1], "reset", 5) == 0))
    {
		remove_directory("rendu");
		remove_directory("subjects");
		control('W', 0);
		printf("%s\n Inicializado, para comenzar prueba con ./grademe \"start\"\n\n", WHITE);
		return(0);
	}   
    if (argc == 2 && i == 0)
    {
        if (strncmp(argv[1], "start", 5) == 0)
        {
            if (second > 0 && second <= 5)
                control('W', 11);
            else
                control('W', 12);     
            new_folder("subjects");
            new_folder("rendu");
        }
        else
		{
            printf("%s\n El tiempo corre, prueba con ./grademe \"start\"\n\n", RED);
			return(0);
		}
    }
    i = control('G', 0);
    if (i > 0)
    {
        if (i > 0 && i < 14)
            if ((second > 0 && second <= 5) || i == 11)
            {
                if (check_file("subjects/aff_a.txt") == 0)
                {
                    print_msg ("questionX", "aff_a");
                    if (check_file("rendu/aff_a/aff_a.c") == 0)
                        check_norminette("rendu/aff_a/aff_a.c");
                    else
						control_penal();
                }
                else
                {
                    copy_file("questions/aff_a.txt", "subjects/aff_a.txt");//11
                    if (check_file("rendu/aff_a") != 0)
                        new_folder("rendu/aff_a");
                    print_msg ("questionX", "aff_a");
                }
            }
            else
            {
                if (check_file("subjects/aff_z.txt") == 0)
                {
                    print_msg ("questionX", "aff_z");
                    if (check_file("rendu/aff_z/aff_z.c") == 0)
                        check_norminette("rendu/aff_z/aff_z.c");
                    else
						control_penal();
                }
                else
                {
                    copy_file("questions/aff_z.txt", "subjects/aff_z.txt");//12
                    if (check_file("rendu/aff_z") != 0)
                        new_folder("rendu/aff_z");
                    print_msg ("questionX", "aff_z");
                }
            }
        else if (i > 20 && i < 24)
            if (second > 0 && second <= 3)
                printf("%s23 rev_print.c\n", color);//23
            else if (second >= 4 && second <= 6)
                printf("%s21 ft_putstr.c\n", color);//21
            else
                printf("%s22 ft_strlen.c\n", color);//22
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
            printf("%s SUCCESS\n\n", GREEN);
    }
    else
	    print_msg ("start", "");
    printf("\n");
    //(void)currentDirPath;
    //printf("Current path: %s\n", currentDirPath);
	return (0);
}
