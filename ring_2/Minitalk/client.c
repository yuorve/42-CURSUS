/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 08:38:19 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/11 16:14:13 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int 	i;
	i = 0;
	// void de argumentos no utilizados
	(void)context;
	(void)info;
	if (sig == SIGUSR2) i++;
    	else if (sig == SIGUSR1) exit(0);
}

void ft_sendmsg(int pid, char c) {
	int  i;

	i = 7;	
	while(i >= 0)
	{
		if ((c >> i) & 1) {
			if (kill(pid, SIGUSR1) == -1) {
				exit(ft_printf("Error: Fallo al enviar la señal USR1\n"));
			}	
		} else {			
			if (kill(pid, SIGUSR2) == -1) {
				exit(ft_printf("Error: Fallo al enviar la señal USR2\n"));
			}			
		}
		i--;
		usleep(50);
	}
}

int main(int argc, char **argv) {
	struct sigaction    sa;	
	int 				pid_server;
	int     			i;
	char 			   *str;

	// Comprobar que los argumentos son correctos        
	if (argc == 3)
	{
		// Inicializar la estructura
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = ft_handler;
		sigemptyset(&sa.sa_mask);
		// Configurar la estructura sigaction para manejar la señal SIGUSR1
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			return (ft_printf("Error: Fallo al configurar el controlador de señales USR1\n"));
		// Configurar la estructura sigaction para manejar la señal SIGUSR2
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			return (ft_printf("Error: Fallo al configurar el controlador de señales USR2\n"));		
		ft_printf("Cliente iniciado\n");
		// Obtener el PID del servidor del argv[1]
		pid_server = ft_atoi(argv[1]);
		ft_printf("Enviando mensaje al servidor: %d\n", pid_server);
		// Obtener el mensaje del argv[2]
		str = argv[2];
		ft_printf("Mensaje: %s\n", str);
		i = 0;
		while (str[i] != '\0')
		{			
			ft_sendmsg(pid_server, str[i]);
			i++;
		}
		// Fin del mensaje
		ft_sendmsg(pid_server, '\0');
		// Esperar la respuesta del servidor
		while (1)
			pause();
	}
	else        
		return (ft_printf("Error: Faltan argumentos\n"));
	return (0);
}
