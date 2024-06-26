/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grademe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:37:09 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/26 15:08:55 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libzip.h"

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
    ctr_txt("control/ctrl_type.txt", 'W', 'N', 0, "");// Mode P
    ctr_txt("control/ctrl_penal.txt", 'W', 'P', 0, "");// Penal 0 reinicia 1 en P 5 en R
    ctr_txt("control/ctrl_question.txt", 'W', 'P', 0, "");// Mode P
    ctr_txt("control/ctrl_grade.txt", 'W', 'P', 0, "");// Mode P
    ctr_txt("control/ctrl_try.txt", 'W', 'P', 0, "");// Mode P
}

void    ctrl_txt_start(const char c)
{
    int i;
    i = atoi(ctr_txt("control/ctrl_question.txt", 'G', 'P', 0, ""));
    ctr_txt("control/ctrl_time.txt", 'W', c, i, "");// Mode P
    ctr_txt("control/ctrl_type.txt", 'W', c, i, "");// Type 'c'
}

void	ft_start(const char c)
{
    //ctrl_txt_reset();
    ctrl_txt_start(c);
    ft_new_folder("subjects");
    ft_new_folder("rendu");
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
	printf("%s Ejecuta %s\"make\"\n\n", WHITE, CYAN);
    printf("%s Para preparar una simulación ejecuta  %s\"./grademe reset\"\n", WHITE, CYAN);
	printf("%s  OJO ESTO %sBORRA LA CARPETA \"rendu\"%s, si quieres conservar tus ficheros de dicha carpeta, muevelos antes\n\n", WHITE, RED, WHITE);      
	printf("%s Para comenzar una simulación ejecuta %s\"./grademe start R\"%s o %s\"./grademe start P\"\n", WHITE, CYAN, WHITE, CYAN);
    printf("%s  \"./grademe start P\" %sModo PRACTICE aleatoriamente te asigna las preguntas de los 8 niveles, te penaliza con menos tiempo de espera y ves el motivo del fallo:\n", CYAN, WHITE);
    printf("%s    El resultado que se esperaba recibir y lo que devuelve tu cógigo\n\n", WHITE);
    printf("%s  \"./grademe start T\" %sModo PRACTICE ALL QUESTIONS te asigna todas las preguntas (20) de los 8 niveles, te penaliza con menos tiempo de espera y ves el motivo del fallo:\n", CYAN, WHITE);
	printf("%s    El resultado que se esperaba recibir y lo que devuelve tu cógigo\n\n", WHITE);
    printf("%s  \"./grademe start R\" %sModo REAL te penaliza con más tiempo de espera y no ves el motivo del fallo\n", CYAN, WHITE);
	printf("%s    El resultado que se esperaba recibir y lo que devuelve tu cógigo\n\n", WHITE);
	printf("%s Para evaluar cada ejercicio ejecuta %s\"./grademe\"\n\n", WHITE, CYAN);
	printf("%s Si el ejercicio es una función %s\"ft_xxx.c\"%s ejecuta %s\"make\"\n\n", WHITE, CYAN, WHITE, CYAN);
    printf("%s Si sospechas que falla la compilación o quieres comprobrar ejecuta %s\"make\"\\n\n", WHITE, CYAN);
	printf("%s Para ver la ayuda ejecuta %s./grademe help\n\n", WHITE, CYAN);
    printf("%s Para ver bien los textos el fondo de la terminal tiene que ser negro\n\n", WHITE);    
}

