/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:21:41 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/05 15:49:42 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	painted(char **matrix, int x, int y)
{
	if (x < 0 || y < 0 || matrix[y][x] == '1')
		return (0);
	if (matrix[y][x] == 'x')
		return (1);
	return (0);
}

int	thisistheway(char **matrix, t_point start)
{
	if (painted(matrix, start.x - 1, start.y) == 1)
		return (1);
	if (painted(matrix, start.x, start.y - 1) == 1)
		return (1);
	if (painted(matrix, start.x, start.y + 1) == 1)
		return (1);
	if (painted(matrix, start.x + 1, start.y) == 1)
		return (1);
	return (0);
}

void	paint(char **matrix, int x, int y)
{
	t_point	start;

	start.y = y;
	start.x = x;
	flood_fill(matrix, start);
}

void	flood_fill(char **matrix, t_point start)
{
	if (start.x < 0 || start.y < 0)
		return ;
	if (matrix[start.y][start.x] == '1' || matrix[start.y][start.x] == 'x')
		return ;
	if (matrix[start.y][start.x] == 'E')
		return ;
	matrix[start.y][start.x] = 'x';
	paint(matrix, start.x - 1, start.y);
	paint(matrix, start.x, start.y - 1);
	paint(matrix, start.x, start.y + 1);
	paint(matrix, start.x + 1, start.y);
}
