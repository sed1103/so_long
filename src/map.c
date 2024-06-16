/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:12:00 by skirakos          #+#    #+#             */
/*   Updated: 2024/06/07 20:12:01 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	map_print2(t_map *map, void *animation, int i, int j)
{
	if ((map->map)[i][j] == '1')
		mlx_put_image_to_window(map->mlx.ptr,
			map->mlx.wind, map->mlx.wall, j * SIZE, i * SIZE);
	if ((map->map)[i][j] == 'E')
		mlx_put_image_to_window(map->mlx.ptr,
			map->mlx.wind, map->mlx.exit, j * SIZE, i * SIZE);
	if ((map->map)[i][j] == 'C')
		mlx_put_image_to_window(map->mlx.ptr,
			map->mlx.wind, map->mlx.feed, j * SIZE, i * SIZE);
	if ((map->map)[i][j] == 'M')
		mlx_put_image_to_window(map->mlx.ptr,
			map->mlx.wind, animation, j * SIZE, i * SIZE);
}

void	map_print(t_map *map, void *animation)
{
	int		i;
	int		j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			mlx_put_image_to_window(map->mlx.ptr,
				map->mlx.wind, map->mlx.field, j * SIZE, i * SIZE);
			mlx_put_image_to_window(map->mlx.ptr,
				map->mlx.wind, map->mlx.packman, map->x * SIZE, map->y * SIZE);
			map_print2(map, animation, i, j);
			j++;
		}
		i++;
	}
}

int	map_filling(t_map *map)
{
	void	*anim;
	char	*itoa;

	itoa = ft_itoa(map->steps);
	anim = animation(map);
	mlx_clear_window(map->mlx.ptr, map->mlx.wind);
	map_print(map, anim);
	mlx_string_put(map->mlx.ptr, map->mlx.wind,
		(map->b - 1.70) * SIZE, 18, 0xffffff, itoa);
	free(itoa);
	return (0);
}
