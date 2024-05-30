/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:53:57 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/30 12:53:59 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

#define MAX_LINE_LENGTH 256

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
	char	*line_q = NULL;
    int		i_q = 0;
    
    while (fgets(line, sizeof(line), control_fp)) // Leer y procesar el archivo original
    {
        if (strncmp(line, "T:", 2) == 0)
            line_t = strdup(line);  // Guardar línea T:
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

char *control_date(void) 
{
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
    return (line_t);
}
