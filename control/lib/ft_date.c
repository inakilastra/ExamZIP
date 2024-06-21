#include "../../libzip.h"

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
    if (seconds_difference < 0)
    {
    	printf("%s╔═══════════════════════════════════════════════════════════════════════════════════╗\n", RED);
	    printf("%s║ End time is in the past.                                                          ║\n", RED);
	    printf("%s║ Parece que has inventado la máquina del tiempo... ¡pero viajaste demasiado lejos! ║\n", RED);
	    printf("%s║ Por favor, regresa al presente y vuelve a intentarlo.                             ║\n", RED);
    	printf("%s╚═══════════════════════════════════════════════════════════════════════════════════╝\n", RED);
    	printf("\n");    
        //fprintf(stderr, "End time is in the past\n");
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