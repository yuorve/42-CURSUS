/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:58:24 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/12 20:33:15 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	*ft_union(char *buffer, char *tab)
{
	char	*buffer_temp;

	buffer_temp = ft_strjoin(buffer, tab);
	free (buffer);
	buffer = buffer_temp;
	return (buffer);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
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
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	i++;
	while (buffer[i + len])
		len++;
	line = ft_substr(buffer, i, len + 1);
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
			free (buffer);
			return (NULL);
		}
		tab[numbytes] = '\0';
		buffer = ft_union(buffer, tab);
		if (buffer[0] == '\0')
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
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		buffer = ft_strdup("");
	buffer = ft_read(fd, buffer);
	if (!buffer)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_line(buffer);
	buffer = ft_new_line(buffer);
	return (line);
}
