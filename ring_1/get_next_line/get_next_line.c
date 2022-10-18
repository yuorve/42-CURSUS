/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:58:24 by yoropeza          #+#    #+#             */
/*   Updated: 2022/10/17 18:36:37 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (!tab)
		return (NULL);
	numbytes = 1;
	while (numbytes > 0 && !ft_strchr(buffer, '\n'))
	{
		numbytes = read(fd, buffer, BUFFER_SIZE);
		if (numbytes < 0)
		{
			free (tab);
			return (NULL);
		}
		tab[numbytes] = '\0';
		buffer = ft_strjoin(buffer, tab);
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
	int			numbytes;
	int			i;
	
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
