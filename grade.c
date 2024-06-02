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

void remove_directory(const char *path) 
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
    char check_path[256];

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

char *ctr_txt(const char *sfile_txt, const char get_write, char mode, int question) 
{
    char	line[MAX_LINE_LENGTH];
    char	*line_get = NULL;
    char    *line_new = NULL;
    int     i = 0;

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
                    line_new = strdup(ft_itoa(1));
                else
                    line_new = strdup(ft_itoa(i));
            else
                if (question == 0)
                    line_new = strdup(ft_itoa(5));
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
if (strcmp(sfile_txt, "control/ctrl_time.txt") != 0)
{       
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

void    print_msg (const char *str1, const char *sfile)
{
	char        *username = getlogin();
    char        currentPath[MAX_PATH];
    char        *currentDirPath = getcwd(currentPath, MAX_PATH);
    char         *mode;

    mode = ctr_txt("control/ctrl_mode.txt", 'G', 'P', 0);
	if (strncmp(str1, "start", 5) == 0)
		printf("%s\n Prueba a poner: ./grademe \"start\" para empezar\n\n", RED);
	if (strncmp(str1, "empezamos", 9) == 0)
	{
		printf("%s\n You're connected: %s%s\n", WHITE, GREEN, username); 
		printf("%s You can log out at any time.", WHITE); 
		printf("%s If this program tells you you earned points\n", WHITE);
		printf("%s then they will be counted whatever happens.\n\n", WHITE);
		printf("%s You are about to start the project %sExam ZIP%s, in", WHITE, GREEN, WHITE);
        if ((strncmp(mode, "P", 1) == 0) || (strncmp(mode, "p", 1) == 0))
            printf("%s PRACTICE%s mode, at level.\n", MAGENTA, WHITE);
        else
            printf("%s REAL%s mode, at level.\n", MAGENTA, WHITE);
		printf("%s You would have 3hrs to complete this project.\n", WHITE);
		printf("%s Start exam ZIP --> ", WHITE);     
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
		//calculate_time_difference(control_date());
		printf("%s =====================================================================================\n", WHITE);
		printf("%s You can work on your assignesent.\n When you are sure you're done with it, use the \"./grademe\" command to be graded.\n", WHITE);
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

    line_g = ctr_txt("control/ctrl_mode.txt", 'G', c, 0);
    if (line_g)
        printf("%s %s\n", line_g, WHITE);
    if (line_g)        
        free(line_g);
    line_g = ctr_txt("control/ctrl_penal.txt", 'G', c, 0);
    if (line_g)
        printf("%s %s\n", line_g, WHITE);
    if (line_g)        
        free(line_g);
    line_g = ctr_txt("control/ctrl_question.txt", 'G', c, 0);
    if (line_g)
        printf("%s %s\n", line_g, WHITE);
    if (line_g)        
        free(line_g);
    line_g = ctr_txt("control/ctrl_time.txt", 'G', c, 0);
    if (line_g)
        printf("%s %s\n", line_g, WHITE);
    if (line_g)        
        free(line_g);
}

void    ctrl_txt_reset(const char c)
{
    ctr_txt("control/ctrl_mode.txt", 'W', c, 0);// Mode P
    ctr_txt("control/ctrl_penal.txt", 'W', c, 0);// Penal 0 reinicia 1 en P 5 en R
    ctr_txt("control/ctrl_question.txt", 'W', c, 0);// Mode P
}

void    ctrl_txt_start(const char c)
{
    ft_file("aff_a");
    ctr_txt("control/ctrl_time.txt", 'W', c, 0);// Mode P
}

void	ft_start(const char c)
{
	//printf("%s\n ft_start %c\n\n", WHITE, c);
    ctrl_txt_reset(c);
    ctrl_txt_start(c);
    new_folder("subjects");
    new_folder("rendu");
    ctrl_txt_show(c);
}

void	ft_help(void)
{
	int	    i = 0;
	char    *q_text = ctr_txt("control/ctrl_question.txt", 'G', 'X', 0);
    if (q_text)
    {
        i = atoi(q_text);
        free(q_text);
    }
	if (i > 0)
    {
		printf("%s\n CABECERA\n\n", GREEN);
    }
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

void	ft_reset(const char c)
{
	ctrl_txt_reset(c);
    remove_directory("rendu");
	remove_directory("subjects");
	/* control('W', 0); */
	printf("%s\n Reinicializado, para comenzar prueba con ./grademe \"start\" %c\n\n", WHITE , c);
    ctrl_txt_show(c);
}

void	ft_grademe(void)
{
	printf("%s\n ft_grademe\n\n", WHITE);
    printf("%s\n CABECERA\n\n", GREEN);
}

int	main(int argc, char **argv)
{ 
	int i;

    printf("\033[H\033[J");
    printf("%s\n ExamZIP v1.0\n\n", WHITE);
	if (argc == 2 && (strncmp(argv[1], "help", 5) == 0) )  
    {
    	if (strncmp(argv[1], "help", 5) == 0) 
			ft_help();
        return(0);  
    }
    if (argc == 3 
        && ((strncmp(argv[1], "start", 5) == 0) || (strncmp(argv[1], "reset", 5) == 0))
        && (argv[2][0] == 'P' || argv[2][0] == 'R' || argv[2][0] == 'p' || argv[2][0] == 'r'))
    {
		if (strncmp(argv[1], "start", 5) == 0) 
			ft_start(argv[2][0]);

		if (strncmp(argv[1], "reset", 5) == 0)
			ft_reset(argv[2][0]);	
		return(0);
	}
    i = atoi(ctr_txt("control/ctrl_question.txt", 'G', 'P', 0));
    if (i == 0)
        print_msg ("start", "");
    else
	    ft_grademe();  
	return (0);
}
