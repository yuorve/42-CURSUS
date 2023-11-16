/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:33:33 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/16 20:27:06 by yoropeza         ###   ########.fr       */
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

void	parser(t_data *data, char *str)
{
	int		i;
	char	*tmp;
	char	**values;

	if (ft_strchr(str, '|') && ft_findpos(str, '|') < ft_findpos(str, '\"'))
	{
		values = ft_split(str, '|');
		i = 0;
		while (values[i])
		{
			parser(data, values[i]);
			free(values[i]);
			i++;
		}
		free(values);
	}
	else
	{
		values = ft_split(str, ' ');
		data->command = ft_add_to_list(data->command, values[0]);
		i = 1;
		while (values[i])
		{
			if (values[i][0] == '\"' && values[i][ft_strlen(values[i]) - 1] != '\"')
			{
				tmp = values[i++];
				while (!ft_strchr(values[i], '\"'))
				{
					tmp = ft_strjoin(tmp, " ");
					tmp = ft_strjoin(tmp, values[i]);
					i++;
				}
				tmp = ft_strjoin(tmp, " ");
				tmp = ft_strjoin(tmp, values[i]);
				data->parameter = ft_add_to_list(data->parameter, tmp);
				free(tmp);
			}
			else
			{
				if (values[i][0] == '|')
				{
					i++;
					data->command = ft_add_to_list(data->command, values[i]);
				}
				else
					data->parameter = ft_add_to_list(data->parameter, values[i]);
			}
			i++;
		}
		free(values);
	}
}

void	ft_input_checks(char *str)
{
	int	i;
	int	start;
	int	flag;

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
			ft_printf("Found pipe\n");
		}
		else if (ft_checks(str[i], '$') && flag != 2)
		{
			start = i++;
			while (ft_isalpha(str[i]))
				i++;
			ft_printf("Get value from: %s\n", ft_substr(str, start, i - start));
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

void	ft_void(void)
{
	system("leaks -q 'minishell'");
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*input;

	atexit(ft_void);
	(void) argc;
	(void) argv;
	using_history();
	ft_bzero(&data, sizeof(t_data));
	while (1)
	{
		input = readline("\033[32;1mMinishell> \033[0m");
		if (input && (ft_strncmp(input, "exit", 4) == 0))
		{
			free(input);
			break ;
		}
		if (input && *input)
		{
			add_history(input);
			ft_input_checks(input);
			parser(&data, input);
			debug(&data);
		}
		ft_lstclear(&data.command, ft_free);
		ft_lstclear(&data.parameter, ft_free);
		free(input);
	}
	clear_history();
	return (0);
}
