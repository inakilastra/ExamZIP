#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_itoa.c"

char	*ft_itoa(int n);

#define MAX_LINE_LENGTH 256

int control(const char get_write, int question) 
{
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
        line_t = strdup("T:1\n");
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