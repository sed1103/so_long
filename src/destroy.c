/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:50:41 by skirakos          #+#    #+#             */
/*   Updated: 2024/06/07 20:32:34 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	destroy_img(t_map *map, char *message, int len)
{
	mlx_destroy_image(map->mlx.ptr, map->mlx.player);
	mlx_destroy_image(map->mlx.ptr, map->mlx.rplayer);
	mlx_destroy_image(map->mlx.ptr, map->mlx.enemy);
	mlx_destroy_image(map->mlx.ptr, map->mlx.renemy);
	mlx_destroy_image(map->mlx.ptr, map->mlx.feed);
	mlx_destroy_image(map->mlx.ptr, map->mlx.wall);
	mlx_destroy_image(map->mlx.ptr, map->mlx.exit);
	write(1, message, len);
	free_all(map->map);
	exit(0);
}

int	destroy(t_map *map)
{
	destroy_img(map, "Closed.\n", 8);
	return (0);
}
