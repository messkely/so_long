/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:05:11 by messkely          #+#    #+#             */
/*   Updated: 2024/05/11 12:29:07 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_strlen(char* str)
{
	if (!str || *str == '\0')
		return 0;
	return (1 + ft_strlen(str + 1));
}

char	*ft_itoa(int nbr)
{
	int n = nbr;
	int len = 0;
	if (nbr <= 0)
	{
		len++;
    	}
	while (n) 
	{
		n /= 10;
		len++;
	}
	char *result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return NULL;
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return(result);
	}
	while (nbr) 
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return result;
}

void	ft_putnbr(int n)
{
	if (n < 10)
		write(1, &"0123456789"[n], 1);
	else
	{
		ft_putnbr(n / 10);
		write(1, &"0123456789"[n % 10], 1);
	}
}

void free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size_y)
		free(map->map2d[i++]);
	free(map);
}
