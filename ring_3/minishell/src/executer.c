/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:01 by angalsty          #+#    #+#             */
/*   Updated: 2023/12/12 18:26:33 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


char *join_path(char *path, char *cmd) 
{
    char *temp;
    char *full_path;
    
    temp = ft_strjoin(path, "/");
    full_path = ft_strjoin(temp, cmd);
    free(temp);
    return (full_path);
}


char *check_path(char **path, char *cmd) 
{
    int i;
    char *found_path;
    char *full_path;

    i = 0;
    found_path = NULL;
    while (path[i]) 
    {
        full_path = join_path(path[i], cmd);
        if (access(full_path, F_OK) == 0) 
        {
            found_path = ft_strdup(full_path);
            free(full_path);
            return (found_path);
        }
        free(full_path);
        i++;
    }
    return (found_path);
}

char *find_command_path(char **env_copy, char *cmd) 
{
    char **path;
    char *found_path;
    int i;
    
    found_path = NULL;
    i = 0;
    while (env_copy[i]) 
    {
        if (ft_strncmp(env_copy[i], "PATH=", 5) == 0) 
        {
            path = ft_split(env_copy[i] + 5, ':');
            if (!path) 
            {
                printf("Error: path not found\n");
                return NULL;
            }
            found_path = check_path(path, cmd);
            if (found_path != NULL) 
            {
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


void    ft_execute_child(t_data *data, t_list *head, int prev_pipe) 
{
            // Hijo
            if (prev_pipe != -1) 
            {
                dup2(prev_pipe, STDIN_FILENO);
                close(prev_pipe);
            }

            if (head->next != NULL) 
            {
                dup2(data->cmd->pipefd[1], STDOUT_FILENO);
            }

            close(data->cmd->pipefd[0]);
            close(data->cmd->pipefd[1]);

            execve(data->cmd->path, data->cmd->cmd_splited, data->cmd->env_copy);
            perror("Exec error");
            exit(EXIT_FAILURE);
}

void    ft_execute_parent(int status, t_data *data, t_list *head, int prev_pipe, int pid) 
{
    // Padre
    if (prev_pipe != -1) 
    {
        close(prev_pipe);
    }

    if (head->next != NULL) 
    {
        close(data->cmd->pipefd[1]);
    }

    waitpid(pid, &status, 0);
    // if (WIFEXITED(status)) 
    // {
    //     if (WEXITSTATUS(status) == 0) 
    //     {
    //         printf("Command executed successfully\n");
    //     } 
    //     else 
    //     {
    //         printf("Command failed with code: %d\n", WEXITSTATUS(status));
    //     }
    // }
}

void    ft_redirections(t_data *data)
{
    int fd;
    int i;

    i = 0;
    while (data->cmd->cmd_splited[i])
    {
        if (ft_strcmp(data->cmd->cmd_splited[i], ">") == 0)
        {
            fd = open(data->cmd->cmd_splited[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            dup2(fd, STDOUT_FILENO);
            close(fd);
            data->cmd->cmd_splited[i] = NULL;
        }
        else if (ft_strcmp(data->cmd->cmd_splited[i], ">>") == 0)
        {
            fd = open(data->cmd->cmd_splited[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
            dup2(fd, STDOUT_FILENO);
            close(fd);
            data->cmd->cmd_splited[i] = NULL;
        }
        else if (ft_strcmp(data->cmd->cmd_splited[i], "<") == 0)
        {
            fd = open(data->cmd->cmd_splited[i + 1], O_RDONLY);
            dup2(fd, STDIN_FILENO);
            close(fd);
            data->cmd->cmd_splited[i] = NULL;
        }
        i++;
    }
}

// void    ft_redirections(t_data *data)
// {
//     t_list *prev;

//     prev = ft_previously(data->command, nodo);
//     if(data->p)
// }


void ft_execute_pipes(t_data *data, t_list *head) 
{
    int status = 0;
    //int pipefd[2];
    int prev_pipe;
    int pid;
    
    prev_pipe = -1;
    while (head) 
    {
        data->cmd->cmd_splited = ft_command(head->content);
        data->cmd->path = ft_get_path(data->cmd->cmd_splited, data);
        ft_redirections(data);
        if (data->cmd->path == NULL) 
        {
            printf("Error: command not found\n");
            return;
        }
        if (pipe(data->cmd->pipefd) == -1) 
        {
            perror("Pipe creation failed");
            return;
        }
        pid = fork();
        if (pid == -1) 
        {
            perror("Fork error");
            return;
        } 
        else if (pid == 0) 
            ft_execute_child(data, head, prev_pipe);
        else 
            ft_execute_parent(status, data, head, prev_pipe, pid);
    
    ft_free_matrix(data->cmd->cmd_splited);
    free(data->cmd->path);

    prev_pipe = data->cmd->pipefd[0];
    head = head->next;
    }
}

void ft_execute(t_data *data) 
{
    t_list *head = data->command;
    ft_execute_pipes(data, head);
}

