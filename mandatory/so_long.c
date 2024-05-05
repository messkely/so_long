/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:32:45 by messkely          #+#    #+#             */
/*   Updated: 2024/04/18 08:32:48 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_error(void)
{
	write(1, "Error\n", 5);
	exit(1);
}
int ft_serch(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_find[j])
		{
			if (str[i] == to_find[j])
				break;
			j++;
		}
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

int is_duplicated(char *str)
{
	int i;
	int count_P;
	int count_E;
	int count_C;

	i = 0;
	count_P = 0;
	count_E = 0;
	count_C = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			count_P++;
		else if (str[i] == 'E')
			count_E++;
		else if (str[i] == 'C')
			count_C++;
		i++;
	}
	if (count_P != 1 || count_E != 1 || count_C < 1)
		return (1);
	return (0);
}


void check_walls(char *map)
{
	int i = 0;
	while (map[i] == '1' && map[i] != '\n')
		i++;
	if (map[i] != '\n')
		ft_error();
	while (map[i])
	{
		if (map[i - 1] == '\n' && (map[i] != '1' || map[i - 2] != '1'))
			ft_error();
		i++;
	}
	i--;
	while (map[i] != '\n' && map[i] == '1')
		i--;
	if (map[i] != '\n')
		ft_error();
}

void check_map_is_valid(char *map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (!ft_serch(map, "01CEP") || is_duplicated(map))
			ft_error();
		i++;
	}
	check_walls(map);
}

void	flood_fill()
{
	d;
}
int main(int ac, char **av)
{
	t_map *map;
	char *map2d;

	if (ac != 2)
	{
		write(2, "usage: ./so_long *.ber\n", 23);
		exit(1);
	}
	map2d = ft_read_map(av[1]);
	check_map_is_valid(map2d);
}
