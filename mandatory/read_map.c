/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:42:14 by messkely          #+#    #+#             */
/*   Updated: 2024/04/28 15:46:12 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	check(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	check_file_is_valid(char *file)
{
	while (*file)
	{
		if (*file == '.')
			if (check(file, ".ber"))
				return;
		file++;
	}
	printf("ERROR: file is not valid\n");
	exit(1);
}

char *ft_read_map(char *map_path)
{
	int fd;
	char c;
	char *map;
	int count;

	fd = open(map_path, O_RDONLY);
	count = 0;
	if (fd < 0)
		exit(1);
	while (read(fd, &c, 1) == 1)
		count++;
	if (count == 0)
		exit(1);
	map = (char *)malloc((count + 1) * sizeof(char));
	if (!map)
		return (NULL);
	close(fd);
	fd = open(map_path, O_RDONLY);
	read(fd, map, count);
	map[count] = '\0';
	close(fd);
	return (map);
}
