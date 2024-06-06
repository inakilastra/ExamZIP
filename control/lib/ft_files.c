/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:38:34 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/06 15:53:13 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libzip.h"


int	ft_check_file(const char *str)
{
	char	check_path[1024];

	snprintf(check_path, sizeof(check_path), "%s", str);
	if (access(check_path, F_OK) != 0)
		return (1);
	return (0);
}

int	ft_new_folder(const char *dir)
{
	if (mkdir(dir, 0755) == -1)
		if (errno != EEXIST)
			return (1);
	return (0);
}

int	ft_copy_file(const char *src, const char *dst)
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
