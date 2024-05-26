/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:21:52 by messkely          #+#    #+#             */
/*   Updated: 2024/05/26 15:50:52 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_check(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

int	num_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_check(s[i], c))
			i++;
		if (s[i])
			count++;
		while (s[i] && !ft_check(s[i], c))
			i++;
	}
	return (count);
}

static char	*ft_word(const char *s, char c, t_map *my_map)
{
	int		i;
	int		len_w;
	char	*ptr;

	len_w = 0;
	while (s[len_w] && !ft_check(s[len_w], c))
		len_w++;
	my_map->size_x = len_w;
	ptr = (char *)malloc((len_w + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len_w)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	**split_part(const char *s, char c, char **ptr, t_map *my_map)
{
	int	j;

	j = 0;
	while (*s)
	{
		while (*s != '\0' && ft_check(*s, c))
			s++;
		if (*s != '\0')
		{
			ptr[j] = ft_word(s, c, my_map);
			if (!ptr[j])
			{
				while (j > 0)
					free(ptr[--j]);
				free(ptr);
				return (0);
			}
			j++;
		}
		while (*s && !ft_check(*s, c))
			s++;
	}
	ptr[j] = NULL;
	return (ptr);
}

char	**ft_split(const char *s, char c, t_map *my_map)
{
	int		j;
	int		len;
	char	**ptr;

	if (!s)
		return (NULL);
	j = 0;
	len = num_words(s, c);
	my_map->size_y = len;
	ptr = (char **)malloc((len + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	return (split_part(s, c, ptr, my_map));
}
