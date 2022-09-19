/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:58:32 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/19 10:59:58 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ft_islower(int c);
#include ft_isupper(int c);

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c)) ? 1 : 0;
}
