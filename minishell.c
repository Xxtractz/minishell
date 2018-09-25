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

static void 	do_echo(char **arg)
{
	int		i;
	int		k;
	int		count;

	i = 0;
	k = 1;
	count = 0;
	while (arg[count] != '\0')
		count++;
	while (arg[k] != '\0')
	{
		while (arg[k][i] != '\0')
		{
			if(arg[k][i] == '\"')
				i++;
			if(arg[k][i] == '\0')
				break;
			ft_putchar(arg[k][i]);
			i++;
		}
		i = 0;
		if (k != count)
			ft_putchar(' ');
		k++;
	}
	ft_putchar('\n');
}

static void	do_env(char **env)
{
	int		i;

	i = 0;
	while (env[i] != '\0')
	{
		ft_printf("%s\n", env[i]);
	 	i++;
	}
	free(env);
}

int		ft_last_path(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return(i);
	free(str);
}

void	ft_current_dir(void)
{
	char	*path;
	char	**pathreal;
	int		last;

	path = NULL;
	path = getcwd(path, sizeof(path));
	pathreal = ft_strsplit(path, '/');
	last = ft_last_path(pathreal);
	ft_printf("%s[ %s ]%s%s[$➜] %s", GREEN, 
		pathreal[last - 1], RESET, RED, RESET);
	free(path);
	free(pathreal);
}

void	do_exit(char **arg)
{
	free(arg);
	exit(0);	
}

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
		ft_current_dir();
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
				do_echo(arg);
			// else if (ft_strcmp(arg[i], "cd"))
			// 	do_cd(arg, env);
			// else if (ft_strcmp(arg[i], "setenv"))
			// 	do_setenv(arg, env);
			// else if (ft_strcmp(arg[i], "unsetenv"))
			// 	do_unsetenv(arg, env);
			else if (ft_strcmp(arg[i], "env") == 0)
			 	do_env(env);
			else if (ft_strcmp(arg[0], "exit") == 0)
			 	do_exit(arg);
			// else
			// 	ft_printf("%s\n", arg[i]);
			i++;
		}
		i = 0;
	}
	return (0);
}