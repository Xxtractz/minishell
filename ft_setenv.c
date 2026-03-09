/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/09/13 11:16:29 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char	*ft_build_entry(char **arg, int num_arg)
{
	char	*tmp;
	char	*entry;

	tmp = ft_strjoin(arg[1], "=");
	if (num_arg == 3)
	{
		entry = ft_strjoin(tmp, arg[2]);
		free(tmp);
	}
	else
		entry = tmp;
	return (entry);
}

static char	**set_new_env(char **env, char **arg, int num_arg)
{
	char	**new;
	int		count;
	int		i;

	i = 0;
	count = ft_strlen_double(env);
	new = (char **)malloc(sizeof(char *) * (count + 2));
	if (!new)
		return (NULL);
	while (i < count)
	{
		new[i] = env[i];
		i++;
	}
	new[i] = ft_build_entry(arg, num_arg);
	new[i + 1] = NULL;
	free(env);
	return (new);
}

static void	ft_set_existing(char ***env, char **arg, int i, int count)
{
	char	*tmp;

	free((*env)[i]);
	if (count == 3)
	{
		tmp = ft_strjoin(arg[1], "=");
		(*env)[i] = ft_strjoin(tmp, arg[2]);
		free(tmp);
	}
	else
		(*env)[i] = ft_strjoin(arg[1], "=");
}

static int	ft_find_var(char ***env, char **arg, int count)
{
	char	**env_var;
	int		i;

	i = 0;
	while ((*env)[i] != NULL)
	{
		env_var = ft_strsplit((*env)[i], '=');
		if (ft_strcmp(arg[1], env_var[0]) == 0)
		{
			ft_set_existing(env, arg, i, count);
			ft_free_double(env_var);
			return (i);
		}
		ft_free_double(env_var);
		i++;
	}
	return (i);
}

void	do_setenv(char **arg, char ***env)
{
	int		env_count;
	int		count;
	int		i;

	count = 0;
	env_count = 0;
	while (arg[count] != NULL)
		count++;
	while ((*env)[env_count] != NULL)
		env_count++;
	if (count == 1)
	{
		do_env(*env);
		return ;
	}
	if (count > 3)
		ft_printf("setenv: too many arguements\n");
	if (count > 1 && count < 4)
	{
		i = ft_find_var(env, arg, count);
		if (i == env_count)
			*env = set_new_env(*env, arg, count);
	}
}
