/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:19 by skirakos          #+#    #+#             */
/*   Updated: 2024/06/07 20:15:03 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"
#include "../Includes/get_next_line.h"

int	ft_check2(unsigned char *set, char c)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	char			*str;
	int				i;
	unsigned int	start;
	unsigned int	end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_check2((unsigned char *)set, s1[start]))
		start++;
	while (s1[start] != '\n' && start != 0)
		start--;
	while (end > start && ft_check2((unsigned char *)set, s1[end - 1]))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim2(char *s1, char *set)
{
	char			*str;
	int				i;
	unsigned int	start;
	unsigned int	end;

	if (!s1 || !set)
		return (NULL);
	end = 0;
	start = ft_strlen(s1) - 1;
	while (start > 0 && s1[start] && ft_check2((unsigned char *)set, s1[start]))
		start--;
	if (start != 0)
		start++;
	str = (char *)malloc(sizeof(char) * (start - end + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (end < start)
		str[i++] = s1[end++];
	str[i] = '\0';
	return (str);
}
