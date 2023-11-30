/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:23:41 by angalsty          #+#    #+#             */
/*   Updated: 2023/11/30 18:47:39 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int ft_pwd(void)
{
    char *pwd;

    pwd = getcwd(NULL, 0);
    if (pwd == NULL) {
        perror("Error al obtener el directorio de trabajo actual");
        return 1;
    }
    printf("%s\n", pwd);
    free(pwd);
    return (0);
}


// int ft_chdir(const char *path) 
// {
//     if (chdir(path) != 0) 
//     {
//         perror("Error al cambiar el directorio");
//         return (1); 
//     }
//     return (0); 
// }

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

// int ft_cd(t_data *data)
// {
//     const char *path;
//     int result;
//     char *home_dir = getenv("HOME");

//     if (ft_strncmp(data->command, "cd", 2) == 0) 
//     {
//         if (command->cmd_txt[2] == '\0') 
//         {
//             //home_dir = getcwd(NULL, 0);
//             //tengo que añadir una line de "OLDPWD=" con el valor de PWD
//             //ft_change_env("OLDPWD=", ft_get_value("PWD", command->env), command);
            
//             if (home_dir) 
//             {
//                 result = ft_chdir(home_dir);
//             } 
//             else 
//             {
//                 // No se pudo obtener el directorio de inicio, maneja el error
//             }
            
//             // El usuario solo escribió "cd" sin una ruta, puedes manejarlo como desees
//         } 
//         else if (command->cmd_txt[2] == ' ' && command->cmd_txt[3] == '-')
//         {
            
//         }
//         else 
//         {
//             // El usuario proporcionó una ruta, como "cd /ruta/deseada"
//             // Debes extraer la ruta y pasarla a ft_cd
//             path = &command->cmd_txt[3]; 
//             // La ruta comienza después de "cd "
//             result = ft_chdir(path);
//             printf("result: %d\n", result);
//             if (result == 0) 
//             {
//                 // Cambio de directorio exitoso
//             } 
//             else 
//             {
//                 // Error al cambiar de directorio, manejar el error
//             }
//         }
//     }

//     return (0);

// }

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
        if(head->name != NULL && head->value != NULL)
        {
            printf("%s=%s\n", head->name, head->value);
        }
        head = head->next;
    }
    return (0);
}

void ft_sort_env_list(t_env_node **head) 
{
    int swapped = 0;
    t_env_node *ptr;
    t_env_node *last = NULL;

    if (*head == NULL) {
        return;
    }

    while (!swapped) {
        swapped = 1;
        ptr = *head;

        while (ptr->next != last) 
        {
            if (strcasecmp(ptr->name, ptr->next->name) > 0) 
            {
                char *temp_name = ptr->name;
                char *temp_value = ptr->value;

                ptr->name = ptr->next->name;
                ptr->value = ptr->next->value;

                ptr->next->name = temp_name;
                ptr->next->value = temp_value;

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


int ft_export(t_data *data)
{
    if(data->parameter == NULL)
    {
        ft_print_sorted_env(data->env_list);
    }
    else
    {
        while(data->parameter)
        {
            if(ft_strchr(data->parameter->content, '='))
            {
                char *name = ft_strchr(data->parameter->content, '=');
                *name = '\0';
                name = data->parameter->content;
                char *value = name + ft_strlen(name) + 1;
                ft_push_env_node(&data->env_list, name, value);
            }
            else
                ft_push_env_node(&data->env_list, data->parameter->content, "");
            data->parameter = data->parameter->next;
        }
    }

    // if (data->parameter == NULL) 
    // {
    //     t_env_node *head;
    //     t_env_node *temp;
    //     // If no parameters provided, sort and print the environment list
    //     head = data->env_list;
    //     temp = data->env_list;
    //     sort_env_list(&temp);
    //     while (temp) 
    //     {
    //         if (temp->name != NULL && temp->value != NULL) 
    //         {
    //             printf("declare -x %s=\"%s\"\n", temp->name, temp->value);
    //         }
    //         temp = temp->next;
    //     }
    //     temp = head;
    //     return (0);
    // }
    // int i;
    // char *name;
    // char *value;
    // t_env_node *head;

    // i = 0;
    // head = data->env_list;
    // while (data->parameter)
    // {
    //     if (ft_strchr(data->parameter->content, '='))
    //     {
    //         name = ft_strchr(data->parameter->content, '=');
    //         *name = '\0';
    //         name = data->parameter->content;
    //         value = name + ft_strlen(name) + 1;
    //         ft_push_env_node(&head, name, value);
    //     }
    //     else
    //         ft_push_env_node(&head, data->parameter->content, "");
    //     data->parameter = data->parameter->next;
    // }
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
            //printf("export\n");
            //return (1);
        }
//     else if (ft_strncmp(data->command, "unset", 5) == 0)
//         {
//             //return (ft_unset(command));
//             printf("unset\n");
//             return (1);
//         }
    else if (ft_strncmp(data->command->content, "pwd", 3) == 0)
    {
        return (ft_pwd());
        // printf("pwd\n");
        // return (1);
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
    // if (ft_strncmp(data->command, "cd", 2) == 0)
    //     return (1);
    if (ft_strncmp(data->command->content, "export", 6) == 0)
    {
        return (1);
    }
    // else if (ft_strncmp(data->command, "unset", 5) == 0)
    //     return (1);
    //else if (ft_strncmp(data->command->content, "exit", 4) == 0 && data->parameter != NULL)
    else if(ft_strncmp(data->command->content, "exit", 4) == 0)   
        return (1);
        //tengo que cambiar env y pwd a redirected builtins
    else if (ft_strncmp(data->command->content, "env", 3) == 0)
        return (1);
    else if (ft_strncmp(data->command->content, "pwd", 3) == 0 && (data->command + 1 == NULL || data->parameter != NULL))
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