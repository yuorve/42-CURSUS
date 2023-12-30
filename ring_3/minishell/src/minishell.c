/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:33:33 by yoropeza          #+#    #+#             */
/*   Updated: 2023/12/30 20:28:36 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)&haystack[i]);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] != '\0'
			&& haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_checks(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	return (0);
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

//no entiendo si esta funcion es necesaria y esta correcta
//esta función la utiliza ft_lstclear para liberar la memoria del nodo de la lista
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

t_list	*ft_add_to_list(t_list *list, char *content)
{
	if (!list)
		list = ft_lstnew(ft_strtrim(content, " "));
	else
		ft_lstadd_back(&list, ft_lstnew(ft_strtrim(content, " ")));
	return (list);
}

// t_list	*ft_previously1(t_list *list, char *content)
// {
// 	t_list	*curr;

// 	if (!list)
// 		return (0);
// 	curr = list;
// 	while (curr->next)
// 	{
// 		if (curr->next->content == content)
// 			return (curr);
// 		curr = curr->next;
// 	}
// 	return (0);
// }

// char	*ft_command(char *str)
// {
// 	char	*command;
// 	char	**values;

// 	command = 0;
// 	values = 0;
// 	if (ft_strchr(str, ' '))
// 	{
// 		values = ft_split(str, ' ');
// 		command = values[0];
// 		free (values);
// 	}
// 	else
// 		command = str;
// 	return (command);
// }

char	**ft_list_to_matrix(t_env_node *head)
{
	int i;
	char **env_matrix;
	char *leak_prevent;
	t_env_node *curr;

	i = 0;
	curr = head;
	env_matrix = (char **)calloc(sizeof(char **), ft_count_nodes(curr) + 1);
	while(curr)
	{
		leak_prevent = ft_strjoin(curr->name, "=");
		env_matrix[i] = ft_strjoin(leak_prevent, curr->value);
		free(leak_prevent);
		i++;
		curr = curr->next;
	}
	env_matrix[i] = NULL;
	return (env_matrix);
}

char    *ft_strxstr(char *str, char *from, char *to)
{
	int     i;
	int     j;
	char    *start;
	char    *end;
	char    *res;
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && from[j] && str[i] == from[j])
		{
			i++;
		   	j++;
		}
		if (from[j])
		{
			i++;
			j = 0;
		}
		else
			break ;
	}
	if (from[0] == '$')
		start = ft_substr(str, 0, (i - j));
	else
		start = ft_substr(str, 0, (i - j) - 1);
	res = ft_strjoin(start, to);
	end = ft_substr(str, i, ft_strlen(str));
	str = ft_strjoin(res, end);
	free (start);
	free (res);
	free (end);
	return (str);
}

char    *ft_variable(char *str)
{
	int     i;
	int     j;
	char    *tmp;
	char    *res;
	res = 0;
	//if (str[0] == '$' && ft_isalpha(str[1]))	
	if (ft_strchr(str, '$'))
	{
		j = 0;
		while (str[j] && str[j] != '$')
			j++;
		tmp = ft_substr(str, j, ft_strlen(str) - j);
		i = 1;
		while (tmp[i] && ft_isalpha(tmp[i]))
			i++;
		res = ft_substr(str, j + 1, i - 1);
		free (tmp);
	}
	return (res);
}

char    *ft_replace(char *str)
{
	int     i;
	int     j;
	int     flag;
	i = 0;
	j = 0;
	flag = 0;
	while (str[i])
	{
		if ((str[i] != '\"' && str[i] != '\'')
			|| (str[i] == '\'' && flag == 1) || (str[i] == '\"' && flag == 2))
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

char    **ft_command(char *str, t_data *data)
{
	int     i;
	int     j;
	int		flag;
	char    *tmp;
	char    *leak_prevent;
	char    **values;
	t_env_node *head;

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
		flag = 0;
		if (data->expand == 1)
		{
			while (ft_strstr(values[i], "$?"))
			{
				flag = 1;
				leak_prevent = ft_itoa(data->cmd->exit_status);
				tmp = ft_strxstr(values[i], "$?", leak_prevent);
				free(leak_prevent);
				free(values[i]);
				values[i] = tmp;
			}
			leak_prevent = ft_variable(values[i]);
		}
		else
			leak_prevent = 0;
		if (leak_prevent)
		{
			head = ft_find_node(data->env_list, leak_prevent);
			if (head)
			{
				tmp = ft_strxstr(values[i], leak_prevent, head->value);
				free(values[i]);
				values[i] = tmp;
			}
			free(leak_prevent);
		}
		i++;
	}
	if (flag == 1)
		data->cmd->exit_status = 0;
	return (values);
}

// char	**ft_command(char *str)
// {
// 	char **values;

// 	values = ft_split(str, ' ');
// 	return (values);
// }

// char	*ft_name(char *str)
// {
// 	char	*name;
// 	char	**values;

// 	name = 0;
// 	if (ft_strchr(str, '='))
// 	{
// 		values = ft_split(str, '=');
// 		name = values[0];
// 		ft_free_split(values);
// 		ft_free_split(values);
// 	}
// 	return (name);
// }

// char	*ft_value(char *str)
// {
// 	char	*value;
// 	char	**values;

// 	value = 0;
// 	if (ft_strchr(str, '='))
// 	{
// 		values = ft_split(str, '=');
// 		value = values[1];
// 		ft_free_split(values);
// 	}
// 	return (value);
// }

void	ft_params(t_data *data, char *str)
{
	int		i;
	int		j;
	int		flag;
	char	*tmp;
	char	*leak_prevent;
	char	**values;
	t_env_node *head;

	if (ft_lstsize(data->parameter) > 0)
		ft_lstclear(&data->parameter, ft_free);
	values = ft_split(str, ' ');
	i = 1;
	while (values[i])
	{
		if (ft_quoted(values[i]))
		{
			tmp = values[i];
			j = i;
			i++;
			while (values[i] && ft_quoted(tmp))
			{
				leak_prevent = ft_strjoin(tmp, " ");
				free(tmp);
				tmp = ft_strjoin(leak_prevent, values[i]);
				free(leak_prevent);
				free(values[i]);
				values[i] = 0;
				i++;
			}
			values[j] = tmp;
			i = j;
		}
		values[i] = ft_replace(values[i]);
		flag = 0;
		if (data->expand == 1)
		{
			while (ft_strstr(values[i], "$?"))
			{
				flag = 1;
				leak_prevent = ft_itoa(data->cmd->exit_status);
				tmp = ft_strxstr(values[i], "$?", leak_prevent);
				free(leak_prevent);
				free(values[i]);
				values[i] = tmp;
			}
			leak_prevent = ft_variable(values[i]);
		}
		else
			leak_prevent = 0;
		if (leak_prevent)
		{
			head = ft_find_node(data->env_list, leak_prevent);
			if (head)
			{
				tmp = ft_strxstr(values[i], leak_prevent, head->value);
				free(values[i]);
				values[i] = tmp;
				data->parameter = ft_add_to_list(data->parameter, values[i]);
			}
			free(leak_prevent);
		}
		else
		{
			data->parameter = ft_add_to_list(data->parameter, values[i]);
		}
		i++;
	}
	if (flag == 1)
		data->cmd->exit_status = 0;
	ft_free_split(values);
}

// void debug(t_data *data)
// {
// 	int		i;
// 	t_list	*nodo;
// 	t_list	*prev;

// 	ft_printf("Número de Comandos: %d\n", ft_lstsize(data->command));
// 	if (ft_lstsize(data->command) == 1)
// 	{
// 		ft_printf("Comando: %s\n", data->command->content);
// 		ft_printf("Commando dividido: %s\n", ft_command(data->command->content)[0]);
// 		ft_params(data, data->command->content);
// 		ft_printf("Número de Parametros: %d\n", ft_lstsize(data->parameter));
// 		if (ft_lstsize(data->parameter) > 0)
// 		{
// 			ft_printf("parametro: %s\n", data->parameter->content);
// 			if (ft_strchr(data->parameter->content, '='))
// 			{
// 				ft_printf("Variable: %s\n", ft_name(data->parameter->content));
// 				ft_printf("Valor: %s\n", ft_value(data->parameter->content));
// 			}
// 		}
// 	}
// 	else
// 	{
// 		nodo = data->command;
// 		while (nodo)
// 		{
// 			ft_printf("Comando: %s\n", nodo->content);
// 			ft_printf("Commando dividido: %s\n", ft_command(nodo->content)[0]);
// 			ft_printf("Commando dividido: %s\n", ft_command(nodo->content)[1]);
// 			ft_params(data, nodo->content);
// 			ft_printf("Número de Parametros: %d\n", ft_lstsize(data->parameter));
// 			if (ft_lstsize(data->parameter) > 0)
// 			{
// 				ft_printf("parametro: %s\n", data->parameter->content);
// 				if (ft_strchr(data->parameter->content, '='))
// 				{
// 					ft_printf("Variable: %s\n", ft_name(data->parameter->content));
// 					ft_printf("Valor: %s\n", ft_value(data->parameter->content));
// 				}
// 			}
// 			prev = ft_previously(data->command, nodo);
// 			if (prev)
// 				ft_printf("Comando anterior: %s\n", prev->content);
// 			nodo = nodo->next;
// 		}
// 	}
// 	i = 0;
// 	while (data->env[i])
// 		ft_printf("env: %s\n", data->env[i++]);
// }

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
		//ft_input_checks(data, values[i]);
		if (ft_quoted(values[i]) && values[i + 1])
		{
			tmp = values[i];
			while (values[++i] && ft_quoted(tmp))
			{
				leak_prevent = ft_strjoin(tmp, "|");
				//free(tmp);
				tmp = ft_strjoin(leak_prevent, values[i]);
				free(leak_prevent);
			}
			i--;
			ft_input_checks(data, tmp);
			data->command = ft_add_to_list(data->command, tmp);
			ft_printf("ok.%s.\n", tmp);
			free(tmp);
		}
		else
		{
			ft_input_checks(data, values[i]);
			data->command = ft_add_to_list(data->command, values[i]);
		}
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
	data->expand = 0;
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
			else if (!str[i + 1])
				flag = 3;
			data->redirection = str[i];
			data->nredirection++;
		}
		else if (ft_checks(str[i], '$') && (flag == 1 || flag == 0))
		{
			data->expand = 1;
			start = i++;
			if (ft_isalpha(str[i]))
			{
				while (ft_isalpha(str[i]))
					i++;				
				i--;
			}
			//else
			//	flag = 3;
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
	{
		data->input_error = 1;
		ft_printf("\033[31;1mSyntax Error\n\033[0m");
	}
}


void	ft_minishell(t_data *data)
{
	char	*leak_prevent;

	while (1)
	{
		data->input = readline("\033[32;1mMinishell> \033[0m");
		if (!data->input)
		{
			// para Ctrl-D, salir del shell
			ft_control_d(data);
		}
		if (data->input[0] == '\0')
		{
			// Si la entrada está vacía o es solo un salto de línea, continuar con la siguiente iteración del bucle
			free(data->input);
			continue;
		}
		if (data->input)
		{
			add_history(data->input);
			ft_pipes(data, data->input);
			//ft_input_checks(data, data->command->content);
			if (data->input_error == 1)
			{
				// Si la entrada tiene error, continuar con la siguiente iteración del bucle
				data->input_error = 0;
				free(data->input);
				ft_lstclear(&data->command, ft_free);
				continue;
			}
			//ft_params(data, data->command->content);
			//ft_redirections_pars(data);
			//debug(data);

			// if (data->input[ft_strlen(data->input) - 1] == '\n')
			// {
			// 	data->input[ft_strlen(data->input) - 1] = '\0';
			// }

			data->cmd->env_copy = ft_list_to_matrix(data->env_list); //converte la lista de env en matriz
			leak_prevent = ft_strtrim(data->input, " ");

			if(ft_not_redirected_builtins(data) == 1)
				ft_execute_not_rebuiltins(data);
			else if (ft_strlen(leak_prevent) > 0)
				ft_execute(data);
			free(leak_prevent);
			ft_free_matrix(data->cmd->env_copy);
		}
		//ft_free_matrix(data->cmd->cmd_splited);
		//tengo que liberar la estructura de cmd
		ft_lstclear(&data->command, ft_free);
		ft_lstclear(&data->parameter, ft_free);
		free(data->input);
	}
}
