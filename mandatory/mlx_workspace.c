/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_workspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:28:45 by messkely          #+#    #+#             */
/*   Updated: 2024/05/11 15:26:18 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_game(t_mlx *mlx, t_map *map)
{
	int i;

	i = 0;
	while (i < map->size_y)
		free(map->map2d[i++]);
	free(map);
	exit_game(mlx);
}

void display_moves(t_mlx *mlx, t_map *map, action_t action, int y, int x)
{
	static int counter;
	char *str;

	if (action == MLX_PRESS && (map->map2d[y][x] != '1' || map->map2d[y][x] != 'E'))
	{
		ft_putnbr(++counter);
		write(1, "\n", 1);
		str = ft_itoa(counter);
		if (!str)
			return;
		if (mlx->moves_counter)
			mlx_delete_image(mlx->mlx_ptr, mlx->moves_counter);
		mlx->moves_counter = mlx_put_string(mlx->mlx_ptr, str, 0, 0);
		mlx_resize_image(mlx->moves_counter, GRADE, GRADE);
		free(str);
	}
}

int check_next_step(t_game *game, int y, int x)
{
	if (game->my_map->map2d[y][x] == '0')
		return (1);
	else if (game->my_map->map2d[y][x] == 'C')
	{
		game->my_map->coin_counter--;
		return (1);
	}
	else if (game->my_map->map2d[y][x] == 'E' && game->my_map->coin_counter == 0)
		mlx_close_window(game->my_mlx->mlx_ptr);
		// free_game(game->my_mlx, game->my_map);
	return (0);
}

void	update_map(t_map *my_map, t_mlx *my_mlx, int new_y, int new_x, action_t action)
{
	int y;
	int x;

	y = my_map->player_pos.y;
	x = my_map->player_pos.x;
	my_map->map2d[y][x] = '0';
	my_map->map2d[new_y][new_x] = 'P';
	my_map->player_pos.y = new_y;
	my_map->player_pos.x = new_x;
	reander_map(my_mlx, my_map);
	display_moves(my_mlx, my_map, action, y, x);
}
void ft_key_press(mlx_key_data_t keydata, void *param)
{
	t_game *game;
	int y;
	int x;

	game = param;
	y = game->my_map->player_pos.y;
	x = game->my_map->player_pos.x;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->my_mlx->mlx_ptr);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		if (check_next_step(game, y - 1, x))
			update_map(game->my_map, game->my_mlx, y - 1, x, keydata.action);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		if (check_next_step(game, y + 1, x))
			update_map(game->my_map, game->my_mlx, y + 1, x, keydata.action);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		if (check_next_step(game, y, x - 1))
			update_map(game->my_map, game->my_mlx, y, x - 1, keydata.action);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		if (check_next_step(game, y, x + 1))
			update_map(game->my_map, game->my_mlx, y, x + 1, keydata.action);
}

void reander_map(t_mlx *my_mlx, t_map *my_map)
{
	int y;
	int x;

	y = 0;
	while (my_map->map2d[y])
	{
		x = 0;
		while (my_map->map2d[y][x])
		{
			if (mlx_image_to_window(my_mlx->mlx_ptr, my_mlx->bg_img, x * GRADE, y * GRADE) < 0)
				free_game(my_mlx, my_map);
			if (my_map->map2d[y][x] == '1' && mlx_image_to_window(my_mlx->mlx_ptr, my_mlx->wall_img, x * GRADE, y * GRADE) < 0)
				free_game(my_mlx, my_map);
			if (my_map->map2d[y][x] == 'P' && mlx_image_to_window(my_mlx->mlx_ptr, my_mlx->player_img, x * GRADE, y * GRADE) < 0)
				free_game(my_mlx, my_map);
			if (my_map->map2d[y][x] == 'C' && mlx_image_to_window(my_mlx->mlx_ptr, my_mlx->coin_img, x * GRADE, y * GRADE) < 0)
				free_game(my_mlx, my_map);
			if (my_map->map2d[y][x] == 'E' && mlx_image_to_window(my_mlx->mlx_ptr, my_mlx->exit_img, x * GRADE, y * GRADE) < 0)
				free_game(my_mlx, my_map);
			x++;
		}
		y++;
	}
}

void mlx_workspace(t_mlx *my_mlx, t_map *my_map)
{
	t_game game;

	game.my_map = my_map;
	game.my_mlx = my_mlx;

	game.my_mlx->mlx_ptr = mlx_init(my_map->size_x * GRADE, my_map->size_y * GRADE, "so_long", false);
	if (!my_mlx->mlx_ptr)
		exit(1);
	init_imgs(my_mlx);
	reander_map(my_mlx, my_map);
	// get_player_position(game);
	mlx_key_hook(my_mlx->mlx_ptr, ft_key_press, &game);
	mlx_loop(my_mlx->mlx_ptr);
}
