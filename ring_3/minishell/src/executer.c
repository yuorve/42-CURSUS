/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:01 by angalsty          #+#    #+#             */
/*   Updated: 2023/12/06 21:44:51 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// char *ft_get_path(char **cmd, t_data *data) 
// {
//     char **path;
//     char *found_path;
//     int i;

//     path = NULL;
//     found_path = NULL;
//     i = 0;
//     while (data->cmd->env_copy[i]) 
//     {
//         if (ft_strncmp(data->cmd->env_copy[i], "PATH=", 5) == 0) 
//         {
//             path = ft_split(data->cmd->env_copy[i] + 5, ':');
//             if (path) 
//             {
//                 int j = 0;
//                 while (path[j]) 
//                 {
//                     char *temp = ft_strjoin(path[j], "/");
//                     char *full_path = ft_strjoin(temp, cmd[0]);
//                     free(temp);

//                     if (access(full_path, F_OK) == 0) 
//                     {
//                         found_path = ft_strdup(full_path);
//                         free(full_path); // No necesitamos conservar la ruta completa si ya encontramos la ruta del comando
//                         ft_free_matrix(path); // Liberamos la matriz path después de usarla
//                         return found_path;
//                     }
//                     free(full_path);
//                     j++;
//                 }
//                 ft_free_matrix(path); // Liberamos la matriz path si no se encontró la ruta
//             } 
//             else 
//             {
//                 printf("Error: path not found\n");
//             }
//             return NULL;
//         }
//         i++;
//     }
//     return NULL;
// }


char *join_path(char *path, char *cmd) 
{
    char *temp;
    char *full_path;
    
    temp = ft_strjoin(path, "/");
    full_path = ft_strjoin(temp, cmd);
    free(temp);
    return (full_path);
}

// char *check_path(char **path, char *cmd) 
// {
//     int i;
//     char *full_path;

//     i = 0;
//     while (path[i]) 
//     {
//         full_path = join_path(path[i], cmd);
//         if (access(full_path, F_OK) == 0) 
//         {
//             ft_free_matrix(path);
//             return (full_path);
//         }
//         free(full_path);
//         i++;
//     }
//     ft_free_matrix(path);
//     return (0);
// }

// char *find_command_path(char **env_copy, char *cmd) 
// {
//     char **path;
//     char *found_path;
//     int i;

//     i = 0;
//     while (env_copy[i]) 
//     {
//         if (ft_strncmp(env_copy[i], "PATH=", 5) == 0) 
//         {
//             path = ft_split(env_copy[i] + 5, ':');
//             if (!path) 
//             {
//                 printf("Error: path not found\n");
//                 return (0);
//             }
//             found_path = check_path(path, cmd);
//             if (found_path != NULL) 
//             {
//                 return (found_path);
//             }
//             return (0);
//         }
//         i++;
//     }
//     return (0);
// }

char *check_path(char **path, char *cmd) {
    int i = 0;
    char *found_path = NULL;

    while (path[i]) {
        char *full_path = join_path(path[i], cmd);
        if (access(full_path, F_OK) == 0) {
            found_path = ft_strdup(full_path);
            free(full_path);
            return found_path;
        }
        free(full_path);
        i++;
    }
    return found_path;
}

char *find_command_path(char **env_copy, char *cmd) {
    char **path;
    char *found_path = NULL;
    int i = 0;

    while (env_copy[i]) {
        if (ft_strncmp(env_copy[i], "PATH=", 5) == 0) {
            path = ft_split(env_copy[i] + 5, ':');
            if (!path) {
                printf("Error: path not found\n");
                return NULL;
            }
            found_path = check_path(path, cmd);
            if (found_path != NULL) {
                ft_free_matrix(path);
                return found_path;
            }
            ft_free_matrix(path);
        }
        i++;
    }
    return found_path;
}

char *ft_get_path(char **cmd, t_data *data) 
{
    return (find_command_path(data->cmd->env_copy, cmd[0]));
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

