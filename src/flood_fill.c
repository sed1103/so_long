/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:56:19 by skirakos          #+#    #+#             */
/*   Updated: 2024/06/07 19:17:52 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"
#include "../Includes/get_next_line.h"

char	**copy_map(char **lines, int line_count)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	j = 0;
	copy = (char **)malloc(sizeof(char *) * (line_count + 1));
	while (lines[i])
	{
		copy[i] = ft_strdup(lines[i]);
		if (copy[i] == NULL)
		{
			free_all(copy);
			free_all(lines);
			exit(1 && write(2, "Memory error\n", 14));
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill_check(char **copy)
{
	int		i;
	int		j;
	int		p;
	int		e;
	int		c;

	i = -1;
	p = 0;
	e = 0;
	c = 0;
	while (copy[++i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'P')
				p++;
			if (copy[i][j] == 'E')
				e++;
			if (copy[i][j++] == 'C')
				c++;
		}
	}
	if (p != 0 || e != 0 || c != 0)
		exit(1 && write(2, "Path error.\n", 13));
}

void	flood_fill_recursive(char **map, int x, int y, int line_count)
{
	if (x < 0 || y < 0 || x >= line_count || y >= ft_strlen(map[0]))
		return ;
	if (map[x][y] == '1' || map[x][y] == 'w' || map[x][y] == 'M')
		return ;
	map[x][y] = 'w';
	flood_fill_recursive(map, x + 1, y, line_count);
	flood_fill_recursive(map, x - 1, y, line_count);
	flood_fill_recursive(map, x, y + 1, line_count);
	flood_fill_recursive(map, x, y - 1, line_count);
}

void	flood_fill(char **lines, int line_count)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	copy = copy_map(lines, line_count);
	while (lines[i])
	{
		j = 0;
		while (lines[i][j++])
		{
			if (lines[i][j] == 'P')
			{
				flood_fill_recursive(copy, i, j, line_count);
				break ;
			}
		}
		i++;
	}
	flood_fill_check(copy);
	free_all(copy);
}
