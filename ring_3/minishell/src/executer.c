/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:01 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/09 21:29:23 by angalsty         ###   ########.fr       */
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
                return (found_path);
            }
            ft_free_matrix(path);
        }
        i++;
    }
    return found_path;
}

char *ft_get_path(char **cmd, t_data *data) 
{
    if (access(*cmd, 0) == 0)
			return (*cmd);
    else 
        return (find_command_path(data->cmd->env_copy, cmd[0]));
}

// char	*ft_cmd(t_data *data, char *cmd)
// {
// 	int		i;
// 	char	*str;
// 	char	**paths;

// 	if (access(cmd, 0) == 0)
// 			return (cmd);
// 	i = 0;
// 	while (data->env[i] && ft_strncmp(data->env[i], "PATH=", 5) != 0)
// 		i++;
// 	paths = ft_split(ft_substr(data->env[i], 5, ft_strlen(data->env[i])), ':');
// 	i = 0;
// 	cmd = ft_strjoin("/", cmd);
// 	while (paths[i])
// 	{
// 		str = ft_strjoin(paths[i], cmd);
// 		if (access(str, 0) == 0)
// 			return (str);
// 		free(str);
// 		i++;
// 	}
// 	perror("minishell");
// 	exit(EXIT_FAILURE);
// }


void    ft_execute_child(t_data *data, t_list *head, int prev_pipe) 
{
    // Hijo
    // if (ft_redirections_pars(data) == 1)
    signal(SIGUSR2, handle_process_on);
    ft_redirections(data);
   
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

    // if (head->next == NULL) 
    // {
    //     close(data->cmd->pipefd[0]);
    // }
    
    // if (ft_is_redirected_builtins(data) == 1)
    // {
    //     printf("Is redirected builtins\n");
    //     ft_execute_rebuiltins(data);
    // }
    if (data->cmd->path != NULL)
            execve(data->cmd->path, data->cmd->cmd_splited, data->cmd->env_copy);
    //}

    // else
    // {
    //     printf("Error: command not found\n");
    //     exit(EXIT_FAILURE);
    // }
}

