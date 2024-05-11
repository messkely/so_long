/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:32:45 by messkely          #+#    #+#             */
/*   Updated: 2024/05/11 15:55:20 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void flood_fill(t_map *my_map, int y, int x)
{
	if (my_map->map2d[y][x] == '1' || my_map->map2d[y][x] == 'x')
		return;
	if (my_map->map2d[y][x] == 'E')
	{
		if (!my_map->C)
			my_map->exit_flag = 1;
		return ;
	}
	if (my_map->map2d[y][x] == 'C')
		my_map->C--;
	printf("coin: %d\n", my_map->C);
	my_map->map2d[y][x] = 'x';
	flood_fill(my_map, y - 1, x);
	flood_fill(my_map, y + 1, x);
	flood_fill(my_map, y, x + 1);
	flood_fill(my_map, y, x - 1);
}

void f(void)
{
	system("leaks so_long");
}
int main(int ac, char **av)
{
	t_map *my_map;
	// t_mlx my_mlx;
	if (ac != 2)
	{
		write(2, "usage: ./so_long *.ber\n", 23);
		exit(1);
	}

	my_map = malloc(sizeof(t_map));
	if (!my_map)
	{
		perror("Failed to allocate memory for map");
		exit(1);
	}
	read_map(av[1], my_map);
	flood_fill(my_map, my_map->player_pos.y, my_map->player_pos.x);
	if (my_map->C || my_map->exit_flag)
		ft_error();
	free_map(my_map);
	// read_map(av[1], my_map);
	// mlx_workspace(&my_mlx, my_map);
	// free_game(&my_mlx, my_map);
	atexit(f);
}
