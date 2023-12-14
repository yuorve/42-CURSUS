/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:01 by angalsty          #+#    #+#             */
/*   Updated: 2023/12/14 21:22:03 by angalsty         ###   ########.fr       */
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



void    ft_execute_child(t_data *data, t_list *head, int prev_pipe) 
{
            // Hijo
            if (ft_redirections_pars(data) == 1)
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
            //ft_redirections(data);

            close(data->cmd->pipefd[0]);
            close(data->cmd->pipefd[1]);


            execve(data->cmd->path, data->cmd->cmd_splited, data->cmd->env_copy);
            perror("Exec error");
            //exit(EXIT_FAILURE);
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



void	ft_heredoc(t_data *data)
{
	int		fd;
	char	*input;
    char	*cmd;
	char	*end;

	cmd = data->command->content;
	end = ft_substr(cmd, 2, ft_strlen(cmd) - 2);

	fd = open(".heredocfile.tmp", O_CREAT|O_WRONLY,0644);
	while (1)
	{
		input = readline("\033[33;1mheredoc> \033[0m");
		if (input && (ft_strncmp(input, end, ft_strlen(end)) == 0))
		{
			free(input);
			break ;
		}
		if (input && *input)
		{
			write(fd, input, ft_strlen(input));
			write(fd, "\n", 1);
		}
		free(input);
	}
    close(fd);
    
    // fd = open(".heredocfile.tmp", O_RDONLY);
    // if (fd == -1)
    // {
    //     perror("Error opening file");
    //     free(end);
    //     free(input);
    //     exit(EXIT_FAILURE);
    // }
    dup2(fd, STDIN_FILENO);
	close(fd);
    free(end);
}



int	ft_redirections_pars(t_data *data)
{
	if (data->nredirection == 1 && data->redirection == '<')
		{
            data->cmd->infiles = 1;
            ft_printf("busca fichero\n");
            return (1);
        }
	else if (data->nredirection == 2 && data->redirection == '<')
		{
            data->cmd->heredoc = 1;
            printf("heredoc\n");
            return (1);
        }
	else if (data->nredirection == 1 && data->redirection == '>')
		{
            data->cmd->outfiles = 1;
            printf("output\n");
            return (1);
        }
    else if (data->nredirection == 2 && data->redirection == '>')
    {
        data->cmd->append = 1;
        printf("append\n");
        return (1);
    }
    return(0);
}

void    ft_dup_infile(t_data *data)
{
    int fd;
    
    if (data->cmd->infiles == 1)
    {
        fd = open(data->file, O_RDONLY);
        if (fd == -1)
        {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
    else if (data->cmd->heredoc == 1)
    {
        ft_heredoc(data);
        //fd = open(".heredocfile.tmp", O_RDONLY);
        // if (fd == -1)
        // {
        //     perror("Error opening file");
        //     exit(EXIT_FAILURE);
        // }
        // dup2(fd, STDIN_FILENO);
        // close(fd);
    }
}

void    ft_dup_outfile(t_data *data)
{
    int fd;
    int i;

    i = 0;
    
    if (data->cmd->outfiles == 1)
    {
        fd = open(data->cmd->cmd_splited[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            dup2(fd, STDOUT_FILENO);
            close(fd);
            data->cmd->cmd_splited[i] = NULL;

        
        // fd[1] = open(data->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        // if (fd[1] == -1)
        // {
        //     perror("Error opening file");
        //     exit(EXIT_FAILURE);
        // }
        // dup2(fd[1], STDOUT_FILENO);
        // close(fd[1]);
    }
    else if (data->cmd->append == 1)
    {

        fd = open(data->cmd->cmd_splited[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
            dup2(fd, STDOUT_FILENO);
            close(fd);
            data->cmd->cmd_splited[i] = NULL;

            
        // fd[1] = open(data->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
        // if (fd[1] == -1)
        // {
        //     perror("Error opening file");
        //     exit(EXIT_FAILURE);
        // }
        // dup2(fd[1], STDOUT_FILENO);
        // close(fd[1]);
    }
}

void	ft_redirections(t_data *data)
{
	/*if (cmd->prev != NULL)
		dup2(cmd->prev->fd[0], 0);
	if (cmd->next != NULL)
		dup2(cmd->fd[1], 1);*/
	ft_dup_infile(data);
	ft_dup_outfile(data);
}



void ft_execute_pipes(t_data *data, t_list *head) 
{
    int status = 0;
    //int pipefd[2];
    int prev_pipe;
    int pid;
    
    prev_pipe = -1;
    while (head) 
    {
        data->cmd->cmd_splited = ft_command(head->content, data);
        if (ft_redirections_pars(data) == 1)
            ft_redirections(data);
            else
            
        {
            data->cmd->path = ft_get_path(data->cmd->cmd_splited, data);
        //data->cmd->path = ft_cmd(data, data->cmd->cmd_splited[0]);
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
        }

    prev_pipe = data->cmd->pipefd[0];
    head = head->next;
    }
}

void ft_execute(t_data *data) 
{
    t_list *head = data->command;
    ft_execute_pipes(data, head);
}

