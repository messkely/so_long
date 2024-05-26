/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:25:06 by messkely          #+#    #+#             */
/*   Updated: 2024/05/20 17:10:03 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_next_step(t_game *game, int y, int x)
{
	if (game->my_map->map2d[y][x] == '0')
		return (1);
	else if (game->my_map->map2d[y][x] == 'C')
	{
		game->my_map->coin_counter--;
		return (1);
	}
	else if (game->my_map->map2d[y][x] == 'E'
		&& game->my_map->coin_counter == 0)
		mlx_close_window(game->my_mlx->mlx_ptr);
	return (0);
}

void	update_map(t_game game, int new_y, int new_x, action_t action)
{
	int	y;
	int	x;

	y = game.my_map->player_pos.y;
	x = game.my_map->player_pos.x;
	game.my_map->map2d[y][x] = '0';
	render_image(game, game.my_mlx->bg_img, x, y);
	game.my_map->map2d[new_y][new_x] = 'P';
	game.my_map->player_pos.y = new_y;
	game.my_map->player_pos.x = new_x;
	render_image(game, game.my_mlx->player_img, new_x, new_y);
	display_moves(game, action, y, x);
}

void	render_image(t_game game, void *img, int x, int y)
{
	if (mlx_image_to_window(game.my_mlx->mlx_ptr,
			img, x * GRADE, y * GRADE) < 0)
		free_game(game.my_mlx, game.my_map);
}

void	render_map(t_game game, t_mlx *my_mlx, t_map *my_map)
{
	int	y;
	int	x;

	y = 0;
	while (my_map->map2d[y])
	{
		x = 0;
		while (my_map->map2d[y][x])
		{
			render_image(game, my_mlx->bg_img, x, y);
			if (my_map->map2d[y][x] == '1')
				render_image(game, my_mlx->wall_img, x, y);
			else if (my_map->map2d[y][x] == 'P')
				render_image(game, my_mlx->player_img, x, y);
			else if (my_map->map2d[y][x] == 'C')
				render_image(game, my_mlx->coin_img, x, y);
			else if (my_map->map2d[y][x] == 'E')
				render_image(game, my_mlx->exit_img, x, y);
			x++;
		}
		y++;
	}
}
