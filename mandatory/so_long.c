/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:05:11 by messkely          #+#    #+#             */
/*   Updated: 2024/04/29 18:10:42 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static mlx_image_t *image_player = NULL;

void ft_error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
// ---------------------------------Background---------------------------------- //
void background(void *mlx)
{
	mlx_texture_t *background;
	mlx_image_t *image;

	image = NULL;
	background = mlx_load_png("assets/background.png");
	if (!background)
		ft_error();
	if (image)
		mlx_delete_image(mlx, image);
	image = mlx_texture_to_image(mlx, background);
	if (!image)
		ft_error();
	mlx_resize_image(image, 50, 50);
	if (mlx_image_to_window(mlx, image, 0, 0) < 0)
		ft_error();
}
// ---------------------------------Player---------------------------------- //
void player(void *mlx, mlx_texture_t *texture_player)
{
	texture_player = mlx_load_png("assets/skeleton.png");
	if (!texture_player)
		ft_error();
	if (image_player)
		mlx_delete_image(mlx, image_player);
	image_player = mlx_texture_to_image(mlx, texture_player);
	if (!image_player)
		ft_error();
	mlx_resize_image(image_player, 50, 50);
	if (mlx_image_to_window(mlx, image_player, 0, 0) < 0)
		ft_error();
}
// ---------------------------------Coin---------------------------------- //
void coin(void *mlx)
{
	mlx_texture_t *coin;
	static mlx_image_t *img;

	img = NULL;
	coin = mlx_load_png("assets/coin.png");
	if (!coin)
		ft_error();
	if (img)
		mlx_delete_image(mlx, img);
	img = mlx_texture_to_image(mlx, coin);
	if (!img)
		ft_error();
	mlx_resize_image(img, 50, 50);
	if (mlx_image_to_window(mlx, img, 100, 100) < 0)
		ft_error();
}
// ---------------------------------Movement---------------------------------- //
void ft_key_press(mlx_key_data_t keydata, void *param)
{
	mlx_t *mlx;
	area *

	mlx = (mlx_t *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		image_player->instances[0].y -= 50;
		printf("hhh\n");
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		image_player->instances[0].y += 50;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		image_player->instances[0].x -= 50;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		image_player->instances[0].x += 50;
	if (keydata.key == MLX_KEY_DELETE)
		mlx_delete_image(mlx, image_player);
}
// ---------------------------------Program---------------------------------- //

// int32_t main()
// {
// 	mlx_t *mlx;
// 	mlx_texture_t *texture_player;
// 		texture_player = NULL;
// 		mlx = mlx_init(5 * 50, 13 * 50, "MLX42", true);
// 		if (!mlx)
// 			ft_error();
// 		background(mlx);
// 		coin(mlx);
// 		mlx_key_hook(mlx, ft_key_press, mlx);
// 		player(mlx, texture_player);
// 		mlx_loop(mlx);
// 		mlx_delete_image(mlx, image_player);
// 		mlx_delete_texture(texture_player);
// 		mlx_terminate(mlx);
// 		return (EXIT_SUCCESS);
// }

int32_t main(int ac, char **av)
{
	if (ac == 2)
	{
		char *map;
		char **map_lines;
		int height_map;
		int width_map;
		int i = 0;
		mlx_t *mlx;
		mlx_texture_t *texture_player;

		check_file_is_valid(av[1]);
		map = ft_read_map(av[1]);
		map_lines = ft_split(map, '\n');
		width_map = ft_strlen(map_lines[0]);
		height_map = num_words(map, '\n');
		// ####################
		texture_player = NULL;
		mlx = mlx_init(width_map * 50, height_map * 50, "MLX42", true);
		if (!mlx)
			ft_error();
		// ####################
		while (map_lines[i])
		{
			int j = 0;
			while (map_lines[i][j])
			{
				if (map_lines[i][j] == '1')
				{
					background(mlx);
				}
				j++;
			}
			i++;
		}
		free(map);
		mlx_loop(mlx);
		mlx_delete_image(mlx, image_player);
		mlx_delete_texture(texture_player);
		mlx_terminate(mlx);
		return (EXIT_SUCCESS);
	}
	else
		write(1, "The program accept one param\n", 29);
	// atexit(system("leaks a.out"));
}
