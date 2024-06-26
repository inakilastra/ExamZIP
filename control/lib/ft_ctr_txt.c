/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctr_txt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:03:41 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/25 09:01:53 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libzip.h"

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
        || strcmp(sfile_txt, "control/ctrl_question.txt") == 0
        || strcmp(sfile_txt, "control/ctrl_grade.txt") == 0
        || strcmp(sfile_txt, "control/ctrl_try.txt") == 0)
    {
        i = atoi(line_get);
    }
    fclose(control_fp);
    if (get_write == 'W')
    {
       	if (strcmp(sfile_txt, "control/ctrl_mode.txt") == 0)
        {
            if (mode == 'P' || mode == 'p' || mode == 'T' || mode == 't')
                line_new = strdup("P");
            else
                line_new = strdup("R");
        } 
        if (strcmp(sfile_txt, "control/ctrl_type.txt") == 0)
        {
            if (mode == 'T' || mode == 't')
                line_new = strdup("T");
            else
                line_new = strdup("N");
        }       
        if (strcmp(sfile_txt, "control/ctrl_penal.txt") == 0)
        {
            i += i;
            if (mode == 'P' || mode == 'p')
                if (question == 0)
                    line_new = strdup(ft_myitoa(15));//15
                else
                    line_new = strdup(ft_myitoa(i));//i
            else
                if (question == 0)
                    line_new = strdup(ft_myitoa(60));
                else
                    line_new = strdup(ft_myitoa(i)); 
        }
        if (strcmp(sfile_txt, "control/ctrl_question.txt") == 0)
        {
            if (question == i)
                line_new = strdup(ft_myitoa(i));
            else
                line_new = strdup(ft_myitoa(question));
        }
        if (strcmp(sfile_txt, "control/ctrl_grade.txt") == 0)
        {
            line_new = strdup(ft_myitoa(question));
        }
        if (strcmp(sfile_txt, "control/ctrl_try.txt") == 0)
        {
            line_new = strdup(ft_myitoa(question));
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
