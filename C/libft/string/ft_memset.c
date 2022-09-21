/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:21:01 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/21 17:26:13 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memset(void *b, int c, size_t len)
{
	unsigned char *str;
	
	str = (unsigned char*)b;
	while (len > 0)
	{
		*str = c;
		str++;
		len--;
	}
	return (b);
}
