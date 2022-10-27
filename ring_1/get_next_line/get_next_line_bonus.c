/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:58:24 by yoropeza          #+#    #+#             */
/*   Updated: 2022/10/27 16:31:43 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	int		len;

	i = 0;
	len = 0;
	while (buffer[i] && buffer[i] != '\n' )
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (0);
	}
	i++;
	while (buffer[i + len] && buffer[i + len] != '\n' )
		len++;
	line = ft_substr(buffer, i, len);
	free (buffer);
	return (line);
}

static char	*ft_read(int fd, char *buffer)
{
	int		numbytes;
	char	*tab;
	char	*buffer_temp;

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
		buffer_temp = ft_strjoin(buffer, tab);
		free (buffer);
		buffer = buffer_temp;
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
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || fd > 4096 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_new_line(buffer[fd]);
	return (line);
}
