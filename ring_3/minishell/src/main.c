#include "../inc/minishell.h"


void	ft_void(void)
{
	system("leaks -q 'minishell'");
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	//char	*input;

	atexit(ft_void);
	(void) argc;
	(void) argv;
	//using_history();
	set_signal(); //signals set to start
	ft_bzero(&data, sizeof(t_data));
	ft_init(&data, env);
    ft_minishell(&data);
	
	
	//ft_free_matrix(data.env_list);
	//ft_free_matrix(data.cmd->cmd_complete);
	clear_history();
	return (0);
}
