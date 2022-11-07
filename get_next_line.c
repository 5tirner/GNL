/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:38:17 by zasabri           #+#    #+#             */
/*   Updated: 2022/11/08 00:16:55 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*buffer_to_stock(int fd, char *stock)
{
	char	*buff;
	int		i;

	buff = malloc((BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = 1;
	while (!ft_strchr(stock, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		stock = ft_strjoin(stock, buff);
	}
	free(buff);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = buffer_to_stock(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_pre_save(stock);
	stock = ft_sec_save(stock);
	return (line);
}
