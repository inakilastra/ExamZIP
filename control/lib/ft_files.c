/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:38:34 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/20 15:20:06 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libzip.h"

int		ft_check_file(const char *str)
{
	char	check_path[1024];

	snprintf(check_path, sizeof(check_path), "%s", str);
	if (access(check_path, F_OK) != 0)
		return (1);
	return (0);
}

int		ft_copy_file(const char *src, const char *dst)
{
	FILE	*source;
	FILE	*destination;
	char	buffer[1024];
	size_t	bytes;

	source = fopen(src, "rb");
	if (source == NULL)
	{
		perror("Error al abrir el archivo de origen");
		return (1);
	}
	destination = fopen(dst, "wb");
	if (destination == NULL)
	{
		perror("Error al abrir el archivo de destino");
		fclose(source);
		return (1);
	}
	while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0)
		fwrite(buffer, 1, bytes, destination);
	fclose(source);
	fclose(destination);
	return (0);
}

void	ft_file(const char *sfile)
{
    char 	*questions_txt = strdup("questions/");
    char 	*subjects_txt = strdup("subjects/");
    char 	*rendu_txt = strdup("rendu/");

	strcat(questions_txt, sfile);
	strcat(questions_txt, ".txt");
    strcat(subjects_txt, sfile);
	strcat(subjects_txt, ".txt");
    strcat(rendu_txt, sfile);
    
    ft_copy_file(questions_txt, subjects_txt);//11
    if (ft_check_file(rendu_txt) != 0)
        ft_new_folder(rendu_txt);
    print_msg ("questionX", sfile);
}

int		ft_new_folder(const char *dir)
{
	if (mkdir(dir, 0755) == -1)
		if (errno != EEXIST)
			return (1);
	return (0);
}

void	ft_remove_directory(const char *path)
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
                ft_remove_directory(file_path);
            else
                if (unlink(file_path) != 0)
                    perror("unlink");
        }
    }
    closedir(dir);
    if (rmdir(path) != 0)
        perror("rmdir");
}
