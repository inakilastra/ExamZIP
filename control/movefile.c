/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:30:04 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/29 16:39:21 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int	checkfile(const char *str)
{
    char check_path[256]; // Ajusta el tamaño según sea necesario

    // Construir la ruta del archivo actual
    snprintf(check_path, sizeof(check_path), "%s", str);  
    // Verificar si el archivo existe en la ruta original
    if (access(check_path, F_OK) != 0)
        return (1);
    return (0);
}

int	movefile(const char *src, const char *dst)
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

int new_folder(const char *dir)
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
