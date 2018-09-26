/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/09/13 11:16:29 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void	ft_home(char **env)
{
	char 	**home;
	int		i;

	i = 0;
	while(env[i] != '\0')
	{
		home = ft_strsplit(env[i], '=');
		if (ft_strcmp(home[0], "HOME") == 0)
			chdir(home[1]);
		i++;
	}
}

void	do_cd(char **arg, char **env)
{
	// char 	*cwd;
	// char	*old;
	// struct stat s_st;

	if ((ft_strcmp(arg[1], "~") == 0) || 
		(ft_strcmp(arg[1], "--") == 0) || (ft_strcmp(arg[1], "$HOME" ) == 0))
		ft_home(env);
	// else if (lstat(arg[1] ,&s_st) >= 0)
	// 	chdir(arg[1]);
	else 
		ft_printf("cd: no such file or directory: %s\n", arg[1]);

}