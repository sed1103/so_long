/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:19:33 by skirakos          #+#    #+#             */
/*   Updated: 2024/05/22 16:36:44 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/get_next_line.h"

int	find_new_line(char *buff)
{
	int		i;

	i = 0;
	if (!buff)
		return (-1);
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_check(char **buff, char **send, int fd)
{
	if ((ft_strlen(*buff) == 0 && ft_strlen(*send) == 0) && (fd >= 0))
	{
		free(*send);
		send = NULL;
		return (NULL);
	}
	if (send && !send[0])
	{
		free(*send);
		return (NULL);
	}
	return (*send);
}

void	fill_buff(char **buff, int fd)
{
	char	*temp;
	char	*tmp1;
	int		sz;

	sz = 1;
	temp = ft_strnew(BUFFER_SIZE + 1);
	while (find_new_line(*buff) == -1 && sz != 0)
	{
		sz = read(fd, temp, BUFFER_SIZE);
		if (sz < 0)
		{
			free(*buff);
			free(temp);
			temp = NULL;
			*buff = NULL;
			return ;
		}
		temp[sz] = '\0';
		tmp1 = *buff;
		*buff = ft_strjoin(*buff, temp);
		free(tmp1);
	}
	free(temp);
	temp = NULL;
}

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*send;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fill_buff(&buff, fd);
	if (find_new_line(buff) != -1)
	{
		send = ft_substr(buff, 0, find_new_line(buff) + 1, 0);
		buff = ft_substr(buff, find_new_line(buff) + 1,
				ft_strlen(buff) - find_new_line(buff), 1);
	}
	else
	{
		send = ft_substr(buff, 0, ft_strlen(buff), 0);
		free(buff);
		buff = NULL;
	}
	return (ft_check(&buff, &send, fd));
}
