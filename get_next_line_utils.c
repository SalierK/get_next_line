/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:25:50 by kkilitci          #+#    #+#             */
/*   Updated: 2023/07/28 13:58:05 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	i;

	i = 0;
	memory = malloc(count * size);
	if (memory == NULL)
		return (0);
	while (i < count * size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buff)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	i = -1;
	j = -1;
	len = ft_strlen(str) + ft_strlen(buff);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	while (str[++i])
		new[i] = str[i];
	while (buff[++j])
		new[i + j] = buff[j];
	new[i + j] = '\0';
	free(str);
	return (new);
}

int	ft_search(char *buff, int c)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == c)
			return (1);
		i++;
	}
	return (0);
}
