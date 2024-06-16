/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:04:24 by skirakos          #+#    #+#             */
/*   Updated: 2024/06/07 20:33:48 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	move_up(t_map *map)
{
	if (map->map[map->y - 1][map->x] != '1')
	{
		if (map->map[map->y - 1][map->x] == 'M' )
			destroy_img(map, "Loser!\n", 7);
		else if (map->map[map->y - 1][map->x] == 'C')
		{
			map->map[map->y - 1][map->x] = '0';
			map->coins--;
		}
		else if (map->map[map->y - 1][map->x] == 'E' && map->coins == 0)
			destroy_img(map, "You won!\n", 9);
		map->y -= 1;
		map->steps++;
	}
}

void	move_down(t_map *map)
{
	if (map->map[map->y + 1][map->x] != '1')
	{
		if (map->map[map->y + 1][map->x] == 'M' )
			destroy_img(map, "Loser!\n", 7);
		else if (map->map[map->y + 1][map->x] == 'C')
		{
			map->map[map->y + 1][map->x] = '0';
			map->coins--;
		}
		else if (map->map[map->y + 1][map->x] == 'E' && map->coins == 0)
			destroy_img(map, "You won!\n", 9);
		map->y += 1;
		map->steps++;
	}
}

void	move_right(t_map *map)
{
	if (map->map[map->y][map->x + 1] != '1')
	{
		if (map->map[map->y][map->x + 1] == 'M' )
			destroy_img(map, "Loser!\n", 7);
		else if (map->map[map->y][map->x + 1] == 'C')
		{
			map->map[map->y][map->x + 1] = '0';
			map->coins--;
		}
		else if (map->map[map->y][map->x + 1] == 'E' && map->coins == 0)
			destroy_img(map, "You won!\n", 9);
		map->x += 1;
		map->steps++;
		map->mlx.packman = map->mlx.player;
	}
}

void	move_left(t_map *map)
{
	if (map->map[map->y][map->x - 1] != '1')
	{
		if (map->map[map->y][map->x - 1] == 'M' )
			destroy_img(map, "Loser!\n", 7);
		else if (map->map[map->y][map->x - 1] == 'C')
		{
			map->map[map->y][map->x - 1] = '0';
			map->coins--;
		}
		else if (map->map[map->y][map->x - 1] == 'E' && map->coins == 0)
			destroy_img(map, "You won!\n", 9);
		map->x -= 1;
		map->steps++;
		map->mlx.packman = map->mlx.rplayer;
	}
}

int	move(int key, t_map *map)
{
	if (key == 53)
		destroy_img(map, "Closed.\n", 8);
	else if (key == 13)
		move_up(map);
	else if (key == 0)
		move_left(map);
	else if (key == 1)
		move_down(map);
	else if (key == 2)
		move_right(map);
	return (0);
}
