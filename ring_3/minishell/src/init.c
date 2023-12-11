/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:59:00 by angalsty          #+#    #+#             */
/*   Updated: 2023/12/11 21:42:52 by angalsty         ###   ########.fr       */
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

// void    ft_init_cmd(t_data *data)
// {
//     //data->cmd->env_copy = NULL;
//     //data->cmd->command = NULL;
//     //data->cmd->args = NULL;
//     //data->cmd->var_name = NULL;
//     //data->cmd->var_value = NULL;
//     //data->cmd->cmd_splited = NULL;
//     //data->cmd->cmd_complete = NULL;
//     //data->cmd->path = NULL;
// }


int ft_count_nodes(t_env_node *head) 
{
    int count = 0;
    while (head != NULL) 
    {
        count++;
        head = head->next;
    }
    return (count);
}

t_env_node *ft_create_env_node(char *name, char *value, int equal) 
{
    t_env_node *new_node = (t_env_node *)malloc(sizeof(t_env_node));
    if (new_node) 
    {
        new_node->name = ft_strdup(name);
        new_node->value = ft_strdup(value);
        new_node->equal = equal;
        new_node->next = NULL;
    }
    return (new_node);
}

t_env_node	*ft_listlast(t_env_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void ft_push_env_node(t_env_node **head, char *name, char *value, int equal) 
{
    t_env_node *curr;

    t_env_node *new_node = ft_create_env_node(name, value, equal);
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
            return (head);
        }
        head = head->next;
    }
    return (0);
}

void ft_shell_level(t_env_node **head, int i) 
{
    t_env_node *shlvl_node;
    int current_shlvl;
    int equal;

    equal = 1;
    
    shlvl_node = ft_find_node(*head, "SHLVL");
    if (shlvl_node) 
    {
        current_shlvl = ft_atoi(shlvl_node->value);
        current_shlvl += i;
        free(shlvl_node->value);
        shlvl_node->value = ft_itoa(current_shlvl);
    } 
    else 
    {
        char *value = ft_itoa(i);
        ft_push_env_node(head, "SHLVL", value, equal);
        free(value);
    }
}


void ft_init_env(t_env_node **head, char **env) 
{
    int i;
    int equal;
    char *name;
    char *value;
    
    i = 0;
    
    while (env[i])
    {
        
        name = env[i];
        // if (ft_strchr(env[i], '=')) 
        // {
        //     equal = 1;
        // } 
        // else 
        // {
        //     equal = 0;
        // }
        value = ft_strchr(env[i], '=');
        if (value) 
        {
            equal = 1;
            *value = '\0'; // Separar el nombre del valor
            value++; // Apuntar al comienzo del valor
            ft_push_env_node(head, name, value, equal);
        } 
        else 
        {
            //data->env_list->equal = 0;
            equal = 0;
            ft_push_env_node(head, name, "", equal); // Variable sin valor
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
    //ft_init_cmd(data);
    ft_init_env(&data->env_list, env);
}