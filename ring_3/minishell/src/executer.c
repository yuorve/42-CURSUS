/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:01 by angalsty          #+#    #+#             */
/*   Updated: 2023/12/20 21:00:15 by yoropeza         ###   ########.fr       */
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

char	*ft_cmd(t_data *data, char *cmd)
{
	int		i;
	char	*str;
	char	**paths;

	if (access(cmd, 0) == 0)
			return (cmd);
	i = 0;
	while (data->cmd->env_copy[i] && ft_strncmp(data->cmd->env_copy[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(ft_substr(data->cmd->env_copy[i], 5, ft_strlen(data->cmd->env_copy[i])), ':');
	i = 0;
	cmd = ft_strjoin("/", cmd);
	while (paths[i])
	{
		str = ft_strjoin(paths[i], cmd);
		if (access(str, 0) == 0)
			return (str);
		free(str);
		i++;
	}
	perror("minishell");
	exit(EXIT_FAILURE);
}

void    ft_execute_child(t_data *data, t_list *head, int prev_pipe) 
{
            // Hijo
            if (ft_redirections_pars(data) == 1)
                ft_redirections(data);
            if (data->cmd->path)
            {
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

// void    ft_redirections(t_data *data)
// {
//     int fd;
//     int i;

//     i = 0;
//     while (data->cmd->cmd_splited[i])
//     {
//         if (ft_strcmp(data->cmd->cmd_splited[i], ">") == 0)
//         {
//             fd = open(data->cmd->cmd_splited[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
//             dup2(fd, STDOUT_FILENO);
//             close(fd);
//             data->cmd->cmd_splited[i] = NULL;
//         }
//         else if (ft_strcmp(data->cmd->cmd_splited[i], ">>") == 0)
//         {
//             fd = open(data->cmd->cmd_splited[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
//             dup2(fd, STDOUT_FILENO);
//             close(fd);
//             data->cmd->cmd_splited[i] = NULL;
//         }
//         else if (ft_strcmp(data->cmd->cmd_splited[i], "<") == 0)
//         {
//             fd = open(data->cmd->cmd_splited[i + 1], O_RDONLY);
//             dup2(fd, STDIN_FILENO);
//             close(fd);
//             data->cmd->cmd_splited[i] = NULL;
//         }
//         i++;
//     }
// }

// void    ft_redirections(t_data *data)
// {
//     t_list *prev;

//     prev = ft_previously(data->command, nodo);
//     if(data->p)
// }


void	ft_output(t_data *data)
{
	pid_t	pid;
	FILE	*fd;
	char	**command;

	command = ft_split(data->command->content, data->redirection);
	free (data->command->content);
	data->command->content = ft_strtrim(command[0], " ");
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (data->nredirection == 1)
			fd = fopen(ft_strtrim(command[1], " "), "w");
		else
			fd = fopen(ft_strtrim(command[1], " "), "a");
		if (!fd)
		{
			perror("error open output file");
			exit(EXIT_FAILURE);
		}
		dup2(fileno(fd), STDOUT_FILENO);
		ft_free_split(command);
		command = ft_command(data->command->content, data);
		command[0] = ft_cmd(data, command[0]);
		if (execve(command[0], command, data->env) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		fclose(fd);
	}
	else
		waitpid(pid, NULL, 0);
	ft_free_split(command);
}

void	ft_get_file(t_data *data)
{
	//get next line y meter en data->parameter
	(void) data;
}

void	ft_heredoc(t_data *data)
{
	int		fd;
	char	*input;
    //char	*cmd;

	//cmd = data->command->content;
	fd = open(".heredocfile.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		// if (data->npipes > 0)
		// 	input = readline("\033[33;1mpipe heredoc> \033[0m");
		// else
			input = readline("\033[33;1mheredoc> \033[0m");
		if (input && (ft_strncmp(input, data->command->content, ft_strlen(data->command->content)) == 0))
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
    //free(cmd);
}

int	ft_redirections_pars(t_data *data)
{
	// char	*cmd;
	// char	*end;

	// cmd = data->command->content;
	// end = ft_substr(cmd, 2, ft_strlen(cmd) - 2);
	if (data->nredirection == 1 && data->redirection == '<')
		{
            data->cmd->infiles = 1;
            return (1);
        }
	else if (data->nredirection == 2 && data->redirection == '<')
		{
            //ft_heredoc(data, end ;
            data->cmd->heredoc = 1;
            return (1);
        }
	else if (data->nredirection == 1 && data->redirection == '>')
		{
            //ft_output(data);
            data->cmd->outfiles = 1;
            return (1);
        }
    else if (data->nredirection == 2 && data->redirection == '>')
        {
            data->cmd->append = 1;
            return (1);
        }
	// else
	// 	ft_execute(data);
	// free (end);
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
        exit(0);
        // fd = open(".heredocfile.tmp", O_RDONLY);
        // if (fd[0] == -1)
        // {
        //     perror("Error opening file");
        //     exit(EXIT_FAILURE);
        // }
        // dup2(fd, STDIN_FILENO);
        // close(fd[0]);
    }
}

void    ft_dup_outfile(t_data *data)
{
    int fd[2];
    
    if (data->cmd->outfiles == 1)
    {
        fd[1] = open(data->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd[1] == -1)
        {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
    }
    else if (data->cmd->append == 1)
    {
        fd[1] = open(data->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd[1] == -1)
        {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
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
    char    **command;
    int status = 0;
    //int pipefd[2];
    int prev_pipe;
    int pid;
    
    prev_pipe = -1;
    while (head) 
    {
        command = ft_split(head->content, data->redirection);
        free (head->content);
        head->content = ft_strtrim(command[0], " ");
        data->file = ft_strtrim(command[1], " ");
        ft_free_split(command);
        data->cmd->cmd_splited = ft_command(head->content, data);
        // if (ft_redirections_pars(data) == 1)
        //     ft_redirections(data);
        // else    
        //{
            data->cmd->path = ft_get_path(data->cmd->cmd_splited, data);
            //data->env = data->cmd->env_copy;
            //data->cmd->path = ft_cmd(data, data->cmd->cmd_splited[0]);
            // if (data->cmd->path == NULL) 
            // {
            //     printf("Error: command not found\n");
            //     return;
            // }
            //if (ft_redirections_pars(data) == 1)
            //    ft_redirections(data);
            //if (data->cmd->heredoc == 1)
            //{
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
            //}
        //}
        data->cmd->heredoc = 0;        
	    data->nredirection = 0;
        if (access(data->cmd->cmd_splited[0], 0) != 0)
            free(data->cmd->path);
        ft_free_matrix(data->cmd->cmd_splited);
        free (data->file);
        prev_pipe = data->cmd->pipefd[0];
        head = head->next;
    }   
}

void ft_execute(t_data *data) 
{
    t_list *head = data->command;
    ft_execute_pipes(data, head);
}

