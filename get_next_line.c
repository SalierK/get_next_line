/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:25:28 by kkilitci          #+#    #+#             */
/*   Updated: 2023/07/28 13:58:03 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_liner(char	*str)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!str[i]) 
		return (NULL); 
	while (str[len] && str[len] != '\n')
		len++;
	line = (char *)ft_calloc(sizeof(char), len + 2); 
	if (!line)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_trim(char *str)
{
	char	*newstr;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = 0;
	while (str[i] && str[i] != '\n') 
		i++;
	if (!str[i++])
	{
		free(str); 
		return (NULL); 
	}
	while (str[i + len] != '\0') 
		len++;
	newstr = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!newstr)
		return (NULL);
	while (str[i] != '\0')
		newstr[j++] = str[i++];
	newstr[j] = '\0';
	free(str);
	return (newstr);
}

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		status;

	status = 1;
	buff = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (status && !(ft_search(buff, '\n')))
	{
		status = read(fd, buff, BUFFER_SIZE);
		if (status == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[status] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str) 
	{
		return (NULL); 
	}
	line = ft_liner(str);
	str = ft_trim(str);
	return (line);
}
