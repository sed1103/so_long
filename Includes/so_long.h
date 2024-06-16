/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:15:57 by skirakos          #+#    #+#             */
/*   Updated: 2024/06/07 20:26:46 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../minilibx/mlx.h"

# define SIZE 60

typedef struct s_img
{
	int		width;
	int		height;
	void	*ptr;
	void	*wind;
	void	*packman;
	void	*player;
	void	*rplayer;
	void	*enemy;
	void	*renemy;
	void	*feed;
	void	*wall;
	void	*field;
	void	*exit;
}	t_img;

typedef struct s_map
{
	t_img	mlx;
	char	**map;
	int		coins;
	int		steps;
	int		a;
	int		b;
	int		x;
	int		y;
}	t_map;

char	**ft_split(char *str);
char	*ft_itoa(int n);
char	*ft_strdup(char *s1);
void	*free_all(char **out);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strtrim2(char *s1, char *set);
void	flood_fill(char **lines, int line_count);
void	start_graphic(char **ready_map, t_map *map);
void	start_game(t_map map);
void	get_images(t_map *map);
void	check_chars(char **lines);
void	check_blank(char *str);
void	check_newline_again(char **str);
int		check_first_last(char **trimed_lines, int len_arr);
void	check_count(char **lines);
int		move(int key, t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);
void	move_right(t_map *map);
void	move_left(t_map *map);
void	destroy_img(t_map *map, char *message, int len);
int		map_filling(t_map *map);
void	map_print(t_map *map, void *animation);
void	map_print2(t_map *map, void *animation, int i, int j);
void	*animation(t_map *map);
int		destroy(t_map *map);

#endif