/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:58:24 by yoropeza          #+#    #+#             */
/*   Updated: 2022/10/17 16:15:32 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			numbytes;
	
	if (fd < 0 || fd > 1024 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	numbytes = read(fd, buffer, BUFFER_SIZE);
	if (numbytes < 0)
		return (NULL);
	if (!ft_strchr(buffer, '\n'))
		line = ft_strjoin(line, buffer);
}
