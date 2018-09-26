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

static int		ft_env_position(char *arg, char **env)
{
	int		i;
	char	**temp;

	i = 0;
	while (env[i])
	{
		temp = ft_strsplit(env[i], '=');
		if (ft_strcmp(arg, temp[i]) == 0)
		{
			free(temp);
			return (i);
		}
		free(temp);
		i++;
	}
	return (i);
}

static char		**ft_new_env(int new_size, char **env)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (new_size));
	i = 0;
	while (env[i] && i < new_size)
	{
		new[i] = ft_strdup(env[i]);
		free(env[i]);
		i++;
	}
	free(env);
	return (new);
}

static void		set_env(char *env_var, char *env_value, char **env)
{
	int		position;
	char	*temp;

	position = ft_env_position(env_var, env);
	temp = ft_strjoin("=", env_value);
	if (env[position])
	{
		free(env[position]);
		if (env_value)
			env[position] = ft_strjoin(env_var, temp);
		else
			env[position] = ft_strjoin(env_var, "=");
	}
	else
	{
		env = ft_new_env(position + 2, env);
		if (env_value)
			env[position] = ft_strjoin(env_var, temp);
		else
			env[position] = ft_strjoin(env_var, "=");
	}
	free(temp);
}

void	do_setenv(char **arg, char **env)
{
	set_env(arg[1], arg[2], env);
}