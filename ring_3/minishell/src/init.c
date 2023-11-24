/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:59:00 by angalsty          #+#    #+#             */
/*   Updated: 2023/11/24 21:04:17 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    ft_init_command(t_data *data)
{
    data->input = NULL;
    data->command = NULL;
    data->parameter = NULL;
    data->npipes = 0;
}

void    ft_init_cmd(t_data *data)
{
    data->cmd->env_copy = NULL;
    data->cmd->var_name = NULL;
    data->cmd->var_value = NULL;
    data->cmd->cmd_splited = NULL;
    data->cmd->cmd_complete = NULL;
    //data->cmd->path = NULL;
}

void    ft_init_env(t_data *data, char **env)
{
    int i;

    i = 0;
    while (env[i])
        i++;
    data->cmd->env_copy = (char **)malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (env[i])
    {
        data->cmd->env_copy[i] = ft_strdup(env[i]);
        //printf("env_copy[%d]: %s\n", i, data->cmd->env_copy[i]);
        i++;
    }
    data->cmd->env_copy[i] = NULL;
}

void    ft_init(t_data *data, char **env)
{
    ft_init_command(data);
    data->cmd = (t_cmd *)malloc(sizeof(t_cmd));
    ft_init_cmd(data);
    ft_init_env(data, env);
}