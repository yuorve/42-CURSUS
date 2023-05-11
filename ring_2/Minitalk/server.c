/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 08:25:49 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/11 18:52:40 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int 	i;
	static int	pid_client;
	static char c;

	// void al argumento no utilizado
	(void)context;
	pid_client = info->si_pid;	
	// Verificar que la señal recibida sea SIGUSR1 o SIGUSR2
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c <<= 1;
	// Incrementar el índice para el siguiente bit
	i++;
	// Si se han recibido los 8 bits de un caracter, mostrarlo y reiniciar las variables
	if (i == 8)
	{
		// Si es el fin del mensaje termina la comunicación
		if (c == '\0') {
			ft_printf("\n", c);		
			kill(pid_client, SIGUSR1);
		}
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}

	// Enviar una señal de confirmación al cliente
	kill(pid_client, SIGUSR2);
}

int	main(void) {
	struct sigaction    sa;
	int 				pid_server;

	// Inicializar la estructura
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	// Configurar la estructura sigaction para manejar la señal SIGUSR1
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_printf("Error: Fallo al configurar el controlador de señales\n"));
	// Configurar la estructura sigaction para manejar la señal SIGUSR2
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("Error: Fallo al configurar el controlador de señales\n"));
	// Muestra el PID del servidor
	pid_server = getpid();
	ft_printf("Servidor iniciado\n");
	ft_printf("PID: %d\n", pid_server);
	ft_printf("Esperando mensajes...\n");
	// Esperar el mensaje del cliente
	while (1) 
		pause();
	return (0);
}
