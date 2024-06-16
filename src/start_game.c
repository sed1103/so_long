/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:36:16 by skirakos          #+#    #+#             */
/*   Updated: 2024/06/07 20:26:22 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	get_images(t_map *map)
{
	map->mlx.width = SIZE;
	map->mlx.height = SIZE;
	map->mlx.player = mlx_xpm_file_to_image(map->mlx.ptr,
			"xpm/Open.xpm", &map->mlx.width, &map->mlx.height);
	map->mlx.packman = map->mlx.player;
	map->mlx.rplayer = mlx_xpm_file_to_image(map->mlx.ptr,
			"xpm/packman_left.xpm", &map->mlx.width, &map->mlx.height);
	map->mlx.enemy = mlx_xpm_file_to_image(map->mlx.ptr,
			"xpm/purple_monster.xpm", &map->mlx.width, &map->mlx.height);
	map->mlx.renemy = mlx_xpm_file_to_image(map->mlx.ptr,
			"xpm/purple_rev_monster.xpm", &map->mlx.width, &map->mlx.height);
	map->mlx.feed = mlx_xpm_file_to_image(map->mlx.ptr,
			"xpm/pill.xpm", &map->mlx.width, &map->mlx.height);
	map->mlx.field = mlx_xpm_file_to_image(map->mlx.ptr,
			"xpm/point.xpm", &map->mlx.width, &map->mlx.height);
	map->mlx.wall = mlx_xpm_file_to_image(map->mlx.ptr,
			"xpm/wall.xpm", &map->mlx.width, &map->mlx.height);
	map->mlx.exit = mlx_xpm_file_to_image(map->mlx.ptr,
			"xpm/exit.xpm", &map->mlx.width, &map->mlx.height);
}

void	*animation(t_map *map)
{
	static void	*monstrik;
	static int	count;

	if (count % 100 == 0)
	{
		monstrik = map->mlx.renemy;
	}
	else if (count % 50 == 0)
		monstrik = map->mlx.enemy;
	count++;
	return (monstrik);
}

void	start_game(t_map map)
{
	map.steps = 0;
	map.mlx.ptr = mlx_init();
	map.mlx.wind = mlx_new_window(map.mlx.ptr, map.b * 60,
			map.a * 60, "Pac-man Game");
	get_images(&map);
	mlx_hook(map.mlx.wind, 2, 0, &move, &map);
	mlx_hook(map.mlx.wind, 17, 0, &destroy, &map);
	mlx_loop_hook(map.mlx.ptr, &map_filling, &map);
	mlx_loop(map.mlx.ptr);
}
