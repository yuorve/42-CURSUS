/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:21:09 by yoropeza          #+#    #+#             */
/*   Updated: 2022/08/24 19:12:38 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *scr, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	while (scr[len] != '\0')
		len++;
	i = 0;
	while (scr[i] != '\0' && i < (size - 1))
	{
		dest[i] = scr[i];
		i++;
	}
	while (i < size)
	{
		dest[i] = '\0';
		++i;
	}
	return (len);
}
