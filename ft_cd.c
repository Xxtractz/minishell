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

static char	*ft_home(char **env)
{
	char	**split;
	char	*result;
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		split = ft_strsplit(env[i], '=');
		if (ft_strcmp(split[0], "HOME") == 0)
		{
			result = ft_strdup(split[1]);
			ft_free_double(split);
			return (result);
		}
		ft_free_double(split);
		i++;
	}
	return (NULL);
}

static char	*ft_oldpwd(char **env)
{
	char	**split;
	char	*result;
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		split = ft_strsplit(env[i], '=');
		if (ft_strcmp(split[0], "OLDPWD") == 0)
		{
			result = ft_strdup(split[1]);
			ft_free_double(split);
			return (result);
		}
		ft_free_double(split);
		i++;
	}
	return (NULL);
}

static int	ft_is_dir(char *dir)
{
	struct stat		s_is;

	if (lstat(dir, &s_is) < 0)
	{
		ft_printf("cd: no such file or directory: %s\n", dir);
		return (0);
	}
	return ((s_is.st_mode & S_IFDIR) ? 1 : 0);
}

static void	ft_update_dir_var(char ***env, char *key)
{
	char	*args[3];
	char	*cwd = getcwd(NULL, 0);
	args[0]	= "setenv";
	args[1] = key;
	args[2] = cwd;
	do_setenv((char **)args, env);
	free(cwd);
}

void	do_cd(char **arg, char ***env)
{
	char	*home = ft_home(*env);
	char	*oldpwd = ft_oldpwd(*env);
	ft_update_dir_var(env, "OLDPWD");
	if (!arg[1] || (ft_strcmp(arg[1], "~") == 0) ||
		(ft_strcmp(arg[1], "--") == 0) ||
		(ft_strcmp(arg[1], "$HOME") == 0))
		chdir(home);
	else if ((ft_strcmp(arg[1], "-") == 0) ||
		(ft_strcmp(arg[1], "$OLDPWD") == 0))
		chdir(oldpwd);
	else if (ft_is_dir(arg[1]))
		chdir(arg[1]);
	else
		ft_printf("cd: no such file or directory: %s\n", arg[1]);
	free(home);
	free(oldpwd);
	ft_update_dir_var(env, "PWD");
}
