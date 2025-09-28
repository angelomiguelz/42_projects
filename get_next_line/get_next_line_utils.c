/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:48:53 by mzarichn          #+#    #+#             */
/*   Updated: 2022/12/08 12:01:17 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!string)
		return (NULL);
	while (s1 && s1[i])
		string[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		string[j++] = s2[i];
		if (s2[i++] == '\n')
			break ;
	}
	string[j] = 0;
	free(s1);
	return (string);
}

int	ft_clean(char *s)
{
	int	bool;
	int	i;
	int	j;

	i = 0;
	j = 0;
	bool = 0;
	while (s[i])
	{
		if (bool)
			s[j++] = s[i];
		if (s[i] == '\n')
			bool = 1;
		s[i] = 0;
		i++;
	}
	return (bool);
}
