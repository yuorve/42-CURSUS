/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:01 by angalsty          #+#    #+#             */
/*   Updated: 2023/12/05 12:57:35 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// char *ft_get_path(char **cmd, t_data *data) 
// {
//     char **path;
//     char *found_path;
//     char *tmp;
//     int i;
    
//     i = 0;
//     path = NULL;
//     while (data->cmd->env_copy[i]) 
//     {
//         if (ft_strncmp(data->cmd->env_copy[i], "PATH=", 5) == 0) 
//         {
//             path = ft_split(data->cmd->env_copy[i], ':');
//             if (path) 
//             {
//                 int j = 0;
//                 while (path[j]) 
//                 {
//                     path[j] = ft_strjoin(path[j], "/");
//                     tmp = path[j];
//                     path[j] = ft_strjoin(tmp, cmd[0]);
//                     free(tmp);
//                     if (access(path[j], F_OK) == 0) 
//                     {
//                         found_path = ft_strdup(path[j]);
//                         ft_free_matrix(path); // Free path after usage
//                         return (found_path);
//                     }
//                     j++;
//                 }
//             }
//             else 
//             {
//                 printf("Error: path not found\n");
//             }
//             ft_free_matrix(path); // Free path after usage
//             return (0);
//         }
//         i++;
//     }
//     if (path)
//         ft_free_matrix(path); // Free path after usage
//     return (0);
// }

char *ft_get_path(char **cmd, t_data *data) {
    char **path = NULL;
    char *found_path = NULL;

    int i = 0;
    while (data->cmd->env_copy[i]) {
        if (ft_strncmp(data->cmd->env_copy[i], "PATH=", 5) == 0) {
            path = ft_split(data->cmd->env_copy[i] + 5, ':');
            if (path) {
                int j = 0;
                while (path[j]) {
                    char *temp = ft_strjoin(path[j], "/");
                    char *full_path = ft_strjoin(temp, cmd[0]);
                    free(temp);

                    if (access(full_path, F_OK) == 0) {
                        found_path = ft_strdup(full_path);
                        free(full_path); // No necesitamos conservar la ruta completa si ya encontramos la ruta del comando
                        ft_free_matrix(path); // Liberamos la matriz path después de usarla
                        return found_path;
                    }
                    free(full_path);
                    j++;
                }
                ft_free_matrix(path); // Liberamos la matriz path si no se encontró la ruta
            } else {
                printf("Error: path not found\n");
            }
            return NULL;
        }
        i++;
    }
    return NULL;
}

void    ft_execute(t_data *data)
{
    int pid;
    int status;
    data->cmd->cmd_splited = ft_command(data->command->content);

    data->cmd->path = ft_get_path(data->cmd->cmd_splited, data);
    printf("path: %s\n", data->cmd->path);
    
    if (data->cmd->path == NULL)
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
        execve(data->cmd->path, data->cmd->cmd_splited, data->cmd->env_copy);
    }
    else
    {
        waitpid(-1, &status, 0);
    }
    ft_free_matrix(data->cmd->cmd_splited);
    free(data->cmd->path);
}

