/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_tab_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:07:33 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/17 13:12:12 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	strlen_split(t_data *data)
{
	int	i;

	i = 0;
	while (data->creat.splt_str[i] && *(data->creat.splt_str[i]) != '\n')
		i++;
	return (i);
}

//**********************************************************//
//**********************************************************//

void	vergul_cherch(t_data *data)
{
	if (ft_strchr(data->creat.str, ','))
		data->serch++;
}

//**********************************************************//
//**********************************************************//

void	rempler_numb_matrix(t_data *data)
{
	int	i;

	i = 0;
	while (data->creat.splt_str[i] && *(data->creat.splt_str[i]) != '\n')
	{
		data->matrix[data->creat.j][i] = \
			ft_atoi((const char *)data->creat.splt_str[i]);
		i++;
	}
	free_split(data->creat.splt_str);
}

//**********************************************************//
//**********************************************************//

void	creat_row_proces(t_data *data, int *wrong_line)
{
	data->creat.str = get_next_line(data->creat.fd);
	vergul_cherch(data);
	data->creat.splt_str = ft_split(data->creat.str, ' ');
	data->whidth = strlen_split(data);
	if (*wrong_line == 0)
		*wrong_line = data->whidth;
	if (data->whidth != *wrong_line || data->creat.str[0] == '\n')
		*wrong_line = -1;
	free(data->creat.str);
}

//**********************************************************//
//**********************************************************//

void	creat_row(char *argv, t_data *data, int *wrong_line)
{
	data->creat.j = 0;
	data->creat.fd = open(argv, O_RDONLY);
	data->matrix = (int **)malloc(sizeof(int *) * data->height + 1);
	if (!data->matrix)
		message_error_matrix_numb(1, data);
	data->matrix[data->height] = NULL;
	while (data->creat.j < data->height)
	{
		creat_row_proces(data, wrong_line);
		data->matrix[data->creat.j] = (int *)malloc(data->whidth * sizeof(int));
		if (data->matrix[data->creat.j] == NULL)
			message_error_matrix_numb(2, data);
		rempler_numb_matrix(data);
		data->creat.j++;
	}
	close(data->creat.fd);
}
