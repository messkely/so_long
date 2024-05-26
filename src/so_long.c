/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:32:45 by messkely          #+#    #+#             */
/*   Updated: 2024/05/26 15:37:04 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	flood_fill_coin(t_map *my_map, int y, int x)
{
	if (my_map->map2d[y][x] == '1' || my_map->map2d[y][x] == 'x')
		return ;
	if (my_map->map2d[y][x] == 'E')
		return ;
	if (my_map->map2d[y][x] == 'C')
		my_map->c--;
	my_map->map2d[y][x] = 'x';
	flood_fill_coin(my_map, y - 1, x);
	flood_fill_coin(my_map, y + 1, x);
	flood_fill_coin(my_map, y, x + 1);
	flood_fill_coin(my_map, y, x - 1);
}

void	flood_fill_exit(t_map *my_map, int y, int x)
{
	if (my_map->map2d[y][x] == '1' || my_map->map2d[y][x] == 'y')
		return ;
	if (my_map->map2d[y][x] == 'E')
		my_map->exit = true;
	my_map->map2d[y][x] = 'y';
	flood_fill_exit(my_map, y - 1, x);
	flood_fill_exit(my_map, y + 1, x);
	flood_fill_exit(my_map, y, x + 1);
	flood_fill_exit(my_map, y, x - 1);
}

void f()
{
	system("leaks so_long");
}
int	main(int ac, char **av)
{
	t_map	my_map;
	t_mlx	my_mlx;

	if (ac != 2)
	{
		write(2, "usage: ./so_long *.ber\n", 23);
		exit(1);
	}
	atexit(f);
	read_map(av[1], &my_map);
	my_map.exit = false;
	flood_fill_coin(&my_map, my_map.player_pos.y, my_map.player_pos.x);
	if (my_map.c)
		ft_error();
	flood_fill_exit(&my_map, my_map.player_pos.y, my_map.player_pos.x);
	if (my_map.exit == false)
		ft_error();
	free_map(&my_map);
	read_map(av[1], &my_map);
	mlx_workspace(&my_mlx, &my_map);
}