void	ft_reset()
{
	ctrl_txt_reset();
    if (ft_check_file("rendu") == 0)
    {
        ft_remove_directory("rendu");
    }
    if (ft_check_file("subjects") == 0)
    {
        ft_remove_directory("subjects");
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
    char        *type;
    char 	    *rendu_c;
    int         penal=0;
    int         grade;
    int         try;
    int         second;
    int         i = 0;
	int			k = 0;
    int         show = 0;
    char        *paco;

    second = get_second();
    i = atoi(ctr_txt("control/ctrl_question.txt", 'G', 'P', 0, ""));
    name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
    mode = ctr_txt("control/ctrl_mode.txt", 'G', 'P', 0, "");
    type = ctr_txt("control/ctrl_type.txt", 'G', 'P', 0, "");
    penal = atoi(ctr_txt("control/ctrl_penal.txt", 'G', 'P', 0, ""));
    grade = atoi(ctr_txt("control/ctrl_grade.txt", 'G', 'P', 0, ""));
    try = atoi(ctr_txt("control/ctrl_try.txt", 'G', 'P', 0, ""));
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
                if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "aff_a", 5) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_aff_a(k, show);                        
                        if (k == 4)
                            i = ft_success_del_subject(name, show, 20, grade);
                        else							
                            ft_failure(show, try);
                    }
                }
                else
                {
                    ft_failure_check_file(name, show, try);
                }
            }
            else
            {
                if (ft_check_file(rendu_c) == 0)
                {   
                    if (strncmp(name, "aff_z", 5) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_aff_z(k, show);                           
                        if (k == 4)
                            i = ft_success_del_subject(name, show, 20, grade);
                        else
                            ft_failure(show, try);
                    }
                }
                else
                    ft_failure_check_file(name, show, try);
            }
        }
        
        if (i == 20)
        {
            ft_input_ok();
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
                if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "rev_print", 9) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_rev_print(k, show); 															
                        if (k == 3)
                            i = ft_success_del_subject(name, show, 30, grade);
                        else
                            ft_failure(show, try);
                    }
                }
                else
                    ft_failure_check_file(name, show, try);                
            }
            else if (i == 21)
            {
				if (ft_check_file(rendu_c) == 0)
                {
                        if (strncmp(name, "ft_putstr", 9) == 0)
                        {
                            k = 0;
							printf("%s\n PACO:\n\n", CYAN);
                            k = paco_ft_putstr(k, show);															
							if (k == 1)
							    i = ft_success_del_subject(name, show, 30, grade);
							else
							    ft_failure(show, try);
                        }
                }
                else
                    ft_failure_check_file(name, show, try);  				
            }
            else if (i == 22)
            {
				if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "ft_strlen", 9) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_ft_strlen(k, show);															
                        if (k == 1)
                            i = ft_success_del_subject(name, show, 30, grade);
                        else
                            ft_failure(show, try);
                    }
                }
                else
                    ft_failure_check_file(name, show, try);                
            }
        }

        if (i == 30)
        {
            ft_input_ok();
            if (second >= 0 && second <= 4)
            {
                ft_file("fizzbuzz");//31
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 31, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 31, "fizzbuzz");
            }
            else
            {
                ft_file("buzzfizz");//32
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 32, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 32, "buzzfizz");              
            }
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            mode = ctr_txt("control/ctrl_mode.txt", 'G', 'P', 0, "");

    		rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);         
        }  
            
        if (i > 30 && i < 34)
        {
            if (i == 31)
            {
                if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "fizzbuzz", 8) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_fizzbuzz(k, show);                        
                        if (k == 1)
                            i = ft_success_del_subject(name, show, 40, grade);
                        else							
                            ft_failure(show, try);
                    }
                }
                else
                {
                    ft_failure_check_file(name, show, try);
                }                
            }
            else
            {
                if (ft_check_file(rendu_c) == 0)
                {  
                    if (strncmp(name, "buzzfizz", 8) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_buzzfizz(k, show);                       
                        if (k == 1)
                            i = ft_success_del_subject(name, show, 40, grade);
                        else							
                            ft_failure(show, try);
                    }
                }
                else
                {
                    ft_failure_check_file(name, show, try);
                } 
            }
        }

       if (i == 40)
        {
            ft_input_ok();
            if (second >= 0 && second <= 4)
            {
                ft_file("aff_first_param");//41
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 41, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 41, "aff_first_param");
            }
            else
            {
                ft_file("aff_last_param");//42
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 42, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 42, "aff_last_param");              
            }
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            mode = ctr_txt("control/ctrl_mode.txt", 'G', 'P', 0, "");

    		rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);         
        } 

        if (i > 40 && i < 44)
        {
            if (i == 41)
            {
                if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "aff_first_param", 15) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_aff_first_param(k, show);                        
                        if (k == 3)
                            i = ft_success_del_subject(name, show, 50, grade);
                        else							
                            ft_failure(show, try);
                    }
            }
                else
                {
                    ft_failure_check_file(name, show, try);
                }                
            }
            else
            {
                if (ft_check_file(rendu_c) == 0)
                {   
                    if (strncmp(name, "aff_last_param", 14) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_aff_last_param(k, show);                        
                        if (k == 3)
                            i = ft_success_del_subject(name, show, 50, grade);
                        else							
                            ft_failure(show, try);
                    }
                }
                else
                {
                    ft_failure_check_file(name, show, try);
                } 
            }            
        }

        if (i == 50)
        {
            ft_input_ok();           
            if (second >= 0 && second <= 3)
            {
                ft_file("rotone");//53
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 53, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 53, "rotone");
            }
            else if (second >= 4 && second <= 6)
            {
                ft_file("first_word");//51
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 51, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 51, "first_word");              
            }
            else
            {
                ft_file("rot_13");//52
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 52, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 52, "rot_13");                
            }
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            mode = ctr_txt("control/ctrl_mode.txt", 'G', 'P', 0, "");

    		rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);              
        }

        if (i > 50 && i < 54)
        {
            if (i == 53)
            {
                if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "rotone", 6) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_rotone(k, show); 															
                        if (k == 5)
                            i = ft_success_del_subject(name, show, 60, grade);
                        else
                            ft_failure(show, try);
                    }
                }
                else
                    ft_failure_check_file(name, show, try);                
            }
            else if (i == 51)
            {
				if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "first_word", 10) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_first_word(k, show);															
                        if (k == 5)
                            i = ft_success_del_subject(name, show, 60, grade);
                        else
                            ft_failure(show, try);
                    }
                }
                else
                    ft_failure_check_file(name, show, try);  				
            }
            else if (i == 52)
            {
				if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "rot_13", 6) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_rot_13(k, show);															
                        if (k == 5)
                            i = ft_success_del_subject(name, show, 60, grade);
                        else
                            ft_failure(show, try);
                    }
                }
                else
                    ft_failure_check_file(name, show, try);                
            }            
        }

        if (i == 60)
        {
            ft_input_ok();             
            if (second >= 0 && second <= 3)
            {
                ft_file("last_word");//63
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 63, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 63, "last_word");
            }
            else if (second >= 4 && second <= 6)
            {
                ft_file("inter");//61
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 61, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 61, "inter");              
            }
            else
            {
                ft_file("union");//62
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 62, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 62, "union");                
            }
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            mode = ctr_txt("control/ctrl_mode.txt", 'G', 'P', 0, "");

    		rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);  
        }
        
        if (i >= 60 && i < 64)
        {
            if (i == 63)
            {
                if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "last_word", 9) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_last_word(k, show); 															
                        if (k == 5)
                            i = ft_success_del_subject(name, show, 70, grade);
                        else
                            ft_failure(show, try);
                    }
                }
                else
                    ft_failure_check_file(name, show, try);                
            }
            else if (i == 61)
            {
				if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "inter", 5) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_inter(k, show);															
                        if (k == 4)
                            i = ft_success_del_subject(name, show, 70, grade);
                        else
                            ft_failure(show, try);
                    }
                }
                else
                    ft_failure_check_file(name, show, try);  				
            }
            else if (i == 62)
            {
				if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "union", 5) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_union(k, show);															
                        if (k == 5)
                            i = ft_success_del_subject(name, show, 70, grade);
                        else
                            ft_failure(show, try);
                    }
                }
                else
                    ft_failure_check_file(name, show, try);                
            }            
        }

        if (i == 70)
        {
            ft_input_ok();                       
            if (second >= 0 && second <= 3)
            {
                ft_file("ft_rrange");//73
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 73, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 73, "ft_rrange");
            }
            else if (second >= 4 && second <= 6)
            {
                ft_file("ft_itoa");//71
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 71, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 71, "ft_itoa");              
            }
            else
            {
                ft_file("ft_range");//72
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 72, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 72, "ft_range");                
            }
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            mode = ctr_txt("control/ctrl_mode.txt", 'G', 'P', 0, "");

    		rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name); 
        }
        
        if (i > 70 && i < 74)
        {
            if (i == 73)
            {
                if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "ft_rrange", 9) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_ft_rrange(k, show); 															
                        if (k == 4)
                            i = ft_success_del_subject(name, show, 80, grade);
                        else
                            ft_failure(show, try);
                    }
                }
                else
                    ft_failure_check_file(name, show, try);                
            }
            else if (i == 71)
            {
				if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "ft_itoa", 7) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_ft_itoa(k, show);															
                        if (k == 4)
                            i = ft_success_del_subject(name, show, 80, grade);
                        else
                            ft_failure(show, try);
                    }
                }
                else
                    ft_failure_check_file(name, show, try);  				
            }
            else if (i == 72)
            {
				if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "ft_range", 8) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_ft_range(k, show);															
                        if (k == 4)
                            i = ft_success_del_subject(name, show, 80, grade);
                        else
                            ft_failure(show, try);
                    }
                }
                else
                    ft_failure_check_file(name, show, try);                
            } 
        }
   
        if (i == 80)
        {
            ft_input_ok();                                  
            if (second >= 0 && second <= 4)
            {
                ft_file("expand_str");//81prueba
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 81, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 81, "expand_str");
            }
            else
            {
                ft_file("ft_split");//82
                ctr_txt("control/ctrl_question.txt", 'W', mode[0], 82, "");
                ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 82, "ft_split");                
            }
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            mode = ctr_txt("control/ctrl_mode.txt", 'G', 'P', 0, "");

    		rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name); 
        }
             
        if (i > 80 && i < 84)
        {
            if (i == 81)
            {
                if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "expand_str", 10) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_expand_str(k, show); 															
                        if (k == 4)
                            i = ft_success_del_subject(name, show, 90, grade);
                        else
                            ft_failure(show, try);
                    }
                }
                else
                    ft_failure_check_file(name, show, try);                
            }
            else if (i == 82)
            {
				if (ft_check_file(rendu_c) == 0)
                {
                    if (strncmp(name, "ft_split", 8) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_ft_split(k, show);															
                        if (k == 2)
                            i = ft_success_del_subject(name, show, 90, grade);
                        else
                            ft_failure(show, try);
                    }
                }
                else
                    ft_failure_check_file(name, show, try);  				
            }            
        }
        
        if (i == 90)
        {
            printf("\n\n");
            printf("%s     Exam_42_ZIP passed, congratulations       \n", GREEN);
            printf("%s     Azterketa_42_ZIP gainditu da, zorionak    \n", GREEN);
            printf("%s     Exam_42_ZIP superat, felicitats           \n", GREEN);
            printf("%s     Exam_42_ZIP superado, felicidades         \n", GREEN);
            printf("\n");
	        printf("%s       ╔════════════════════════════════╗      \n", GREEN);
            printf("%s       ║            :::      ::::::::   ║      \n", GREEN);
            printf("%s       ║          :+:      :+:    :+:   ║      \n", GREEN);
            printf("%s       ║        +:+ +:+         +:+     ║      \n", GREEN);
            printf("%s       ║      +#+  +:+       +#+        ║      \n", GREEN);
            printf("%s       ║    +#+#+#+#+#+   +#+           ║      \n", GREEN);
            printf("%s       ║         #+#    #+#             ║      \n", GREEN);
            printf("%s       ║        ###   ########.fr       ║      \n", GREEN);
	        printf("%s       ╚════════════════════════════════╝      \n", GREEN);
            printf("\n");
            printf("%s           ██████████████████████████          \n", YELLOW);
            printf("%s           ██████████████████████████          \n", YELLOW);
            printf("%s      █████████████████████████████████████    \n", YELLOW);
            printf("%s    █████████████████████████████████████████  \n", YELLOW);
            printf("%s   ████      ██████████████████████       ████ \n", YELLOW);
            printf("%s   ███       ██████████████████████        ███ \n", YELLOW);
            printf("%s   ██        ██████████████████████        ███ \n", YELLOW);
            printf("%s   ███     ██████████████████████████      ███ \n", YELLOW);
            printf("%s   ███    ████████████████████████████    ████ \n", YELLOW);
            printf("%s    ███   ███ ████████████████████ ███    ███  \n", YELLOW);
            printf("%s    ████   ███ ██████████████████ ████  ████   \n", YELLOW);
            printf("%s      ████  █████████████████████████ █████    \n", YELLOW);
            printf("%s       ████████ ████████████████ █████████     \n", YELLOW);
            printf("%s         ██████  ██████████████   ██████       \n", YELLOW);
            printf("%s                  ████████████                 \n", YELLOW);
            printf("%s                    ████████                   \n", YELLOW);
            printf("%s                      ████                     \n", YELLOW);
            printf("%s                      ████                     \n", YELLOW);
            printf("%s                      ████                     \n", YELLOW);
            printf("%s                      ████                     \n", YELLOW);
            printf("%s                  ████████████                 \n", YELLOW);
            printf("%s               ██████████████████              \n", MAGENTA);
            printf("%s               ██████████████████              \n", MAGENTA);
            printf("%s               ███            ███              \n", MAGENTA);
            printf("%s               ███            ███              \n", MAGENTA);
            printf("%s               ███            ███              \n", MAGENTA);
            printf("%s               ██████████████████              \n", MAGENTA);
            printf("%s               ██████████████████              \n", MAGENTA);
            printf("%s             ██████████████████████            \n", MAGENTA);
            printf("%s            ████████████████████████           \n", MAGENTA);
            printf("\n\n\n");   
        }         
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


