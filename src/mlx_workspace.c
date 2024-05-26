/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_workspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:28:45 by messkely          #+#    #+#             */
/*   Updated: 2024/05/21 09:05:10 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_game(t_mlx *mlx, t_map *map)
{
	free_map(map);
	exit_game(mlx);
}

void	display_moves(t_game game, action_t action, int y, int x)
{
	static int	counter;
	char		*str;

	if (action == MLX_PRESS && (game.my_map->map2d[y][x] != '1'
		|| game.my_map->map2d[y][x] != 'E'))
	{
		ft_putnbr(++counter);
		write(1, "\n", 1);
		str = ft_itoa(counter);
		if (!str)
			return ;
		if (game.my_mlx->moves_counter)
			mlx_delete_image(game.my_mlx->mlx_ptr, game.my_mlx->moves_counter);
		game.my_mlx->moves_counter
			= mlx_put_string(game.my_mlx->mlx_ptr, str, 0, 0);
		mlx_resize_image(game.my_mlx->moves_counter, GRADE, GRADE);
		free(str);
	}
}

void	ft_key_press(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		y;
	int		x;

	game = param;
	y = game->my_map->player_pos.y;
	x = game->my_map->player_pos.x;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->my_mlx->mlx_ptr);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		if (check_next_step(game, y - 1, x))
			update_map(*game, y - 1, x, keydata.action);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		if (check_next_step(game, y + 1, x))
			update_map(*game, y + 1, x, keydata.action);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		if (check_next_step(game, y, x - 1))
			update_map(*game, y, x - 1, keydata.action);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		if (check_next_step(game, y, x + 1))
			update_map(*game, y, x + 1, keydata.action);
}

void	mlx_workspace(t_mlx *my_mlx, t_map *my_map)
{
	t_game	game;
	int		width;
	int		height;

	if (my_map->size_x > MAX_WIDTH || my_map->size_y > MAX_HEIGHT)
	{
		write(1, "size of map is large\n", 21);
		free_map(my_map);
		exit(1);
	}
	width = my_map->size_x * GRADE;
	height = my_map->size_y * GRADE;
	game.my_map = my_map;
	game.my_mlx = my_mlx;
	game.my_mlx->mlx_ptr = mlx_init(width, height, "so_long", false);
	if (!my_mlx->mlx_ptr)
		exit(1);
	init_imgs(my_mlx);
	render_map(game, my_mlx, my_map);
	mlx_key_hook(my_mlx->mlx_ptr, ft_key_press, &game);
	mlx_loop(my_mlx->mlx_ptr);
	free_game(my_mlx, my_map);
}
