/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:44:10 by messkely          #+#    #+#             */
/*   Updated: 2024/05/10 14:38:08 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_left_txts(t_mlx *my_mlx)
{
	if (!my_mlx->coin_txt)
	{
		mlx_delete_texture(my_mlx->bg_txt);
		mlx_delete_texture(my_mlx->wall_txt);
		mlx_delete_texture(my_mlx->player_txt);
		mlx_terminate(my_mlx->mlx_ptr);
		exit(1);
	}
	my_mlx->exit_txt = mlx_load_png("assets/exit.png");
	if (!my_mlx->exit_txt)
	{
		mlx_delete_texture(my_mlx->bg_txt);
		mlx_delete_texture(my_mlx->wall_txt);
		mlx_delete_texture(my_mlx->player_txt);
		mlx_delete_texture(my_mlx->coin_txt);
		mlx_terminate(my_mlx->mlx_ptr);
		exit(1);
	}
}

void	init_txts(t_mlx *my_mlx)
{
	my_mlx->bg_txt = mlx_load_png("assets/background.png");
	if (!my_mlx->bg_txt)
	{
		mlx_terminate(my_mlx->mlx_ptr);
		exit(1);
	}
	my_mlx->wall_txt = mlx_load_png("assets/wall.png");
	if (!my_mlx->wall_txt)
	{
		mlx_delete_texture(my_mlx->bg_txt);
		mlx_terminate(my_mlx->mlx_ptr);
		exit(1);
	}
	my_mlx->player_txt = mlx_load_png("assets/player.png");
	if (!my_mlx->player_txt)
	{
		mlx_delete_texture(my_mlx->bg_txt);
		mlx_delete_texture(my_mlx->wall_txt);
		mlx_terminate(my_mlx->mlx_ptr);
		exit(1);
	}
	my_mlx->coin_txt = mlx_load_png("assets/coin.png");
	init_left_txts(my_mlx);
}

void	exit_game(t_mlx *mlx)
{
	mlx_delete_image(mlx->mlx_ptr, mlx->bg_img);
	mlx_delete_image(mlx->mlx_ptr, mlx->wall_img);
	mlx_delete_image(mlx->mlx_ptr, mlx->player_img);
	mlx_delete_image(mlx->mlx_ptr, mlx->coin_img);
	mlx_delete_image(mlx->mlx_ptr, mlx->exit_img);
	if (mlx->moves_counter)
		mlx_delete_image(mlx->mlx_ptr, mlx->moves_counter);
	mlx_delete_texture(mlx->bg_txt);
	mlx_delete_texture(mlx->wall_txt);
	mlx_delete_texture(mlx->player_txt);
	mlx_delete_texture(mlx->coin_txt);
	mlx_delete_texture(mlx->exit_txt);
	mlx_terminate(mlx->mlx_ptr);
	// mlx_close_window(mlx->mlx_ptr);
}

void	resize_imgs(t_mlx *mlx)
{
	if (!mlx_resize_image(mlx->bg_img, GRADE, GRADE))
		exit_game(mlx);
	if (!mlx_resize_image(mlx->wall_img, GRADE, GRADE))
		exit_game(mlx);
	if (!mlx_resize_image(mlx->player_img, GRADE, GRADE))
		exit_game(mlx);
	if (!mlx_resize_image(mlx->coin_img, GRADE, GRADE))
		exit_game(mlx);
	if (!mlx_resize_image(mlx->exit_img, GRADE, GRADE))
		exit_game(mlx);
}

void	init_imgs(t_mlx *my_mlx)
{
	init_txts(my_mlx);
	my_mlx->bg_img = mlx_texture_to_image(my_mlx->mlx_ptr, my_mlx->bg_txt);
	my_mlx->wall_img = mlx_texture_to_image(my_mlx->mlx_ptr, my_mlx->wall_txt);
	my_mlx->player_img = mlx_texture_to_image(my_mlx->mlx_ptr, my_mlx->player_txt);
	my_mlx->coin_img = mlx_texture_to_image(my_mlx->mlx_ptr, my_mlx->coin_txt);
	my_mlx->exit_img = mlx_texture_to_image(my_mlx->mlx_ptr, my_mlx->exit_txt);
	my_mlx->moves_counter = 0;
	resize_imgs(my_mlx);
	
}
