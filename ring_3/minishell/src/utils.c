/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:11:27 by angalsty          #+#    #+#             */
/*   Updated: 2023/11/29 21:11:58 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int ft_strcmp(const char *str1, const char *str2) 
{
    while (*str1 == *str2) 
    {
        if (*str1 == '\0') 
        {
            return 0;  
            // Ambas cadenas son iguales
        }
        str1++;
        str2++;
    }
    // Las cadenas son diferentes, devuelve la diferencia entre los caracteres
    return (*str1 - *str2);
}