/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 07:38:40 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/17 07:44:48 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void tokenize(char *str) {
    int inside_quotes = 0;
    int pipes = 0;
    int infile = 0;
    int outfile = 0;
    char quote_type = '\0';

    while (*str != '\0') {
        // Ignorar espacios al inicio
        while (*str == ' ') {
            str++;
        }

        // Verificar si encontramos comillas y cambiar el estado
        if (*str == '\"' || *str == '\'') {
            inside_quotes = !inside_quotes;
            quote_type = *str;
            str++;
        }
        
        // Verificar si encontramos pipes y contabilizar el número
        if (*str == '|') {
            pipes++;
            str++;
        }
        
        // Verificar si encontramos redireccionador infile y extraer el filename
        if (*str == '<') {
            infile = !infile;
            str++;
            printf("infile:");
            while (*str != ' ' && *str != '>' && *str != '<' && *str != '|' && *str != '\"' && *str != '\'' && *str != '\0') {
                printf("%c", *str);
                str++;
            }
        }
        
        // Verificar si encontramos redireccionador outfile y extraer el filename
        if (*str == '>') {
            outfile = !outfile;
            str++;
            printf("outfile:");
            while (*str != ' ' && *str != '>' && *str != '<' && *str != '|' && *str != '\"' && *str != '\'' && *str != '\0') {
                printf("%c", *str);
                str++;
            }
        }
        
        if (!inside_quotes) {
            while (*str != ' ' && *str != '>' && *str != '<' && *str != '|' && *str != '\"' && *str != '\'' && *str != '\0') {
                printf("%c", *str);
                str++;
            }
            printf("\n");
        } else {
            while (*str != quote_type && *str != '\0') {
                printf("%c", *str);
                str++;
            }
            printf("\n");
            if (*str == quote_type) {
                str++;
                inside_quotes = 0;
            }
        }
    }
}

int main() {
    char str[] = "Este ><> es < un \"ejemplo | d<e 'cadena\" con 'comillas simples'";
    tokenize(str);

    return 0;
}
