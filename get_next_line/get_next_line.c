/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:48:50 by mzarichn          #+#    #+#             */
/*   Updated: 2022/12/08 12:08:48 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	cursor[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || FOPEN_MAX < fd)
		return (NULL);
	line = NULL;
	while (cursor[0] || read(fd, cursor, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, cursor);
		if (ft_clean(cursor) == 1)
			break ;
		if (read(fd, cursor, 0) < 0)
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
}

/* char	*get_next_line(int fd)
{
	 char	cursor[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || FOPEN_MAX < fd)
		return (NULL);
	line = NULL;
	while (cursor[0] || read(fd, cursor, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, cursor);
		if (ft_strlen(cursor) == 0)
			return (line);
		if (ft_clean(cursor) == 1)
			break ;
		if (read(fd, cursor, 0) < 0)
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
} */