void	ft_grademeT(void)
{
	char        *name;
    char        *mode;
    char        *type;
    char 	    *rendu_c;
    int         penal=0;
    int         grade;
    int         try;
    int         second;
    int         i = 0;
	int			k = 0;
    int         show = 0;
    char        *paco;

    second = get_second();
    i = atoi(ctr_txt("control/ctrl_question.txt", 'G', 'P', 0, ""));
    name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
    mode = ctr_txt("control/ctrl_mode.txt", 'G', 'P', 0, "");
    type = ctr_txt("control/ctrl_type.txt", 'G', 'P', 0, "");
    penal = atoi(ctr_txt("control/ctrl_penal.txt", 'G', 'P', 0, ""));
    grade = atoi(ctr_txt("control/ctrl_grade.txt", 'G', 'P', 0, ""));
    try = atoi(ctr_txt("control/ctrl_try.txt", 'G', 'P', 0, ""));
    if ((strncmp(mode, "P", 1) == 0) || (strncmp(mode, "p", 1) == 0))
        show = 1;
    print_msg ("questionX", name);
    rendu_c = get_rendu_c(name);
    printf("%s\n Please be patient, this CAN take several minutes...\n (10 seconds is fast, 30 seconds is expected, 3 minutes is a maximum)\n\n", WHITE);
    printf("%s waiting...\n\n", YELLOW);
    sleep(penal);
    if (i > 0)
    {
        if (i == 11)
        {
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "aff_a", 5) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_aff_a(k, show);                        
                    if (k == 4)
                        i = ft_success_del_subject(name, show, 120, grade);
                    else							
                        ft_failure(show, try);
                }
            }
            else
            {
                ft_failure_check_file(name, show, try);
            }
        }
        
        if (i == 120)
        {
            ft_input_ok();
            ft_file("aff_z");//12
            ctr_txt("control/ctrl_question.txt", 'W', 'P', 12, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', 'P', 12, "aff_z");
            try = atoi(ctr_txt("control/ctrl_try.txt", 'G', 'P', 0, ""));
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);
        }
        if (i == 12)
        {                  
            if (ft_check_file(rendu_c) == 0)
            {   
                if (strncmp(name, "aff_z", 5) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_aff_z(k, show);                           
                    if (k == 4)
                        i = ft_success_del_subject(name, show, 210, grade);
                    else
                        ft_failure(show, try);
                }
            }
            else
                ft_failure_check_file(name, show, try);
        }
                
        if (i == 210)
        {
            ft_input_ok();    
            ft_file("ft_putstr");//21
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 21, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 21, "ft_putstr"); 
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);  
        }
        if (i == 21)
        { 
            if (ft_check_file(rendu_c) == 0)
            {
                    if (strncmp(name, "ft_putstr", 9) == 0)
                    {
                        k = 0;
                        printf("%s\n PACO:\n\n", CYAN);
                        k = paco_ft_putstr(k, show);															
                        if (k == 1)
                            i = ft_success_del_subject(name, show, 220, grade);
                        else
                            ft_failure(show, try);
                    }
            }
            else
                ft_failure_check_file(name, show, try);  				
        }
                
        if (i == 220)
        {
            ft_input_ok();
            ft_file("ft_strlen");//22
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 22, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 22, "ft_strlen"); 
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);
        }
        if (i == 22)
        {         
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "ft_strlen", 9) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_ft_strlen(k, show);															
                    if (k == 1)
                        i = ft_success_del_subject(name, show, 230, grade);
                    else
                        ft_failure(show, try);
                }
            }
            else
                ft_failure_check_file(name, show, try);                
        }

        if (i == 230)
        {
            ft_input_ok();
            ft_file("rev_print");//23
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 23, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 23, "rev_print");
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);    
        }
        if (i == 23)
        {                 
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "rev_print", 9) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_rev_print(k, show); 															
                    if (k == 3)
                        i = ft_success_del_subject(name, show, 310, grade);
                    else
                        ft_failure(show, try);
                }
            }
            else
                ft_failure_check_file(name, show, try);                
        }

        if (i == 310)
        {
            ft_input_ok();
            ft_file("fizzbuzz");//31
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 31, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 31, "fizzbuzz");
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);  
        }
        if (i == 31)
        {        
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "fizzbuzz", 8) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_fizzbuzz(k, show);                        
                    if (k == 1)
                        i = ft_success_del_subject(name, show, 320, grade);
                    else							
                        ft_failure(show, try);
                }
            }
            else
            {
                ft_failure_check_file(name, show, try);
            }                
        }
    
        if (i == 320)
        {
            ft_input_ok();
            ft_file("buzzfizz");//32
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 32, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 32, "buzzfizz");              
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);    
        }
        if (i == 32)
        {      
            if (ft_check_file(rendu_c) == 0)
            {  
                if (strncmp(name, "buzzfizz", 8) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_buzzfizz(k, show);                       
                    if (k == 1)
                        i = ft_success_del_subject(name, show, 410, grade);
                    else							
                        ft_failure(show, try);
                }
            }
            else
            {
                ft_failure_check_file(name, show, try);
            } 
        }

        if (i == 410)
        {
            ft_input_ok();
            ft_file("aff_first_param");//41
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 41, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 41, "aff_first_param");
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);     
        }
        if (i == 41)
        {     
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "aff_first_param", 15) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_aff_first_param(k, show);                        
                    if (k == 3)
                        i = ft_success_del_subject(name, show, 420, grade);
                    else							
                        ft_failure(show, try);
                }
        }
            else
            {
                ft_failure_check_file(name, show, try);
            }                
        }
            
        if (i == 420)
        {
            ft_input_ok();    
            ft_file("aff_last_param");//42
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 42, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 42, "aff_last_param");              
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);   
        }
        if (i == 42)
        {       
            if (ft_check_file(rendu_c) == 0)
            {   
                if (strncmp(name, "aff_last_param", 14) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_aff_last_param(k, show);                        
                    if (k == 3)
                        i = ft_success_del_subject(name, show, 510, grade);
                    else							
                        ft_failure(show, try);
                }
            }
            else
            {
                ft_failure_check_file(name, show, try);
            } 
        } 
    
        if (i == 510)
        {
            ft_input_ok(); 
            ft_file("first_word");//51
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 51, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 51, "first_word");              
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);          
        }
        if (i == 51)
        { 
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "first_word", 10) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_first_word(k, show);															
                    if (k == 5)
                        i = ft_success_del_subject(name, show, 520, grade);
                    else
                        ft_failure(show, try);
                }
            }
            else
                ft_failure_check_file(name, show, try);  				
        }

        if (i == 520)
        {
            ft_input_ok(); 
            ft_file("rot_13");//52
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 52, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 52, "rot_13");                
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);        
        }
        if (i == 52)
        {  
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "rot_13", 6) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_rot_13(k, show);															
                    if (k == 5)
                        i = ft_success_del_subject(name, show, 530, grade);
                    else
                        ft_failure(show, try);
                }
            }
            else
                ft_failure_check_file(name, show, try);                
        }
        
        if (i == 530)
        {
            ft_input_ok(); 
            ft_file("rotone");//53
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 53, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 53, "rotone");
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);        
        }
        if (i == 53)
        {  
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "rotone", 6) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_rotone(k, show); 															
                    if (k == 5)
                        i = ft_success_del_subject(name, show, 610, grade);
                    else
                        ft_failure(show, try);
                }
            }
            else
                ft_failure_check_file(name, show, try);                
        }

        if (i == 610)
        {
            ft_input_ok(); 
            ft_file("inter");//61
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 61, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 61, "inter");              
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);         
        }
        if (i == 61)
        { 
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "inter", 5) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_inter(k, show);															
                    if (k == 4)
                        i = ft_success_del_subject(name, show, 620, grade);
                    else
                        ft_failure(show, try);
                }
            }
            else
                ft_failure_check_file(name, show, try);  				
        }    
    
        if (i == 620)
        {
            ft_input_ok(); 
            ft_file("union");//62
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 62, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 62, "union");                
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);     
        }
        if (i == 62)
        {    
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "union", 5) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_union(k, show);															
                    if (k == 5)
                        i = ft_success_del_subject(name, show, 630, grade);
                    else
                        ft_failure(show, try);
                }
            }
            else
                ft_failure_check_file(name, show, try);                
        }   

        if (i == 630)
        {
            ft_input_ok(); 
            ft_file("last_word");//63
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 63, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 63, "last_word");
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);      
        }
        if (i == 63)
        {    
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "last_word", 9) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_last_word(k, show); 															
                    if (k == 5)
                        i = ft_success_del_subject(name, show, 710, grade);
                    else
                        ft_failure(show, try);
                }
            }
            else
                ft_failure_check_file(name, show, try);                
        }    

        if (i == 710)
        {
            ft_input_ok();
            ft_file("ft_itoa");//71
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 71, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 71, "ft_itoa");              
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name); 
        }
        if (i == 71)
        { 
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "ft_itoa", 7) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_ft_itoa(k, show);															
                    if (k == 4)
                        i = ft_success_del_subject(name, show, 720, grade);
                    else
                        ft_failure(show, try);
                }
            }
            else
                ft_failure_check_file(name, show, try);        
        }
        
        if (i == 720)
        {
            ft_input_ok();
            ft_file("ft_range");//72
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 72, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 72, "ft_range");  
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);        
        }
        if (i == 72)
        {        
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "ft_range", 8) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_ft_range(k, show);															
                    if (k == 4)
                        i = ft_success_del_subject(name, show, 730, grade);
                    else
                        ft_failure(show, try);
                }
            }
            else
                ft_failure_check_file(name, show, try); 
        }

        if (i == 730)
        {
            ft_input_ok();
            ft_file("ft_rrange");//73
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 73, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 73, "ft_rrange");
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name);     
        }
        if (i == 73)
        { 
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "ft_rrange", 9) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_ft_rrange(k, show); 															
                    if (k == 4)
                        i = ft_success_del_subject(name, show, 810, grade);
                    else
                        ft_failure(show, try);
                }
            }
            else
                ft_failure_check_file(name, show, try); 
        }

        if (i == 810)
        {    
            ft_input_ok(); 
            ft_file("expand_str");//81prueba
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 81, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 81, "expand_str");
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name); 
        }
        if (i == 81)
        { 
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "expand_str", 10) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_expand_str(k, show); 															
                    if (k == 4)
                        i = ft_success_del_subject(name, show, 820, grade);
                    else
                        ft_failure(show, try);
                }
            }
            else
                ft_failure_check_file(name, show, try);            
        }

        if (i == 820)
        {    
            ft_input_ok(); 
            ft_file("ft_split");//82
            ctr_txt("control/ctrl_question.txt", 'W', mode[0], 82, "");
            ctr_txt("control/ctrl_question_name.txt", 'W', mode[0], 82, "ft_split");                
            name = ctr_txt("control/ctrl_question_name.txt", 'G', 'P', 0, "");
            rendu_c = strdup(get_rendu_c(name));		
            printf("\033[H\033[J");
            printf("%s\n Exam_42_ZIP v1.03\n\n", WHITE);		
            print_msg ("questionX", name); 
        }
        if (i == 82)
        { 
            if (ft_check_file(rendu_c) == 0)
            {
                if (strncmp(name, "ft_split", 8) == 0)
                {
                    k = 0;
                    printf("%s\n PACO:\n\n", CYAN);
                    k = paco_ft_split(k, show);															
                    if (k == 2)
                        i = ft_success_del_subject(name, show, 90, grade);
                    else
                        ft_failure(show, try);
                }
            }
            else
                ft_failure_check_file(name, show, try);        
        }

            
        if (i == 90)
        {
            printf("\n\n");
            printf("%s     Exam_42_ZIP passed, congratulations       \n", GREEN);
            printf("%s     Azterketa_42_ZIP gainditu da, zorionak    \n", GREEN);
            printf("%s     Exam_42_ZIP superat, felicitats           \n", GREEN);
            printf("%s     Exam_42_ZIP superado, felicidades         \n", GREEN);
            printf("\n");
	        printf("%s       ╔════════════════════════════════╗      \n", GREEN);
            printf("%s       ║            :::      ::::::::   ║      \n", GREEN);
            printf("%s       ║          :+:      :+:    :+:   ║      \n", GREEN);
            printf("%s       ║        +:+ +:+         +:+     ║      \n", GREEN);
            printf("%s       ║      +#+  +:+       +#+        ║      \n", GREEN);
            printf("%s       ║    +#+#+#+#+#+   +#+           ║      \n", GREEN);
            printf("%s       ║         #+#    #+#             ║      \n", GREEN);
            printf("%s       ║        ###   ########.fr       ║      \n", GREEN);
	        printf("%s       ╚════════════════════════════════╝      \n", GREEN);
            printf("\n");
            printf("%s           ██████████████████████████          \n", YELLOW);
            printf("%s           ██████████████████████████          \n", YELLOW);
            printf("%s      █████████████████████████████████████    \n", YELLOW);
            printf("%s    █████████████████████████████████████████  \n", YELLOW);
            printf("%s   ████      ██████████████████████       ████ \n", YELLOW);
            printf("%s   ███       ██████████████████████        ███ \n", YELLOW);
            printf("%s   ██        ██████████████████████        ███ \n", YELLOW);
            printf("%s   ███     ██████████████████████████      ███ \n", YELLOW);
            printf("%s   ███    ████████████████████████████    ████ \n", YELLOW);
            printf("%s    ███   ███ ████████████████████ ███    ███  \n", YELLOW);
            printf("%s    ████   ███ ██████████████████ ████  ████   \n", YELLOW);
            printf("%s      ████  █████████████████████████ █████    \n", YELLOW);
            printf("%s       ████████ ████████████████ █████████     \n", YELLOW);
            printf("%s         ██████  ██████████████   ██████       \n", YELLOW);
            printf("%s                  ████████████                 \n", YELLOW);
            printf("%s                    ████████                   \n", YELLOW);
            printf("%s                      ████                     \n", YELLOW);
            printf("%s                      ████                     \n", YELLOW);
            printf("%s                      ████                     \n", YELLOW);
            printf("%s                      ████                     \n", YELLOW);
            printf("%s                  ████████████                 \n", YELLOW);
            printf("%s               ██████████████████              \n", MAGENTA);
            printf("%s               ██████████████████              \n", MAGENTA);
            printf("%s               ███            ███              \n", MAGENTA);
            printf("%s               ███            ███              \n", MAGENTA);
            printf("%s               ███            ███              \n", MAGENTA);
            printf("%s               ██████████████████              \n", MAGENTA);
            printf("%s               ██████████████████              \n", MAGENTA);
            printf("%s             ██████████████████████            \n", MAGENTA);
            printf("%s            ████████████████████████           \n", MAGENTA);
            printf("\n\n\n");   
        }         
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
    char        *type;

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
        && (argv[2][0] == 'P' || argv[2][0] == 'p'
        || argv[2][0] == 'R' || argv[2][0] == 'r'
        || argv[2][0] == 'T' || argv[2][0] == 't'))
    {
		if (strncmp(argv[1], "start", 5) == 0)
        {
            if (i == 0)
            {
                ctr_txt("control/ctrl_type.txt", 'G', argv[2][0], 0, "");
                type = &argv[2][0];
                ft_start(argv[2][0]);
                if ((strncmp(type, "T", 1) == 0) || (strncmp(type, "t", 1) == 0))
                    second = 3;
                if (second >= 0 && second <= 4)
                {
                    ft_file("aff_a");//11
                    ctr_txt("control/ctrl_question.txt", 'W', argv[2][0], 11, "");
                    ctr_txt("control/ctrl_question_name.txt", 'W', argv[2][0], 11, "aff_a");
                }
                else
                {
                    ft_file("aff_z");//12
                    ctr_txt("control/ctrl_question.txt", 'W', argv[2][0], 12, "");
                    ctr_txt("control/ctrl_question_name.txt", 'W', argv[2][0], 12, "aff_z");
                }
                return (0);
            }
            else
            {
                if ((strncmp(type, "T", 1) == 0) || (strncmp(type, "t", 1) == 0))
                    ft_grademeT();
                else
                    ft_grademe(); 
            }
        }
	}
    type = ctr_txt("control/ctrl_type.txt", 'G', argv[2][0], 0, "");
    if (i == 0)
       print_msg ("start", "");
    else
    {
        if ((strncmp(type, "T", 1) == 0) || (strncmp(type, "t", 1) == 0))
            ft_grademeT();
        else
            ft_grademe(); 
    }  
	return (0);
}
