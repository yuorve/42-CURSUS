/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:23:36 by yoropeza          #+#    #+#             */
/*   Updated: 2023/03/28 19:23:47 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void error_and_exit(char *message)
{
    ft_putendl_fd(message, 2);
    exit(EXIT_FAILURE);
}

int ft_abs(int x)
{
    return (x > 0 ? x : -x);
}

int get_color(t_point current, t_point start, t_point end, t_point delta)
{
    int		percent;
    int		color;

    if (current.color == end.color)
        return (current.color);
    if (delta.x > delta.y)
        percent = ft_abs((current.x - start.x) * 100 / delta.x);
    else
        percent = ft_abs((current.y - start.y) * 100 / delta.y);
    color = get_light(start.color, end.color, percent);
    return (color);
}

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage / 100) * start + percentage / 100 * end));
}
