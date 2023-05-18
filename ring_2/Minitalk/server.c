/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 08:25:49 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/18 09:17:41 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Función para manejar las señales recibidas
// Lo primero es void al argumento no utilizado
// Luego verificar que la señal recibida sea SIGUSR1 o SIGUSR2
// Si es SIGUSR1 añado el bit en 1 sino en 0
// Incrementar el índice para el siguiente bit
// Si se han recibido los 8 bits, mostrarlo
// Si es el fin del mensaje termino la comunicación
// Al final enviar una señal de confirmación al cliente
void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static int	pid_client;
	static char	c;

	(void)context;
	pid_client = info->si_pid;
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c <<= 1;
	i++;	
	if (i == 8)
	{		
		if (c == '\0')
		{
			ft_printf("\n", c);		
			kill(pid_client, SIGUSR1);
		}
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}	
	kill(pid_client, SIGUSR2);
}

// Lo primero es inicializar la estructura del sigaction
// La  llamada  al  sistema  sigaction  se emplea para cambiar la acción 
// tomada por un proceso cuando recibe una determinada señal.
// Hay que configurar sigaction para manejar la señal SIGUSR1 y SIGUSR2
// Mostrar el PID del servidor
// Esperar el mensaje del cliente
int	main(void) {
	struct sigaction	sa;
	int					pid_server;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_printf("Error: Fallo config USR1\n"));	
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("Error: Fallo config USR2\n"));	
	pid_server = getpid();
	ft_printf("Servidor iniciado\n");
	ft_printf("PID: %d\n", pid_server);
	ft_printf("Esperando mensajes...\n");
	while (1) 
		pause();
	return (0);
}
