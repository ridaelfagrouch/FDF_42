/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplir_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:02:04 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/20 20:45:13 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_char_to_hex(char *str)
{
	size_t	i;
	size_t	j;
	int		n;

	n = 0;
	i = ft_strlen(str) - 1;
	j = 0;
	while (j < ft_strlen(str) - 2)
	{
		if (str[i] >= 48 && str[i] <= 57)
			n += ((str[i] - 48) * pow(16, j));
		else if (str[i] >= 65 && str[i] <= 70)
			n += ((str[i] - 55) * pow(16, j));
		else if (str[i] >= 97 && str[i] <= 102)
			n += ((str[i] - 87) * pow(16, j));
		j++;
		i--;
	}
	return (n);
}

//**********************************************************//
//**********************************************************//

void	ft_check_split(t_data *data)
{
	int		i;
	char	**splt2;

	i = 0;
	while (i < data->whidth)
	{
		data->cord.z = data->matrix[data->creat.j][i];
		if (data->cord.z == 0 && !ft_strchr(data->creat.splt_str[i], ','))
			data->matrix2[data->creat.j][i] = WHIGHT_COLOR;
		else if (data->cord.z != 0 && !ft_strchr(data->creat.splt_str[i], ','))
			data->matrix2[data->creat.j][i] = RED_COLOR;
		else if (ft_strchr(data->creat.splt_str[i], ','))
		{
			splt2 = ft_split(data->creat.splt_str[i], ',');
			if (splt2[1][0] == '0' && splt2[1][1] == 'x')
			{
				data->matrix2[data->creat.j][i] = ft_char_to_hex(splt2[1]);
				free_split(splt2);
			}
		}
		i++;
	}
}

//**********************************************************//
//**********************************************************//

void	creatmatrix_proces(t_data *data)
{
	data->creat.str = get_next_line(data->creat.fd);
	data->creat.splt_str = ft_split(data->creat.str, ' ');
	free(data->creat.str);
	ft_check_split(data);
	free_split(data->creat.splt_str);
}

//**********************************************************//
//**********************************************************//

void	creatmatrix(char *argv, t_data *data)
{
	data->creat.j = 0;
	data->creat.fd = open(argv, O_RDONLY);
	data->matrix2 = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!data->matrix2)
		message_error_matrix_color(1, data);
	data->matrix2[data->height] = NULL;
	while (data->creat.j < data->height)
	{
		data->matrix2[data->creat.j] = \
			(int *)malloc(data->whidth * sizeof(int));
		if (!data->matrix2[data->creat.j])
			message_error_matrix_color(2, data);
		creatmatrix_proces(data);
		data->creat.j++;
	}
	close(data->creat.fd);
}
