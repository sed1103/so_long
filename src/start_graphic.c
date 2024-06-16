/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:55:42 by skirakos          #+#    #+#             */
/*   Updated: 2024/06/07 19:21:54 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	count_coins(char **ready_map, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (ready_map[i])
	{
		j = 0;
		while (ready_map[i][j])
		{
			if (ready_map[i][j] == 'C')
			{
				map->coins++;
			}
			j++;
		}
		i++;
	}
}

void	start_graphic(char **ready_map, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	map->map = ready_map;
	count_coins(ready_map, map);
	while (ready_map[i])
	{
		j = 0;
		while (ready_map[i][j])
		{
			if (ready_map[i][j] == 'P')
			{
				map->y = i;
				map->x = j;
				break ;
			}
			j++;
		}
		i++;
	}
}
