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

static int check(char *str, char *to_find)
{
	int i;

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

void check_file_is_valid(char *file)
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

// if (ac == 2)
// {

// void char_to_image()
// {}
int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

// int main(int ac, char **av)
// {
// 	char *map;
// 	char **map_lines;
// 	int height_map;
// 	int width_map;
// 	int i = 0;
// 	if (ac == 2)
// 	{
// 		check_file_is_valid(av[1]);
// 		map = ft_read_map(av[1]);
// 		map_lines = ft_split(map, '\n');
// 		width_map = ft_strlen(map_lines[0]);
// 		height_map = num_words(map, '\n');
// 		while (map_lines[i])
// 		{
// 			int j = 0;
// 			while (map_lines[i][j])
// 			{
// 				if (map[i] == '1')
// 				{
// 					char_to_image()
// 				}
// 			}
// 		}
// 		// printf("width_map : %d\n",width_map);
// 		// printf("height_map : %d\n",height_map);
// 		// printf("%s\n",map_lines[0]);
// 		free(map);
// 	}
// 	else
// 		write(1, "The program accept one param\n", 29);
// 	// atexit(ft_leaks);
// }
