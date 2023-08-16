/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:25:08 by kkilitci          #+#    #+#             */
/*   Updated: 2023/07/28 14:09:15 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_liner(char	*str);
char	*ft_trim(char *str);
char	*ft_read(int fd, char *str);
char	*ft_strjoin(char *str, char *buff);
int		ft_search(char *buff, int c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *s);

#endif