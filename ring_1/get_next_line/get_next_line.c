/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:58:24 by yoropeza          #+#    #+#             */
/*   Updated: 2022/10/17 10:24:27 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			numbytes;
	
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	numbytes = read_file(fd, buffer, BUFFER_SIZE);
	if (numbytes < 0)
		return (NULL);
	if (!ft_strchr(buffer, '\n'))
		line = join(line, buffer);
}
