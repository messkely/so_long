/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:37:32 by messkely          #+#    #+#             */
/*   Updated: 2024/05/26 15:29:54 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42.h"
# define MAX_WIDTH 52
# define MAX_HEIGHT 28
# define GRADE 50

typedef struct s_ply
{
	int	x;
	int	y;
}	t_ply;

typedef struct s_map
{
	char	**map2d;
	int		c;
	int		coin_counter;
	int		size_x;
	int		size_y;
	bool	exit;
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
	mlx_image_t		*bg_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*coin_img;
	mlx_image_t		*player_img;
	mlx_image_t		*exit_img;
}	t_mlx;

typedef struct s_game
{
	t_map	*my_map;
	t_mlx	*my_mlx;
}	t_game;

char	**ft_split(const char *s, char c, t_map *my_map);
int		ft_strlen(char *str);
void	read_map(char *map_path, t_map *my_map);
void	ft_error(void);
void	check_map_is_valid(char *map, t_map *my_map);
void	free_map(t_map *map);

void	mlx_workspace(t_mlx *my_mlx, t_map *my_map);
void	render_image(t_game game, void *img, int x, int y);
void	init_imgs(t_mlx *my_mlx);
void	exit_game(t_mlx *mlx);
void	render_map(t_game game, t_mlx *my_mlx, t_map *my_map);
void	free_game(t_mlx *mlx, t_map *map);
void	display_moves(t_game game, action_t action, int y, int x);
void	update_map(t_game game, int new_y, int new_x, action_t action);
int		check_next_step(t_game *game, int y, int x);

char	*ft_itoa(int nbr);
void	ft_putnbr(int n);
void	flood_fill_coin(t_map *my_map, int x, int y);
void	flood_fill_exit(t_map *my_map, int x, int y);

#endif