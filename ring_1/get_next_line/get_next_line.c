/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:58:24 by yoropeza          #+#    #+#             */
/*   Updated: 2022/10/26 17:26:14 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n' )
		i++;
	line = ft_substr(buffer, 0, i + 1);
	return (line);
}

static char	*ft_new_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n' )
		i++;
	line = ft_substr(buffer, i, ft_strlen(buffer));
	free (buffer);
	return (line);
}

static char	*ft_read(int fd, char *buffer)
{
	int		numbytes;
	char	*tab;

	tab = malloc((BUFFER_SIZE + 1) * sizeof(char));
	numbytes = 1;
	while (numbytes > 0 && !ft_strchr(buffer, '\n'))
	{
		numbytes = read(fd, tab, BUFFER_SIZE);
		if (numbytes == -1)
		{
			free (tab);
			return (NULL);
		}
		tab[numbytes] = '\0';
		buffer = ft_strjoin(tab, buffer);
		if (buffer[0] == 0)
		{
			free (tab);
			free (buffer);
			return (NULL);
		}	
	}
	free (tab);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || fd > 4096 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_new_line(buffer);
	return (line);
}
