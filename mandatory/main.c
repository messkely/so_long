/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:32:45 by messkely          #+#    #+#             */
/*   Updated: 2024/04/18 08:32:48 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	check_file_is_valid(char *file)
{
	while (*file)
	{
		if (*file == '.')
			if (check(file, ".ber"))
				return ;
		file++;
	}
	printf("ERROR: file is not valid\n");
	exit(1);
}

int main(int ac, char **av)
{
	check_file_is_valid(av[1]);
}