/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:33:33 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/28 18:20:08 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_checks(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	return (0);
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

void debug(t_data *data)
{
	t_list	*nodo;
	char	**str;

	if (ft_lstsize(data->command) == 1)
	{
		ft_printf("Comando: %s\n", data->command->content);
	}
	else
	{
		nodo = data->command;
		while (nodo)
		{
			ft_printf("Comandos: %s\n", nodo->content);
			nodo = nodo->next;
		}
	}
	if (ft_lstsize(data->parameter) == 1)
	{
		ft_printf("parametro: %s\n", data->parameter->content);		
		if (ft_strchr(data->parameter->content, '='))
		{
			str = ft_split(data->parameter->content, '=');
			ft_printf("Variable: %s\n", str[0]);
			ft_printf("Valor: %s\n", str[1]);
			ft_free_split(str);
		}
	}
	else
	{
		nodo = data->parameter;
		while (nodo)
		{
			ft_printf("parametros: %s\n", nodo->content);
			if (ft_strchr(nodo->content, '='))
			{
				str = ft_split(nodo->content, '=');
				ft_printf("Variable: %s\n", str[0]);
				ft_printf("Valor: %s\n", str[1]);
				ft_free_split(str);
			}
			nodo = nodo->next;
		}
	}
}

t_list	*ft_add_to_list(t_list *list, char *content)
{
	if (!list)
		list = ft_lstnew(content);
	else
		ft_lstadd_back(&list, ft_lstnew(content));
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

	numQuotes = 0;
	i = 0;
	while (str[i])
	{
		if (ft_checks(str[i], '\"'))
			numQuotes++;
		i++;
	}
	return (numQuotes % 2);
}

void	ft_spaces(t_data *data, char *str)
{
	int		i;
	char	*tmp;
	char	**values;

	values = ft_split(str, ' ');
	
	//printf("values_spaces[0]: %s\n", values[0]);
	data->command = ft_add_to_list(data->command, values[0]);
	i = 1;
	while (values[i])
	{
		if (ft_quoted(values[i]))
		{
			tmp = values[i++];
			while (values[i] && !ft_quoted(values[i]))
			{
				tmp = ft_strjoin(tmp, ft_strjoin(" ", values[i]));
				i++;
			}
			tmp = ft_strjoin(tmp, ft_strjoin(" ", values[i]));
			data->parameter = ft_add_to_list(data->parameter, tmp);
		}
		else
		{
			data->parameter = ft_add_to_list(data->parameter, values[i]);
		}
		i++;
	}
	free(values);
}


void	ft_pipes(t_data *data, char *str)
{
	int		i;
	char	*tmp;
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
			tmp = values[i++];
			while (values[i] && !ft_quoted(values[i]))
			{
				tmp = ft_strjoin(tmp, ft_strjoin("|", values[i]));
				i++;
			}
			tmp = ft_strjoin(tmp, ft_strjoin("|", values[i]));
			printf("tmp: %s\n", tmp);
			ft_spaces(data, tmp);
		}
		else
		{
			if (ft_strchr(values[i], ' '))
				ft_spaces(data, values[i]);
			else
				data->command = ft_add_to_list(data->command, values[i]);
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
		else if (ft_checks(str[i], '$') && flag != 2)
		{
			start = i++;
			while (ft_isalpha(str[i]))
				i++;
			ft_printf("Obtain value from: %s\n", ft_substr(str, start, i - start));
			i--;
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
