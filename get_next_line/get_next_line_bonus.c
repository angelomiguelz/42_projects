/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:39:19 by mzarichn          #+#    #+#             */
/*   Updated: 2022/12/08 12:09:56 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	cursor[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || FOPEN_MAX < fd)
		return (NULL);
	line = NULL;
	while (cursor[fd][0] || read(fd, cursor[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, cursor[fd]);
		if (ft_clean(cursor[fd]) == 1)
			break ;
		if (read(fd, cursor, 0) < 0)
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
}
