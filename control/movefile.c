/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:30:04 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/30 12:54:33 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

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