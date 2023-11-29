/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:15:34 by angalsty          #+#    #+#             */
/*   Updated: 2023/11/27 18:15:44 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


void ft_free_matrix(char **array)
{
    int i;

    if (array)
    {
        i = 0;
        while (array[i] != NULL)
        {
            free(array[i]);
            i++;
        }
        free(array);
        array = NULL;
    }
}