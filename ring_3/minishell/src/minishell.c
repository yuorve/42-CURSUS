/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:33:33 by yoropeza          #+#    #+#             */
/*   Updated: 2023/12/22 17:35:34 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_checks(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	return (0);
}

void	ft_free(void *data)
{
	free(data);
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_list	*ft_previously(t_list *list, t_list *target)
{
	t_list	*curr;

	if (!list)
		return (0);
	curr = list;
	while (curr->next)
	{
		if (curr->next == target)
			return (curr);
		curr = curr->next;
	}
	return (0);
}

t_list	*ft_previously1(t_list *list, char *content)
{
	t_list	*curr;

	if (!list)
		return (0);
	curr = list;
	while (curr->next)
	{
		if (curr->next->content == content)
			return (curr);
		curr = curr->next;
	}
	return (0);
}

t_list	*ft_add_to_list(t_list *list, char *content)
{
	if (!list)
		list = ft_lstnew(ft_strtrim(content, " "));
	else
		ft_lstadd_back(&list, ft_lstnew(ft_strtrim(content, " ")));
	return (list);
}

int	ft_findpos(char *str, char c)
{
	int	i;

	i = 1;
	while (str[i] && !ft_checks(str[i], c))
		i++;
	return (i);
}

int	ft_quoted(char *str)
{
	int i;
	int numQuotes;
	int numSingleQuotes;

	numQuotes = 0;
	numSingleQuotes = 0;
	i = 0;
	while (str[i])
	{
		if (ft_checks(str[i], '\"') && !(numSingleQuotes % 2))
			numQuotes++;
		else if (ft_checks(str[i], '\'') && !(numQuotes % 2))
			numSingleQuotes++;
		i++;
	}
	return ((numQuotes % 2) || (numSingleQuotes % 2));
}

char	*ft_replace(char *str)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;	
	while (str[i])
	{		
		if ((str[i] != '\"' && str[i] != '\'')
		 || (str[i] == '\'' && flag == 1)
		 || (str[i] == '\"' && flag == 2))
			str[j++] = str[i];
		if (ft_checks(str[i], '\"') && flag != 2)
		{
			if (flag == 1)
				flag = 0;
			else
				flag = 1;
		}
		else if (ft_checks(str[i], '\'') && flag != 1)
		{
			if (flag == 2)
				flag = 0;
			else
				flag = 2;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_command(char *str)
{
	int		i;
	int		j;
	char	*tmp;
	char	*leak_prevent;
	char	**values;

	values = ft_split(str, ' ');
	i = 0;
	while (values[i])
	{
		if (ft_quoted(values[i]))
		{
			tmp = values[i];
			j = i;
			while (values[++i] && ft_quoted(tmp))
			{
				leak_prevent = ft_strjoin(tmp, " ");
				tmp = ft_strjoin(leak_prevent, values[i]);
				free(leak_prevent);
				free(values[i]);
				values[i] = 0;
			}
			values[j] = tmp;
			i = j;
		}
		values[i] = ft_replace(values[i]);
		i++;
	}
	return (values);
}

char	*ft_name(char *str)
{
	char	*name;
	char	**values;

	name = 0;
	if (ft_strchr(str, '='))
	{
		values = ft_split(str, '=');
		name = values[0];
		ft_free_split(values);
	}
	return (name);
}

char	*ft_value(char *str)
{
	char	*value;
	char	**values;

	value = 0;
	if (ft_strchr(str, '='))
	{
		values = ft_split(str, '=');
		value = values[1];
		ft_free_split(values);
	}
	return (value);
}

void	ft_params(t_data *data, char *str)
{
	int		i;
	char	*tmp;
	char	*leak_prevent;
	char	**values;

	if (ft_lstsize(data->parameter) > 0)
		ft_lstclear(&data->parameter, ft_free);
	values = ft_split(str, ' ');
	i = 1;
	while (values[i])
	{
		if (ft_quoted(values[i]))
		{
			tmp = values[i];
			while (values[++i] && ft_quoted(tmp))
			{
				leak_prevent = ft_strjoin(tmp, " ");
				tmp = ft_strjoin(leak_prevent, values[i]);
				free(leak_prevent);
				free(tmp);
			}
			i--;
			data->parameter = ft_add_to_list(data->parameter, tmp);
		}
		else
			data->parameter = ft_add_to_list(data->parameter, values[i]);
		i++;
	}
	ft_free_split(values);
}

void debug(t_data *data)
{
	int		i;
	t_list	*nodo;
	t_list	*prev;

	ft_printf("Número de Comandos: %d\n", ft_lstsize(data->command));
	if (ft_lstsize(data->command) == 1)
	{
		ft_printf("Comando: %s\n", data->command->content);
		ft_printf("Commando dividido: %s\n", ft_command(data->command->content)[0]);
		ft_params(data, data->command->content);
		ft_printf("Número de Parametros: %d\n", ft_lstsize(data->parameter));
		if (ft_lstsize(data->parameter) > 0)
		{
			ft_printf("parametro: %s\n", data->parameter->content);
			if (ft_strchr(data->parameter->content, '='))
			{
				ft_printf("Variable: %s\n", ft_name(data->parameter->content));
				ft_printf("Valor: %s\n", ft_value(data->parameter->content));
			}
		}
	}
	else
	{
		nodo = data->command;
		while (nodo)
		{
			ft_printf("Comando: %s\n", nodo->content);
			ft_printf("Commando dividido: %s\n", ft_command(nodo->content)[0]);
			ft_printf("Commando dividido: %s\n", ft_command(nodo->content)[1]);
			ft_params(data, nodo->content);
			ft_printf("Número de Parametros: %d\n", ft_lstsize(data->parameter));
			if (ft_lstsize(data->parameter) > 0)
			{
				ft_printf("parametro: %s\n", data->parameter->content);
				if (ft_strchr(data->parameter->content, '='))
				{
					ft_printf("Variable: %s\n", ft_name(data->parameter->content));
					ft_printf("Valor: %s\n", ft_value(data->parameter->content));
				}
			}
			prev = ft_previously(data->command, nodo);
			if (prev)
				ft_printf("Comando anterior: %s\n", prev->content);
			nodo = nodo->next;
		}
	}
	i = 0;
	while (data->env[i])
		ft_printf("env: %s\n", data->env[i++]);
}

void	ft_pipes(t_data *data, char *str)
{
	int		i;
	char	*tmp;
	char	*leak_prevent;
	char	**values;

	values = ft_split(str, '|');
	i = 0;
	while (values[i])
	{
		if (ft_quoted(values[i]))
		{
			tmp = values[i];
			while (values[++i] && ft_quoted(tmp))
			{
				leak_prevent = ft_strjoin(tmp, "|");
				free(tmp);
				tmp = ft_strjoin(leak_prevent, values[i]);
				free(leak_prevent);
			}
			i--;
			data->command = ft_add_to_list(data->command, tmp);
			free(tmp);
		}
		else
			data->command = ft_add_to_list(data->command, values[i]);
		i++;
	}
	ft_free_split(values);
}

void	ft_input_checks(t_data *data, char *str)
{
	int	i;
	int	start;
	int	flag;

	data->npipes = 0;
	data->nredirection = 0;
	start = 0;
	flag = 0;
	i = 0;
	while (str[i])
	{
		if (ft_checks(str[i], '\"') && flag != 2)
		{
			if (flag == 1)
				flag = 0;
			else
				flag = 1;
		}
		else if (ft_checks(str[i], '\'') && flag != 1)
		{
			if (flag == 2)
				flag = 0;
			else
				flag = 2;
		}
		else if (ft_checks(str[i], '|') && flag == 0)
		{
			data->npipes++;
			start = i;
		}
		else if ((ft_checks(str[i], '>') || ft_checks(str[i], '<')) && flag == 0)
		{
			if (data->nredirection > 0 && data->redirection != str[i])
				flag = 3;
			data->redirection = str[i];
			data->nredirection++;
		}
		else if (ft_checks(str[i], '$') && flag == 1)
		{
			start = i++;
			if (ft_isalpha(str[i]))
			{
				while (ft_isalpha(str[i]))
					i++;
				ft_printf("Obtain value from: %s\n", ft_substr(str, start, i - start));
				i--;
			}
			else
				flag = 3;
		}
		else if (flag == 0)
		{
			if (ft_checks(str[i], ';') || ft_checks(str[i], '\\'))
			{
				flag = 3;
				break ;
			}
		}
		i++;
	}
	if (flag != 0 || data->nredirection > 2)
		exit(ft_printf("\033[31;1mSyntax Error\n \033[0m"));
}

void	ft_void(void)
{
	system("leaks -q 'minishell'");
}

int ft_cd(t_data *data)
{
	int		response;

	ft_params(data, data->command->content);
	if (ft_lstsize(data->parameter) == 1)
	{
		if (ft_strncmp(data->command->content, "cd", 2) == 0)
		{
			ft_printf("ok");
			//set env OLDPWD
			response = chdir(data->parameter->content);
			if (response != 0)
				perror("error");
			// SET ENV PWD
		}
	}
	else
		ft_printf("cd: too many arguments\n");
	return (0);
}

int	ft_echo(t_data *data)
{
	t_list	*current;
	char	*leak_prevent;
	char	*str;

	if (ft_strncmp(data->command->content, "echo", 4) == 0)
	{
		ft_params(data, data->command->content);
		if (ft_lstsize(data->parameter) > 0)
		{
			current = data->parameter;
			if (ft_strncmp(current->content, "-n", 2) == 0)
				current = current->next;
			while (current)
			{
				str = current->content;
				leak_prevent = ft_strtrim(str, "\"");
				str = ft_strtrim(leak_prevent, "\'");
				ft_printf("%s", str);
				free (str);
				free (leak_prevent);
				current = current->next;
				if (current)
					ft_printf(" ");
			}
			if (ft_strncmp(data->parameter->content, "-n", 2) != 0)
				ft_printf("\n");
			ft_lstclear(&current, ft_free);
		}
	}
	return (0);
}

char	*ft_cmd(t_data *data, char *cmd)
{
	int		i;
	char	*str;
	char	**paths;

	if (access(cmd, 0) == 0)
			return (cmd);
	i = 0;
	while (data->env[i] && ft_strncmp(data->env[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(ft_substr(data->env[i], 5, ft_strlen(data->env[i])), ':');
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

int		ft_input(t_list *curr)
{
	int		fd;
	char	**command;
		
	command = ft_split(curr->content, '<');
	free (curr->content);
	curr->content = ft_strtrim(command[0], " ");
	fd = open(ft_strtrim(command[1], " "), O_RDONLY);
	if (!fd)
	{
		perror("error open input file");
		exit(EXIT_FAILURE);
	}
	ft_free_split(command);
	return (fd);
}

int		ft_output(t_list *curr, int nredirection)
{
	int		fd;
	char	**command;
	
	command = ft_split(curr->content, '>');
	free (curr->content);
	curr->content = ft_strtrim(command[0], " ");
	if (nredirection == 1)
		fd = open(ft_strtrim(command[1], " "), O_CREAT|O_WRONLY|O_TRUNC,0644);
	else
		fd = open(ft_strtrim(command[1], " "), O_CREAT|O_WRONLY|O_APPEND,0644);
	if (!fd)
	{
		perror("error open output file");
		exit(EXIT_FAILURE);
	}
	ft_free_split(command);
	return (fd);
}

void	ft_heredoc(t_list *curr)
{
	int		fd;
	char	*input;
	char	*end;
	char	**command;
	
	command = ft_split(curr->content, '<');
	free (curr->content);
	if (!command[1])
	{
		end = ft_strtrim(command[0], " ");
		curr->content = NULL;
	}
	else
	{
		end = ft_strtrim(command[1], " ");
		curr->content = ft_strtrim(command[0], " ");
	}
	fd = open(".heredocfile.tmp", O_CREAT|O_WRONLY,0644);
	while (1)
	{
		input = readline("\033[33;1m> \033[0m");
		if (input && (ft_strncmp(input, end, ft_strlen(end)) == 0))
		{
			free(input);
			break ;
		}
		if (input && *input)
		{
			write(fd, input, ft_strlen(input));
			write(fd, " ", 1);
		}
		free(input);
	}
	ft_free_split(command);
	free (end);
	close(fd);
}

int	ft_redirections(t_data *data, t_list *curr)
{
	char	*end;

	end = ft_substr(curr->content, ft_findpos(curr->content, '<') + 1, 2);
	if (data->nredirection == 1 && data->redirection == '<')
		return (1);
	else if (data->nredirection == 2 && data->redirection == '<')
		return (3);
	else if (data->nredirection > 0 && data->redirection == '>')
		return (2);
	data->nredirection = 0;
	free (end);
	return (0);
}

void	ft_execute(t_data *data, t_list *curr, int *prev_pipe)
{
	int		fd[2];
	int		file;
	int		status, pid;
	char	**command;
	
	file = -1;
	ft_input_checks(data, curr->content);
	if (ft_redirections(data, curr) == 1)
		file = ft_input(curr);
	else if (ft_redirections(data, curr) == 2)
		file = ft_output(curr, data->nredirection);
	else if (ft_redirections(data, curr) == 3)
		ft_heredoc(curr);
	else if (curr->next)
		pipe(fd);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (file > -1)
		{
			if (ft_redirections(data, curr) == 1)
			{
				dup2(file, STDIN_FILENO);
			}
			else
			{
				dup2(file, STDOUT_FILENO);
			}
		}
		if (prev_pipe)
		{
			close(fd[READ_END]);
			dup2(prev_pipe[READ_END], STDIN_FILENO);
			close(prev_pipe[READ_END]);
		}
		if (curr->next)
		{
			close(fd[READ_END]);
			dup2(fd[WRITE_END], STDOUT_FILENO);
			close(fd[WRITE_END]);
		}
		if (curr->content)
		{
			command = ft_command(curr->content);
			command[0] = ft_cmd(data, command[0]);
			execve(command[0], command, data->env);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
			exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
		if (file > -1)
		{
			close(file);
		}
		if (prev_pipe)
			close(prev_pipe[READ_END]);
		if (curr->next)
		{
			close(fd[WRITE_END]);
			ft_execute(data, curr->next, fd);
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	char	*input;

	atexit(ft_void);
	(void) argc;
	(void) argv;
	(void) env;
	using_history();
	ft_bzero(&data, sizeof(t_data));
	while (1)
	{
		data.env = env;
		input = readline("\033[32;1mMinishell> \033[0m");
		if (input && (ft_strncmp(input, "exit", 4) == 0))
		{
			free(input);
			break ;
		}
		if (input && *input)
		{
			add_history(input);
			ft_pipes(&data, input);
			ft_params(&data, data.command->content);
			ft_execute(&data, data.command, NULL);
			//debug(&data);
		}
		ft_lstclear(&data.command, ft_free);
		ft_lstclear(&data.parameter, ft_free);
		free(input);
	}
	clear_history();
	return (0);
}
