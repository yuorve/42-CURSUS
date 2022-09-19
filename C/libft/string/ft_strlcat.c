/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:08:43 by yoropeza          #+#    #+#             */
/*   Updated: 2022/08/23 20:00:02 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *scr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_s;
	unsigned int	len_d;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	len_d = i;
	len_s = ft_strlen(scr);
	if (size == 0 || size <= i)
		return (len_s + size);
	while (scr[j] && j < size - len_d - 1)
	{
		dest[i] = scr[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len_d + len_s);
}
