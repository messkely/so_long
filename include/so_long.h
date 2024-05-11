/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:37:32 by messkely          #+#    #+#             */
/*   Updated: 2024/05/11 15:45:51 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
# define MAX_WIDTH 1024
# define MAX_HEIGHT 1024
# define GRADE 50
typedef struct s_ply
{
	int	x;
	int	y;
}	t_ply;

typedef struct s_map
{
	char	*path;
	int		fd;
	char	**map2d;
	int 	C;
	int 	coin_counter;
	int		size_x;
	int		size_y;
	int		exit_flag;
	t_ply	player_pos;
}	t_map;

typedef struct s_mlx
{
	mlx_t			*mlx_ptr;
	int				window_width;
	int				window_height;
	mlx_image_t		*moves_counter;
	mlx_image_t		*image_player;
	mlx_texture_t	*bg_txt;
	mlx_texture_t	*wall_txt;
	mlx_texture_t	*coin_txt;
	mlx_texture_t	*player_txt;
	mlx_texture_t	*exit_txt;
	mlx_image_t		*img;
	mlx_image_t		*bg_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*coin_img;
	mlx_image_t		*player_img;
	mlx_image_t		*exit_img;
	mlx_texture_t	*texture_player;
	
}	t_mlx;

typedef struct s_game
{
	t_map *my_map;
	t_mlx *my_mlx;
}	t_game;

char	**ft_split(const char *s, char c, t_map *my_map);
int		ft_strlen(char *str);
char	*ft_read_file(char *map_path);
void	read_map(char *map_path, t_map *my_map);
void	check_file_is_valid(char *file);
int		ft_serch(char *str, char *to_find);
void	ft_error(void);
int		is_duplicated(char *str, t_map *map);
void	check_walls(char *map);
void	check_map_is_valid(char *map, t_map *my_map);
void	free_map(t_map *map);

void	mlx_workspace(t_mlx *my_mlx, t_map *my_map);
void	init_imgs(t_mlx *my_mlx);
void	resize_imgs(t_mlx *mlx);
void	exit_game(t_mlx *mlx);
void	init_txts(t_mlx *my_mlx);
void	init_left_txts(t_mlx *my_mlx);
void	reander_map(t_mlx *my_mlx, t_map *my_map);
void	free_game(t_mlx *mlx, t_map *map);
void	display_moves(t_mlx *mlx, t_map *map, action_t action, int y, int x);

char	*ft_itoa(int nbr);
void	ft_putnbr(int n);
void	flood_fill(t_map *my_map, int x, int y);

#endif