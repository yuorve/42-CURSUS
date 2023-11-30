/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:01 by angalsty          #+#    #+#             */
/*   Updated: 2023/11/30 19:07:27 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// char    *ft_get_path(char **cmd, t_data *data)
// {
//     int i;
//     int j;
//     char **path;

//     i = 0;
//     while (data->cmd->env_copy[i])
//     {
//         // here I can use function getenv(constan name) eg getenv("PATH") and return a pointer to the value of the environment variable name        
//         if (ft_strncmp(data->cmd->env_copy[i], "PATH=", 5) == 0)
//         {
//             path = ft_split(data->cmd->env_copy[i], ':');
//             j = 0;
//             while (path[j])
//             {
//                 path[j] = ft_strjoin(path[j], "/");
//                 path[j] = ft_strjoin(path[j], cmd[0]);
//                 if (access(path[j], 0) == 0)
//                 {
//                     return (path[j]);
//                 }
//                 printf("path[%d]: %s\n", j, path[j]);
//                 j++;
//             }
//         }
//         i++;
//     }
//     ft_free_matrix(path);
//     return (NULL);
// }

char *ft_get_path(char *cmd, t_data *data) 
{
    char **path;
    char *found_path;
    char *tmp;
    int i;
    
    i = 0;
    path = NULL;
    while (data->cmd->env_copy[i]) 
    {
        if (ft_strncmp(data->cmd->env_copy[i], "PATH=", 5) == 0) 
        {
            path = ft_split(data->cmd->env_copy[i], ':');
            if (path) 
            {
                int j = 0;
                while (path[j]) 
                {
                    path[j] = ft_strjoin(path[j], "/");
                    tmp = path[j];
                    path[j] = ft_strjoin(path[j], cmd[0]);
                    free(tmp);
                    if (access(path[j], F_OK) == 0) 
                    {
                        found_path = ft_strdup(path[j]);
                        ft_free_matrix(path); // Free path after usage
                        return (found_path);
                    }
                    j++;
                }
            }
            else 
            {
                printf("Error: path not found\n");
            }
            ft_free_matrix(path); // Free path after usage
            return (0);
        }
        i++;
    }
    if (path)
        ft_free_matrix(path); // Free path after usage
    return (0);
}


// void    ft_devide_command(t_data *data)
// {
//     int i;
//     char **cmd_splited;

//     i = 0;
//     cmd_splited = ft_split(*data->cmd->cmd_complete, ' ');
   
//     while (cmd_splited[i])
//     {
//         //printf("cmd_splited[%d]: %s\n", i, cmd_splited[i]);
//         i++;
//     }
    
//     data->cmd->cmd_splited = (char **)calloc(sizeof(char **), i + 1);
//     i = 0;
//     while (cmd_splited[i])
//     {
//         data->cmd->cmd_splited[i] = cmd_splited[i];
//         i++;
//     }
//     data->cmd->cmd_splited[i] = NULL;
//     printf("data->cmd->cmd_splited[0]: %s\n", data->cmd->cmd_splited[0]);
    
//     // int j = 0;
//     // while(data->cmd->cmd_complete[j])
//     // {
//     //     printf("command->cmd[%d] = %s\n", j, data->cmd->cmd_splited[j]);
//     //     j++;
//     // }
//     //ft_free_matrix(cmd_splited);
//     // ft_free_matrix(data->cmd->cmd_complete);
// }

void    ft_execute(t_data *data)
{
    int pid;
    int status;
    char *path;

    //ft_devide_command(data);
    path = ft_get_path(ft_command(data->command), data);
    printf("path: %s\n", path);
    
    if (path == NULL)
    {
        printf("Error: command not found\n");
        return ;
    }
    pid = fork();
    if (pid == -1)
    {
        perror ("Error: ");
        return ;
    }
    else if ( pid == 0)
    {
        execve(path, data->cmd->cmd_splited, data->cmd->env_copy);
    }
    else
    {
        waitpid(-1, &status, 0);
    }
    ft_free_matrix(data->cmd->cmd_splited);
    free(path);
    
}

