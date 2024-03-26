/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:22:09 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/23 18:57:48 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	ft_process_texture(t_data *data, char **param, char **texture)
{
	(void)data;
	if (param[2] != NULL && ft_empty_line(param[2]) == 0)
		exit_error("Wrong elements in the path o in the color\n");
	*texture = ft_param_path(param[1]);
}

void	ft_process_color(t_data *data, char **param, int *color)
{
	(void)data;
	*color = ft_check_color(param[1]);
	if (param[2] != NULL && ft_empty_line(param[2]) == 0)
		exit_error("Wrong elements in the path o in the color\n");
}

void	ft_check_texture_exists(char *texture)
{
	if (texture != NULL)
		exit_error("Element is repeated\n");
}

void	ft_check_color_exists(int color)
{
	if (color != 0)
		exit_error("Element is repeated\n");
}
