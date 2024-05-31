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
        if (strcmp(sfile_txt, "control/ctrl_question.txt") == 0)
        {
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
    ctr_txt("control/ctrl_time.txt", 'W', c, 0);// Mode P
}

void	ft_start(const char c)
{
	//printf("%s\n ft_start %c\n\n", WHITE, c);
    ctrl_txt_reset(c);
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
    else
    {
        printf("%s\n ExamZIP v1.0\n\n", WHITE);
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
	printf("%s  (OJO ESTO BORRA LA CARPETA %s\"rendu\"%s, si quieres conservar tus ficheros muevelos antes)\n\n", WHITE, RED, WHITE);
	printf("%s Para ver la ayuda ejecuta %s./grademe help\n\n", WHITE, CYAN);
}

void	ft_reset(const char c)
{
	ctrl_txt_reset(c);
/* 	remove_directory("rendu");
	remove_directory("subjects");
	control('W', 0); */
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
	printf("\033[H\033[J");
	if (argc == 2 && (strncmp(argv[1], "help", 5) == 0) )  
    	if (strncmp(argv[1], "help", 5) == 0) 
			ft_help();  
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
	ft_grademe();  
	return (0);
}
