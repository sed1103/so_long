/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:13:03 by skirakos          #+#    #+#             */
/*   Updated: 2024/06/07 19:20:04 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

char	*ft_result(int i, int end, long long int k, char *str)
{
	while (i >= end)
	{
		str[i--] = (k % 10) + '0';
		k /= 10;
	}
	return (str);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*temp;

	temp = b;
	while (len != 0)
	{
		*temp = (unsigned char)c;
		temp++;
		len--;
	}
	return (b);
}

char	*ft_newstr(size_t size)
{
	char	*str;

	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	else
	{
		ft_memset(str, '\0', (size + 1));
		return (str);
	}
}

long long int	ft_nlen(long long int n)
{
	int		len;

	len = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				end;
	long long int	k;

	k = n;
	if (n >= 0)
	{
		str = ft_newstr(ft_nlen(k));
		if (!str)
			return (NULL);
		i = ft_nlen(k) - 1;
		end = 0;
	}
	else
	{
		str = ft_newstr(ft_nlen(k) + 1);
		if (!str)
			return (NULL);
		str[0] = '-';
		i = ft_nlen(k);
		end = 1;
	}
	return (ft_result(i, end, k, str));
}
