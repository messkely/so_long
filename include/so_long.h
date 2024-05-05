/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:37:32 by messkely          #+#    #+#             */
/*   Updated: 2024/04/29 17:49:35 by messkely         ###   ########.fr       */
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

typedef struct s_map
{
	char	*path;
	int		fd;
	char	**map2d;
	int		x;
	int		y;
}	t_map;

char	**ft_split(const char *s, char c);
int		ft_strlen(char *str);
char	*ft_read_map(char *map_path);
int		num_words(const char *s, char c);
void	check_file_is_valid(char *file);
int		ft_serch(char *str, char *to_find);
void	ft_error(void);
int		is_duplicated(char *str);
void	check_walls(char *map);
void	check_map_is_valid(char *map);

#endif