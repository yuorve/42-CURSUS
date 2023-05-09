/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 08:38:19 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/09 11:55:15 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/inc/libft.h"

void ft_sendmsg(int sig, char c) {
	int  i;

	i = 0;
	while(i < 8)
	{
		if (c & (1 << i)) {
			if (kill(pid, SIGUSR1) == -1) {
				exit(ft_printf("Error: Fallo al enviar la señal del bit 0\n"));
			}
		} else {
			if (kill(pid, SIGUSR2) == -1) {
				exit(ft_printf("Error: Fallo al enviar la señal del bit 1\n"));
			}
		}
		j++;
		usleep(50);
	}
	// Envia un byte nulo al final del mensaje
	i = 0;
	while (i < 8) {
		if (kill(pid, SIGUSR1) == -1) {
			exit(ft_printf("Error: Fallo al enviar la señal del bit 0\n"));
		}
		i++;
		usleep(50);
	}
	return (0);
}

int main(int argc, char **argv) {
	int 	pid_server;
	int     i;
	char    *str;

	// Comprobar que los argumentos son correctos        
	if (argc == 3)
	{
		ft_printf("Cliente iniciado\n");
		// Obtener el PID del servidor del argv[2]
		pid_server = ft_atoi(argv[1]);
		str = argv[2];
		i = 0;
		while (str[i] != '\0')
		{
			ft_sendmsg(pid, str[i]);
			i++;
		}
		ft_handler(pid, '\0');
		// Esperar la respuesta del servidor
		while (1)
			pause();
	}
	else        
		return (ft_printf("Error: Faltan argumentos\n"));
	return (0);
}
