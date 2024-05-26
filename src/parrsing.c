/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parrsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:28:09 by messkely          #+#    #+#             */
/*   Updated: 2024/05/25 12:48:43 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	int	ft_search(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'P' && str[i] != 'E' && str[i] != 'C'
			&& str[i] != '1' && str[i] != '0' && str[i] != '\n')
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

static	int	is_duplicated(char *str, t_map *my_map)
{
	int	i;
	int	count_p;
	int	count_e;
	int	count_c;

	i = 0;
	count_p = 0;
	count_e = 0;
	count_c = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			count_p++;
		else if (str[i] == 'E')
			count_e++;
		else if (str[i] == 'C')
			count_c++;
		i++;
	}
	my_map->coin_counter = count_c;
	if (count_p != 1 || count_e != 1 || count_c < 1)
		return (1);
	return (0);
}

static int	check_first_wall(char *map, int i)
{
	if (map[i] != '1')
		ft_error();
	while (map[i] == '1' && map[i] != '\n')
		i++;
	if (map[i] != '\n')
		ft_error();
	return (i);
}

static void	check_walls(char *map)
{
	int	i;

	i = 0;
	i = check_first_wall(map, i);
	while (map[i])
	{
		if (map[i] == '\n')
		{
			i++;
			if (map[i] != '1')
				ft_error();
			while (map[i] != '\n' && map[i] != '\0')
				i++;
			if (map[i - 1] != '1')
				ft_error();
		}
	}
	i--;
	while (map[i] != '\n' && map[i] == '1')
		i--;
	if (map[i] != '\n' && map[i] != '\0')
		ft_error();
}

void	check_map_is_valid(char *map, t_map *my_map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!ft_search(map) || is_duplicated(map, my_map))
			ft_error();
		i++;
	}
	check_walls(map);
}
