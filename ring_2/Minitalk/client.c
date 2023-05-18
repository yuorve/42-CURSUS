/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 08:38:19 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/18 08:17:00 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	i = 0;
	(void)context;
	(void)info;
	if (sig == SIGUSR2) i++;
    	else if (sig == SIGUSR1) 
			exit(0);
}

void ft_sendmsg(int pid, char c) {
	int	i;

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

// Obtener el PID del servidor del argv[1]
// Obtener el mensaje del argv[2]
// Enviar el mensaje y un final del mensaje
// Esperar la respuesta del servidor
int main(int argc, char **argv) {
	struct sigaction	sa;	
	int 				pid_server;
	int					i;
	char 				*str;

	if (argc == 3)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = ft_handler;
		sigemptyset(&sa.sa_mask);
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			return (ft_printf("Error: Fallo config USR1\n"));
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			return (ft_printf("Error: Fallo config USR2\n"));
		pid_server = ft_atoi(argv[1]);
		ft_printf("Enviando mensaje al servidor: %d\n", pid_server);
		str = argv[2];
		i = 0;
		while (str[i] != '\0') 
			ft_sendmsg(pid_server, str[i++]);
		ft_sendmsg(pid_server, '\0');
		while (1)
			pause();
	} 
	else
		return (ft_printf("Error: Faltan argumentos\n"));
	return (0);
}