void    ft_execute_parent(int status, t_data *data, t_list *head, int prev_pipe, int pid) 
{
    // Padre
    signal(SIGUSR2, SIG_IGN); //signal to ignore
    rl_set_prompt("");
    
    if (prev_pipe != -1) 
    {
        close(prev_pipe);
    }
    if (head->next != NULL) 
    {
        close(data->cmd->pipefd[1]);
    } 
    if (head->next == NULL) 
    {
        close(data->cmd->pipefd[0]);
    }

    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
    {
        data->cmd->exit_status = WEXITSTATUS(status);
    }
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


// int	ft_redirections_pars(t_data *data)
// {
// 	// char	*cmd;
// 	// char	*end;

// 	// cmd = data->command->content;
// 	// end = ft_substr(cmd, 2, ft_strlen(cmd) - 2);
//     ft_printf("redirec:%c\n", data->redirection);
// 	if (data->nredirection == 1 && data->redirection == '<')
// 		{
//             data->cmd->infiles = 1;            
//             data->file = ft_substr(data->command->content, ft_findpos(data->command->content, '<') + 2, ft_strlen(data->command->content));            
//             return (1);
//         }
// 	else if (data->nredirection == 2 && data->redirection == '<')
// 		{
//             //ft_heredoc(data, end);
//             data->cmd->heredoc = 1;
//             printf("heredoc\n");
//             return (1);
//         }
// 	else if (data->nredirection == 1 && data->redirection == '>')
// 		{
//             //ft_output(data);
//             //data->cmd->outfiles = 1;
//             printf("output\n");
//             return (1);
//         }
//     else if (data->nredirection == 2 && data->redirection == '>')
//     {
//         data->cmd->append = 1;
//         printf("append\n");
//         return (1);
//     }
// 	// else
// 	// 	ft_execute(data);
// 	// free (end);
//     return(0);
// }




void    ft_heredoc(t_data *data)
{
    char    *line;
    int fd_infile;
    
    fd_infile = open(".heredoc.txt", O_CREAT | O_RDWR | O_TRUNC, 0664);
    if (fd_infile == -1)
        ft_exit_error();
    while (1)
    {
        line = readline("\033[33;1m> \033[0m");
        if (ft_strcmp(line, data->command->content) == 0)
        {
            free(line);
            break;
        }
        ft_putstr_fd(line, fd_infile);
        ft_putstr_fd("\n", fd_infile);
        free(line);
    }
    close(fd_infile);
    fd_infile = open(".heredoc.txt", O_RDONLY);
    if (fd_infile == -1)
        ft_exit_error();
    dup2(fd_infile, STDIN_FILENO);
    close(fd_infile);
}


void    ft_dup_infile(t_data *data)
{
    int fd_infile;
    
    if (data->nredirection == 1 && data->redirection == '<')
    {
        fd_infile = open(data->file, O_RDONLY);
        if (fd_infile == -1)
            ft_exit_error(); 
        dup2(fd_infile, STDIN_FILENO);
        close(fd_infile);
    }
    else if (data->nredirection == 2 && data->redirection == '<')
    {
        ft_heredoc(data);
        exit(EXIT_SUCCESS);
    }
}

void    ft_exit_error(void)
{
    perror("fd_outfile:");
    exit(EXIT_FAILURE);
}

void    ft_dup_outfile(t_data *data)
{
    int fd_outfile;
    
    if (data->nredirection == 1 && data->redirection == '>')
    {
        fd_outfile = open(data->file, O_TRUNC | O_CREAT | O_RDWR, 0664);
        if (fd_outfile == -1)
            ft_exit_error();
        close(STDOUT_FILENO);
        dup2(fd_outfile, STDOUT_FILENO);
        close(fd_outfile);
    }
    else if (data->nredirection == 2 && data->redirection == '>')
    {
        fd_outfile = open(data->file, O_APPEND | O_CREAT | O_RDWR, 0664);
        if (fd_outfile == -1)
            ft_exit_error();
        close(STDOUT_FILENO);
        dup2(fd_outfile, STDOUT_FILENO);
        close(fd_outfile);
    }
}

void	ft_redirections(t_data *data)
{
	ft_dup_infile(data);
	ft_dup_outfile(data);
}

int ft_redirection_check(t_data *data)
{
    if (data->nredirection == 1 && data->redirection == '<')
        return (1);
    else if (data->nredirection == 2 && data->redirection == '<')
        return (1);
    else if (data->nredirection == 1 && data->redirection == '>')
        return (1);
    else if (data->nredirection == 2 && data->redirection == '>')
        return (1);
    return (0);
}

void ft_execute_pipes(t_data *data, t_list *head) 
{
    int status = 0;
    char **command;
    //int pipefd[2];
    int prev_pipe;
    int pid;
    
    prev_pipe = -1;
    signal(SIGUSR2, SIG_IGN);
    while (head) 
    {
        if (ft_not_redirected_builtins(data) == 1 && head->next == NULL)
    {
        ft_execute_not_rebuiltins(data);
        return;
    }
    else if (ft_not_redirected_builtins(data) == 1 && head->next != NULL)
    {
        head = head->next;
    }
        command = ft_split(head->content, data->redirection);
        free(head->content);
        head->content = ft_strtrim(command[0], " ");
        //printf("content:%s\n", head->content);
        //printf("content:%s\n", head->content);
        data->file = ft_strtrim(command[1], " ");
            //printf("file:%s\n", data->file);
            //printf("file:%s\n", data->file);
        ft_free_matrix(command);
        data->cmd->cmd_splited = ft_command(head->content, data);
        //  ft_redirections(data);
        data->cmd->path = ft_get_path(data->cmd->cmd_splited, data);
        //data->cmd->path = ft_cmd(data, data->cmd->cmd_splited[0]);
    
        if (data->cmd->path == NULL && ft_redirection_check(data) == 0)
        {
            printf("Error: command not found\n");
            data->cmd->exit_status = 127;
            ft_free_matrix(data->cmd->cmd_splited);
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
        {
            ft_execute_child(data, head, prev_pipe);
        } 
        else 
            ft_execute_parent(status, data, head, prev_pipe, pid);
        if ((access(*data->cmd->cmd_splited, 0) != 0))
            free(data->cmd->path);
        data->redirection = 0;
        ft_free_matrix(data->cmd->cmd_splited);
        free(data->file);
        prev_pipe = data->cmd->pipefd[0];
        head = head->next;
    }
}

void ft_execute(t_data *data) 
{
    t_list *head = data->command;
    if (ft_is_redirected_builtins(data) == 1 && head->next == NULL)
    {
        printf("Is redirected builtins, will not enter en execute\n");
        ft_execute_rebuiltins(data);
    }
    else
        ft_execute_pipes(data, head);
}
