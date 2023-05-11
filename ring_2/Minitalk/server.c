/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 08:25:49 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/11 08:10:10 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int 	i;
	static char c;

	// void al argumento no utilizado
	(void)context;
	// Verificar que la señal recibida sea SIGUSR1 o SIGUSR2
	if (sig == SIGUSR1)
		c |= (1 << i);		
	else if (sig == SIGUSR2)
		c |= (0 << i);
	// Incrementar el índice para el siguiente bit
	i++;
	// Si se han recibido los 8 bits de un caracter, mostrarlo y reiniciar la estructura de datos
	if (i == 8)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}

	// Enviar una señal de confirmación al cliente
	kill(info->si_pid, SIGUSR1);
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
	// Esperar el mensaje del cliente
	while (1) 
		pause();
	return (0);
}
