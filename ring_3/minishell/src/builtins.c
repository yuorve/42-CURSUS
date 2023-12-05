/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:23:41 by angalsty          #+#    #+#             */
/*   Updated: 2023/12/05 12:51:20 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int ft_pwd(void)
{
    char *pwd;

    pwd = getcwd(NULL, 0);
    if (pwd == NULL) 
    {
        perror("Error al obtener el directorio de trabajo actual");
        return 1;
    }
    printf("%s\n", pwd);
    free(pwd);
    return (0);
}


int ft_chdir(const char *path) 
{
    if (chdir(path) != 0) 
    {
        perror("Error al cambiar el directorio");
        return (1); 
    }
    return (0); 
}

// char *ft_get_value(char *str, char **env)
// {
//     int i = 0;
//     if (!str)
//         return (NULL);
//     while (env[i])
//     {
//         if (ft_strncmp(str, env[i], ft_strlen(str)) == 0)
//         {
//             if (ft_strlen(env[i]) == ft_strlen(str))
//                 return (env[i] + ft_strlen(str));
//             else if (env[i][ft_strlen(str)] == '=')
//                 return (env[i] + ft_strlen(str) + 1);
//         }
//         i++;
//     }
//     return (0);
// }

// int ft_change_env(char *name, char *new_value, t_command *command)
// {
//     int i;

//     i = 0;
//     while(command->env[i] != NULL)
//     {
//         if (ft_strncmp(command->env[i], name, ft_strlen(name)) == 0)
//         {
//             printf("the name already exists\n");
//             free(command->env[i]);
//             command->env[i] = ft_strjoin(name, new_value);
//             return (1);
//         }
//         i++;
//     }
//     return(0);
// }

int ft_cd(t_data *data)
{
    const char *path;
    int result;
    //char *home_dir = getenv("HOME");

    if (ft_strncmp(data->command->content, "cd", 2) == 0) 
    {
        // if (data->command->content == '\0') 
        // {
        //     //home_dir = getcwd(NULL, 0);
        //     //tengo que añadir una line de "OLDPWD=" con el valor de PWD
        //     //ft_change_env("OLDPWD=", ft_get_value("PWD", command->env), command);
            
        //     if (home_dir) 
        //     {
        //         result = ft_chdir(home_dir);
        //     } 
        //     else 
        //     {
        //         // No se pudo obtener el directorio de inicio, maneja el error
        //     }
            
        //     // El usuario solo escribió "cd" sin una ruta, puedes manejarlo como desees
        // } 
        // else if (command->cmd_txt[2] == ' ' && command->cmd_txt[3] == '-')
        // {
            
        // }
        // else 
        // {
            // El usuario proporcionó una ruta, como "cd /ruta/deseada"
            // Debes extraer la ruta y pasarla a ft_cd
            path = data->parameter->content + 3; 
            // La ruta comienza después de "cd "
            result = ft_chdir(path);
            printf("result: %d\n", result);
            if (result == 0) 
            {
                // Cambio de directorio exitoso
            } 
            else 
            {
                // Error al cambiar de directorio, manejar el error
            }
        }
    

    return (0);

}


int ft_exit(void) 
{
    // while(&data->parameter->content)
    // {
    //     if (ft_isdigit(ft_atoi(&data->parameter->content)) == 0)
    //     {
    //         printf("minishell: exit: %s: numeric argument required\n", &data->parameter->content);
    //         exit(255);
    //     }
    //     *data->parameter->content++;
    // }
    exit(0); // Salir del shell con código de éxito
}

int ft_env(t_data *data)
{
    t_env_node *head;
    
    head = data->env_list;
    while(head)
    {
        if(head->name != NULL && head->value != NULL && strlen(head->value) > 0)
        {
            printf("%s=%s\n", head->name, head->value);
        }
        head = head->next;
    }
    return (0);
}

void ft_swap_values(char **str1, char **str2) 
{
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void ft_sort_env_list(t_env_node **head) 
{
    int swapped = 0;
    t_env_node *ptr;
    t_env_node *last; 

    last = NULL;
    if (*head == NULL) 
    {
        return;
    }

    while (!swapped) {
        swapped = 1;
        ptr = *head;

        while (ptr->next != last) 
        {
            if (ft_strcmp(ptr->name, ptr->next->name) > 0) 
            {
                ft_swap_values(&ptr->name, &ptr->next->name);
                ft_swap_values(&ptr->value, &ptr->next->value);
                swapped = 0;
            }
            ptr = ptr->next;
        }
        last = ptr;
    }
}

void ft_print_sorted_env(t_env_node *head) 
{
    t_env_node *temp = head;
    // Crear una copia temporal para ordenar
    t_env_node *sorted_env = NULL;
    while (temp) 
    {
        ft_push_env_node(&sorted_env, temp->name, temp->value);
        temp = temp->next;
    }

    // Ordenar la lista de entorno temporal
    ft_sort_env_list(&sorted_env);

    // Imprimir la lista ordenada
    temp = sorted_env;
    while (temp) 
    {
        if (temp->name != NULL && temp->value != NULL) 
        {
            printf("declare -x %s=\"%s\"\n", temp->name, temp->value);
        }
        temp = temp->next;
    }

    // Liberar la memoria de la lista temporal
    while (sorted_env) 
    {
        temp = sorted_env;
        sorted_env = sorted_env->next;
        free(temp->name);
        free(temp->value);
        free(temp);
    }
}

int ft_unset(t_data *data) 
{
    t_env_node *current;
    t_env_node *prev;
    char *name;

    name = data->parameter->content;
    prev = NULL;
    current = data->env_list;
    while (current != NULL) 
    {
        if (ft_strchr(name, '=') != NULL) 
        {
            // Si el nombre de unset tiene un '=', 
            // no se puede eliminar
            printf("minishell: unset: `%s': not a valid identifier\n", name);
            return (1);
        }
        if (ft_strcmp(current->name, name) == 0) 
        {
            if (prev == NULL) 
            {
                data->env_list = current->next; // Si el nodo a eliminar es el primero
            } 
            else 
            {
                prev->next = current->next;
            }
            free(current->name);
            free(current->value);
            free(current);
            return (0); // Éxito al eliminar la variable de entorno
        }
        prev = current;
        current = current->next;
    }
    return (0); // Si la variable de entorno no se encuentra
}

int    ft_check_export_errors(t_data *data)
{
    t_list *parameter;

    parameter = data->parameter;
    while(parameter)
    {
        //compruebo
        data->cmd->param = parameter->content;
        printf("parameter: %s\n", parameter->content);
        if(ft_isalpha(data->cmd->param[0]) == 0 && data->cmd->param[0] != '_')
        {
            printf("minishell: export: `%s': not a valid identifier\n", data->cmd->param);
            return(1);
        }
        parameter = parameter->next;
    }
    return(0);
}


int ft_export(t_data *data) 
{
    if (data->parameter == NULL && (data->cmd->command[6] == ' ' || data->cmd->command[6] == '\0'))
    {
        ft_print_sorted_env(data->env_list);
    }
    else if (data->cmd->command[6] != ' ')
    {
        printf("minishell: %s: command not found\n", data->cmd->command);
        return (1);
    }
    else 
    {
        if  (ft_check_export_errors(data) == 0)
        {
            while (data->parameter) 
            {
                char *param_content = data->parameter->content;
                char *name = param_content;
                char *value = ft_strchr(param_content, '=');

                if (value != NULL) 
                {
                    *value = '\0'; // Coloca '\0' para dividir nombre y valor
                    value++; // Apunta al comienzo del valor (después del '=')
                } 
                else 
                {
                    value = ""; // Si no hay '=', establece un valor vacío
                }

                // Check if the variable exists in the current environment list
                t_env_node *current = data->env_list;
                int found = 0;
                while (current) 
                {
                    if (ft_strcmp(current->name, name) == 0) 
                    {
                        // Variable exists, update its value
                        free(current->value);
                        current->value = ft_strdup(value);
                        found = 1;
                        break;
                    }
                    current = current->next;
                }

                // If the variable doesn't exist, add it to the environment list
                if (!found) 
                {
                    ft_push_env_node(&data->env_list, name, value);
                }
                data->parameter = data->parameter->next;
            }
        }
    }
    // free(data->cmd->param);
    return (0);
}


int ft_execute_not_rebuiltins(t_data *data)
{
//    if (ft_strncmp(data->command, "cd", 2) == 0)
        
//         {
//             //printf("cd\n");
//             //return (1);
//             return (ft_cd(data));
//         }
     if (ft_strncmp(data->command->content, "export", 6) == 0)
        {
            return (ft_export(data));
        }
    else if (ft_strncmp(data->command->content, "unset", 5) == 0)
        {
            return (ft_unset(data));
        }
    else if (ft_strncmp(data->command->content, "pwd", 3) == 0)
    {
        return (ft_pwd());
    }
    else if (ft_strncmp(data->command->content, "exit", 4) == 0)
    {
        
            return (ft_exit());
        // else 
        // {
        //     printf("minishell: exit: too many arguments\n");
        //     return (ft_exit());
        // }
    // printf("exit\n");
    // return (1);
    }
    else if (ft_strncmp(data->command->content, "env", 3) == 0)
    {
        return (ft_env(data));
    }
    else
        return (0);
}

// int ft_execute_rebuiltins(t_data *data)
// {
//     if (ft_strncmp(data->command->content, "echo", 4) == 0)
//        {
//         printf("echo\n");
//         return (1);
//         //return (ft_echo(command));
//        }
//     else if (ft_strncmp(data->command->content, "pwd", 3) == 0)
//         return (ft_pwd());
//     // else if (ft_strncmp(command->cmd_txt, "env", 3) == 0)
//     //     {
//     //         return (ft_env(command));
//     //     }
//     else
//         return (0);
// }

int ft_not_redirected_builtins(t_data *data)
{
    //data->cmd->command = ft_strjoin(data->command->content, " ");
    data->cmd->command = data->command->content;
    ft_params(data, data->command->content);
    
    // if (ft_strncmp(data->command, "cd", 2) == 0)
    //     return (1);
    //if (ft_strncmp(data->command->content, "export", 6) == 0)
    if(ft_strncmp(data->cmd->command, "export", 6) == 0)
    {
        return (1);
    }
    else if (ft_strncmp(data->command->content, "unset", 5) == 0)
        return (1);
    //else if (ft_strncmp(data->command->content, "exit", 4) == 0 && data->parameter != NULL)
    else if(ft_strncmp(data->command->content, "exit", 4) == 0)   
        return (1);
        //tengo que cambiar env y pwd a redirected builtins
    else if (ft_strncmp(data->command->content, "env", 3) == 0)
        return (1);
    //else if (ft_strncmp(data->command->content, "pwd", 3) == 0 && (data->command + 1 == NULL || data->parameter != NULL))
    else if (ft_strncmp(data->command->content, "pwd", 3) == 0)
        return (1);
    return (0);
}

// int ft_is_redirected_builtins(t_data *data)
// {
//     if (ft_strncmp(data->command->content, "echo", 4) == 0)
//         return (1);
//     //else if (ft_strncmp(data->command, "pwd", 3) == 0)
//     //    return (1);
//     // else if (ft_strncmp(data->command, "env", 3) == 0)
//     //     return (1);
//     return (0);  
// }