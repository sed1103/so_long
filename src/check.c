/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:15:20 by skirakos          #+#    #+#             */
/*   Updated: 2024/06/07 19:15:21 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"
#include "../Includes/get_next_line.h"

void	check_count(char **lines)
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
	while (lines[++i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'P')
				p++;
			if (lines[i][j] == 'E')
				e++;
			if (lines[i][j++] == 'C')
				c++;
		}
	}
	if (p != 1 || e != 1 || c <= 0)
		exit(1 && write(2, "Error check count\n", 19));
}

int	check_first_last(char **trimed_lines, int len_arr)
{
	int		len;
	int		i;

	len = ft_strlen(trimed_lines[0]);
	i = 0;
	while (trimed_lines[0][i])
	{
		if (trimed_lines[0][i] != '1')
		{
			write(2, "Error first last\n", 18);
			return (1);
		}
		i++;
	}
	i = 0;
	while (trimed_lines[len_arr - 1][i])
	{
		if (trimed_lines[len_arr - 1][i] != '1')
		{
			write(2, "Error first last\n", 18);
			return (1);
		}
		i++;
	}
	return (0);
}

void	check_newline_again(char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		tmp = str[i];
		str[i] = ft_strtrim2(str[i], " \t\v\f\r");
		free(tmp);
		i++;
	}
	str[i] = NULL;
}

void	check_blank(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			write(2, "Invalid map.\n", 14);
			exit(0);
		}
		i++;
	}
}

void	check_chars(char **lines)
{
	int		i;
	int		j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if ((lines[i][j] != '0' && lines[i][j] != 'M'
					&& lines[i][j] != '1' && lines[i][j] != 'P' &&
					lines[i][j] != 'C' &&
					lines[i][j] != 'E' && lines[i][j] != '\n'))
				exit(1 && write(2, "Error check chars\n", 19));
			j++;
		}
		i++;
	}
	check_count(lines);
}
