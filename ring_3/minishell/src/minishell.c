/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:33:33 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/29 19:02:36 by angalsty         ###   ########.fr       */
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

char	*ft_command(char *str)
{
	char	*command;
	char	**values;
	
	command = 0;
	values = 0;
	if (ft_strchr(str, ' '))
	{
		values = ft_split(str, ' ');
		command = values[0];
		free (values);
	}
	else
		command = str;
	return (command);
}

char	*ft_name(char *str)
{
	char	*name;
	char	**values;
	
	if (ft_strchr(str, '='))
	{
		values = ft_split(str, '=');
		name = values[0];
		free(values);
	}
	return (name);
}

char	*ft_value(char *str)
{
	char	*value;
	char	**values;
	
	if (ft_strchr(str, '='))
	{
		values = ft_split(str, '=');
		value = values[1];
		free(values);
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
				free(tmp);
				tmp = ft_strjoin(leak_prevent, values[i]);
				free(leak_prevent);
			}
			i--;
			data->parameter = ft_add_to_list(data->parameter, tmp);
		}
		else
			data->parameter = ft_add_to_list(data->parameter, values[i]);
		i++;
	}
	free (values);
}

void debug(t_data *data)
{
	t_list	*nodo;
	t_list	*prev;

	ft_printf("Número de Comandos: %d\n", ft_lstsize(data->command));
	if (ft_lstsize(data->command) == 1)
	{
		ft_printf("Comando: %s\n", data->command->content);
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
}

void	ft_spaces(t_data *data, char *str)
{
	int		i;
	char	*tmp;
	char	*leak_prevent;
	char	**values;

	values = ft_split(str, ' ');
	
	//printf("values_spaces[0]: %s\n", values[0]);
	data->command = ft_add_to_list(data->command, values[0]);
	i = 1;
	while (values[i])
	{
		if (ft_quoted(values[i]))
		{
			tmp = values[i];
			while (values[++i] && ft_quoted(tmp))
			{
				leak_prevent = ft_strjoin(tmp, " ");
				free(tmp);
				tmp = ft_strjoin(leak_prevent, values[i]);
				free(leak_prevent);
			}
			i--;
			data->parameter = ft_add_to_list(data->parameter, tmp);
			//free(tmp);
		}
		else
		{
			data->parameter = ft_add_to_list(data->parameter, values[i]);
		}
		free (values[i]);
		i++;
	}
	//ft_free_split(values);
}


void	ft_pipes(t_data *data, char *str)
{
	int		i;
	char	*tmp;
	char	*leak_prevent;
	char	**values;

	values = ft_split(str, '|');

	//to keep the complete command in my struct
	data->cmd->cmd_complete = (char **)calloc(sizeof(char **), data->npipes + 1);
	i = 0;
	while (values[i])
	{
		data->cmd->cmd_complete[i] = values[i];
		i++;
	}
	data->cmd->cmd_complete[i] = NULL;
	
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
			printf("tmp: %s\n", tmp);
			}
			i--;
			//ft_spaces(data, tmp);
			data->command = ft_add_to_list(data->command, tmp);
			//free(tmp);
			free (values[i]);
		}
		else
		{
			data->command = ft_add_to_list(data->command, values[i]);
			/*if (ft_strchr(values[i], ' '))
				ft_spaces(data, values[i]);
			else
				data->command = ft_add_to_list(data->command, values[i]);*/
		}
		i++;
	}
	free(values);
}

void	ft_input_checks(t_data *data, char *str)
{
	int	i;
	int	start;
	int	flag;

	data->npipes = 0;
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
	if (flag != 0)
		exit(ft_printf("\033[31;1mSyntax Error\n \033[0m"));
}

void	ft_free(void *data)
{
	free(data);
}


//this function is to find the full comands between pipes
// void    ft_devide_command(t_data *data)
// {
//     int i;
//     char **cmd_copy;

//     i = 0;
//     cmd_copy = ft_split(data->input, '|');
   
//     while (cmd_copy[data->num_command])
//     {
//         printf("cmd_copy[%d]: %s\n", data->num_command, cmd_copy[data->num_command]);
// 		data->num_command++;
//     }
//     data->cmd->cmd_complete = (char **)calloc(sizeof(char **), data->num_command + 1);
//     i = 0;
//     while (cmd_copy[i])
//     {
//         data->cmd->cmd_complete[i] = cmd_copy[i];
//         i++;
//     }
//     data->cmd->cmd_complete[i] = NULL;
    
//     int j = 0;
//     while(data->cmd->cmd_complete[j])
//     {
//         printf("command->cmd[%d] = %s\n", j, data->cmd->cmd_complete[j]);
//         j++;
//     }
//     free(cmd_copy);
// }

void	ft_minishell(t_data *data)
{
	char	*input;

	while (1)
	{
		input = readline("\033[32;1mMinishell> \033[0m");
		//if (input && (ft_strncmp(input, "exit", 4) == 0))
		if (!input)
		{
			free(input);
			//ft_free_matrix(data.cmd->env_copy);
			break ;
		}
		if (input && *input)
		{
			add_history(input);
			ft_input_checks(data, input);
			ft_pipes(data, input);
			debug(data);
			if(ft_not_redirected_builtins(data) == 1)
				ft_execute_not_rebuiltins(data);
            	//printf("tiene que ejecutar el buitin\n");
            else
            	ft_execute(data);
		}
		ft_lstclear(&data->command, ft_free);
		ft_lstclear(&data->parameter, ft_free);
		free(input);
		
	}
}
