/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:59:00 by angalsty          #+#    #+#             */
/*   Updated: 2023/11/30 18:47:11 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    ft_init_command(t_data *data)
{
    data->input = NULL;
    data->command = NULL;
    data->parameter = NULL;
    data->npipes = 0;
    data->env_list = NULL;
}

void    ft_init_cmd(t_data *data)
{
    //data->cmd->env_copy = NULL;
    data->cmd->var_name = NULL;
    data->cmd->var_value = NULL;
    //data->cmd->cmd_splited = NULL;
    //data->cmd->cmd_complete = NULL;
    //data->cmd->path = NULL;
}

// void    ft_shell_level(t_data *data)
// {
//     int i;
//     char *level;
//     char *new_level;

//     i = 0;
//     while (data->cmd->env_copy[i])
//     {
//         if (ft_strncmp(data->cmd->env_copy[i], "SHLVL=", 6) == 0)
//         {
//             level = ft_strdup(data->cmd->env_copy[i] + 6);
//             new_level = ft_itoa(ft_atoi(level) + 1);
//             free(data->cmd->env_copy[i]);
//             data->cmd->env_copy[i] = ft_strjoin("SHLVL=", new_level);
//             free(level);
//             free(new_level);
//             break;
//         }
//         i++;
//     }
// }

// void    ft_init_env(t_data *data, char **env)
// {
//     int i;

//     i = 0;
//     while (env[i])
//         i++;
//     data->cmd->env_copy = (char **)malloc(sizeof(char *) * (i + 1));
//     i = 0;
//     while (env[i])
//     {
//         data->cmd->env_copy[i] = ft_strdup(env[i]);
//         //printf("env_copy[%d]: %s\n", i, data->cmd->env_copy[i]);
//         i++;
//     }
//     data->cmd->env_copy[i] = NULL;
//     ft_shell_level(data);
// }

t_env_node *ft_create_env_node(char *name, char *value) 
{
    t_env_node *new_node = (t_env_node *)malloc(sizeof(t_env_node));
    if (new_node) 
    {
        new_node->name = ft_strdup(name);
        new_node->value = ft_strdup(value);
        new_node->next = NULL;
    }
    return new_node;
}

t_env_node	*ft_listlast(t_env_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void ft_push_env_node(t_env_node **head, char *name, char *value) 
{
    t_env_node *curr;

    t_env_node *new_node = ft_create_env_node(name, value);
    if (!*head)
    {
        *head = new_node;
    }
    else
    {
        curr = ft_listlast(*head);
        curr->next = new_node;
    }
}

t_env_node *ft_find_node(t_env_node *head, const char *name) 
{
    while (head != NULL) 
    {
        if (ft_strcmp(head->name, name) == 0) 
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void ft_shell_level(t_env_node **head, int i) 
{
    t_env_node *shlvl_node = ft_find_node(*head, "SHLVL");
    if (shlvl_node) 
    {
        int current_shlvl = atoi(shlvl_node->value);
        current_shlvl += i;
        free(shlvl_node->value);
        shlvl_node->value = ft_itoa(current_shlvl);
    } 
    else 
    {
        char *value = ft_itoa(i);
        ft_push_env_node(head, "SHLVL", value);
        free(value);
    }
}

void ft_init_env(t_env_node **head, char **env) 
{
    int i;
    
    i = 0;
    
    while (env[i])
    {
        char *name = env[i];
        char *value = ft_strchr(env[i], '=');
        if (value) 
        {
            *value = '\0'; // Separar el nombre del valor
            value++; // Apuntar al comienzo del valor
            ft_push_env_node(head, name, value);
        } 
        else 
        {
            //data->env_list->equal = 0;
            ft_push_env_node(head, name, ""); // Variable sin valor
        }
        // printf("Name: %s\n", (*head)->name);
        // printf("Value: %s\n", (*head)->value);
        i++;
    }
    ft_shell_level(head, 1); // Increment SHLVL by 1
}


void    ft_init(t_data *data, char **env)
{
    ft_init_command(data);
    data->cmd = (t_cmd *)malloc(sizeof(t_cmd));
    //ft_bzero(data->cmd, sizeof(t_cmd));
    ft_init_cmd(data);
    ft_init_env(&data->env_list, env);
}