/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:58:32 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/19 10:59:58 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ft_isalpha(int c);
#include ft_isdigit(int c);

int	ft_isalnum(int c)
{
	return ((ft_isalpha(c) || ft_isdigit(c)) ? 1 : 0);
}
