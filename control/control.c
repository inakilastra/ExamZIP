#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void process_file(const char *control_file) {
    FILE *control_fp = fopen(control_file, "r");
    FILE *temp_fp = fopen("temp_control.txt", "w");

    if (!control_fp || !temp_fp) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    char *line_t = NULL;
    char *line_q = NULL;

    // Leer y procesar el archivo original
    while (fgets(line, sizeof(line), control_fp)) {
        if (strncmp(line, "T:", 2) == 0) {
            line_t = strdup(line);  // Guardar línea T:
        } else if (strncmp(line, "Q:", 2) == 0) {
            line_q = strdup(line);  // Guardar línea Q:
        } else {
            fputs(line, temp_fp);  // Escribir otras líneas en el archivo temporal
        }
    }

    fclose(control_fp);

    // Reabrir el archivo temporal en modo lectura para escribir al principio
    fclose(temp_fp);
    temp_fp = fopen("temp_control.txt", "r+");
    FILE *final_fp = fopen("final_control.txt", "w");

    if (!temp_fp || !final_fp) {
        perror("Error opening files for final writing");
        return;
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

    // Copiar el contenido del archivo temporal al archivo final
    while (fgets(line, sizeof(line), temp_fp)) {
        fputs(line, final_fp);
    }

    fclose(temp_fp);
    fclose(final_fp);

    // Reemplazar el archivo original con el archivo final
    if (remove(control_file) != 0) {
        perror("Error deleting original file");
        return;
    }

    if (rename("final_control.txt", control_file) != 0) {
        perror("Error renaming final file");
    }

    // Eliminar el archivo temporal
    remove("temp_control.txt");
}

int main() {
    const char *control_file = "control.txt";

    process_file(control_file);

    printf("Processing complete.\n");
    return 0;
}