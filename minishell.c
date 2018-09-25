/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/09/13 11:16:29 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int	main(int ac, char **av, char **envp)
{
	char	*input;
	char	**arg;
	char	*path;
	int		i;
	int		j;
	char	**env;

	i = 0;
	j = 0;
	env = envp;
	path = NULL;
	(void)(ac && av);
	while (1)
	{
		ft_input();
		input = NULL;
		get_next_line(0, &input);
		arg = ft_strsplit(input, ' ');
		free(input);
		while (arg[i] != '\0')
		{
			if (ft_strcmp(arg[0], "pwd") == 0)
			{	
				path = getcwd(path, sizeof(path));
				ft_printf("%s\n", path);
				free(path);
			}
			else if (ft_strcmp(arg[i], "echo") == 0)
				do_echo(arg, env);
			// else if (ft_strcmp(arg[i], "cd"))
			//  	do_cd(arg, env);
			// else if (ft_strcmp(arg[i], "setenv"))
			// 	do_setenv(arg, env);
			// else if (ft_strcmp(arg[i], "unsetenv"))
			// 	do_unsetenv(arg, env);
			else if (ft_strcmp(arg[i], "env") == 0)
			 	do_env(env);
			else if (ft_strcmp(arg[i], "exit") == 0)
			 	do_exit(arg);
			// else
			// 	ft_printf("%s\n", arg[i]);
			i++;
		}
		i = 0;
	}
	return (0);
}