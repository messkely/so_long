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

#define WIDTH 512
#define HEIGHT 512
// #define BLOCK ""
#define HEIGHT 512

# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_mlx
{
	int x;
	int y;
	mlx_t	*ptr;
} 		area;

char	**ft_split(const char *s, char c);
int ft_strlen(char *str);
char *ft_read_map(char *map_path);
int	num_words(const char *s, char c);
void check_file_is_valid(char *file);

#endif