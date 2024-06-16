/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:56:11 by skirakos          #+#    #+#             */
/*   Updated: 2024/06/07 19:03:55 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"
#include "../Includes/get_next_line.h"

char	**get_map(int fd)
{
	char	*line;
	char	*join;
	char	*temp;
	char	**splited;

	join = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		temp = join;
		join = ft_strjoin(join, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	temp = join;
	join = ft_strtrim(join, " \t\n\v\f\r");
	free(temp);
	check_blank(join);
	splited = ft_split(join);
	check_newline_again(splited);
	free(join);
	check_chars(splited);
	return (splited);
}

int	final_check(char **trimed_lines)
{
	int		len;
	int		i;

	len = ft_strlen(trimed_lines[0]);
	i = 1;
	while (trimed_lines[i])
	{
		if (len != ft_strlen(trimed_lines[i]))
		{
			write(2, "Error final check\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_sidewalls(char **trimed_lines)
{
	int		len;
	int		len_arr;
	int		i;

	len = ft_strlen(trimed_lines[0]);
	len_arr = 0;
	while (trimed_lines[len_arr])
		len_arr++;
	i = 0;
	while (trimed_lines[i])
	{
		if (trimed_lines[i][0] != trimed_lines[i][len - 1] ||
				trimed_lines[i][0] != '1')
		{
			write(2, "Error sidewalls\n", 17);
			return (1);
		}
		i++;
	}
	check_first_last(trimed_lines, len_arr);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		line_count;
	t_map	map;
	char	**res;

	if (argc != 2)
		exit(1 && write(2, "Error\n", 6));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1 && write(2, "FD Error\n", 9));
	res = get_map(fd);
	if (final_check(res) == 1 || check_sidewalls(res) == 1)
	{
		free_all(res);
		exit(1);
	}
	line_count = 0;
	while (res[line_count])
		line_count++;
	map.a = line_count;
	map.b = ft_strlen(res[0]);
	flood_fill(res, line_count);
	start_graphic(res, &map);
	start_game(map);
	return (0);
}
