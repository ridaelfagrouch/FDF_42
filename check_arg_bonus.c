/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:35:59 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/19 15:44:25 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_check_arg(char *argv)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (ft_strchr(argv, '.') == 0)
	{
		write(1, "bad file!\n", 10);
		exit(1);
	}
	str = ft_strdup(ft_strchr(argv, '.'));
	if (str[0] == '.' && str[1] == 'f' && str[2] == 'd' \
		&& str[3] == 'f' && str[4] == '\0')
		i++;
	else if (ft_strlen(str) != 4)
	{
		free(str);
		write(1, "bad file!\n", 10);
		exit(1);
	}
	free(str);
}

int	check_av3(char *av_3, int *i, t_data *data)
{
	while (av_3[*i])
	{
		if (ft_isdigit(av_3[*i]))
			(*i)++;
		else
		{
			free(data);
			write(1, "av3 is not degit", 16);
			exit(1);
		}
	}
	return (0);
}

int	check_av4(char *av_4, int *j, t_data *data)
{
	while (av_4[*j])
	{
		if (ft_isdigit(av_4[*j]))
			(*j)++;
		else
		{
			free(data);
			write(1, "av4 is not degit", 16);
			exit(1);
		}
	}
	*j = 4;
	return (0);
}

void	check_arg_3_4(char *av_3, char *av_4, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (av_3[i] == '-')
		i++;
	if (av_4[j] == '-')
		j++;
	check_av3(av_3, &i, data);
	check_av3(av_4, &j, data);
	data->zoom = ft_atoi((const char *)av_3);
	data->z_altitude = ft_atoi((const char *)av_4);
	data->check_av = 1;
}
