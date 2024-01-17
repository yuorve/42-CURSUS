/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:48:45 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/17 21:58:04 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_heredoc(t_data *data)
{
	char	*line;
	int		fd_infile;

	fd_infile = open(".heredoc.txt", O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (fd_infile == -1)
		ft_exit_error();
	while (1)
	{
		line = readline("\033[33;1m> \033[0m");
		if (ft_strcmp(line, data->command->content) == 0)
		{
			free(line);
			break ;
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

void	ft_dup_infile(t_data *data)
{
	int	fd_infile;

	if (data->nredirection == 1 && data->redirection == '<')
	{
		fd_infile = open(ft_filename(data, data->file), O_RDONLY);
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

void	ft_dup_outfile(t_data *data)
{
	int	fd_outfile;

	if (data->nredirection == 1 && data->redirection == '>')
	{
		fd_outfile = open(ft_filename(data, data->file),
				O_TRUNC | O_CREAT | O_RDWR, 0664);
		if (fd_outfile == -1)
			ft_exit_error();
		close(STDOUT_FILENO);
		dup2(fd_outfile, STDOUT_FILENO);
		close(fd_outfile);
	}
	else if (data->nredirection == 2 && data->redirection == '>')
	{
		fd_outfile = open(ft_filename(data, data->file),
				O_APPEND | O_CREAT | O_RDWR, 0664);
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

int	ft_redirection_check(t_data *data)
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
