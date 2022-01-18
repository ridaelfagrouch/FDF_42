/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialBresenhame_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:28:15 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/17 14:58:26 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	check_color(t_data *data, int *z, int *z1)
{
	if (data->serch != 0)
	{
		if (data->indx.x < data->whidth && \
			data->matrix2[data->indx.y][data->indx.x] == 0xFFFFFF \
			&& data->matrix2[data->indx.y][data->indx.x1] != 0xFFFFFF)
			data->color = data->matrix2[data->indx.y][data->indx.x1];
		else if (data->indx.y < data->height && \
			data->matrix2[data->indx.y][data->indx.x] == 0xFFFFFF \
			&& data->matrix2[data->indx.y1][data->indx.x] != 0xFFFFFF)
			data->color = data->matrix2[data->indx.y1][data->indx.x];
		else
			data->color = data->matrix2[data->indx.y][data->indx.x];
	}
	else
	{
		if (*z != 0 || *z1 != 0)
			data->color = RED_COLOR;
		else
			data->color = WHIGHT_COLOR;
	}
}

//**********************************************************//
//**********************************************************//

int	check_sx_sy(int i, int j)
{
	if (i < j)
		return (1);
	else
		return (-1);
	return (0);
}

//**********************************************************//
//**********************************************************//

void	initial_bresenhame(t_data *data)
{
	data->cord.z = data->matrix[data->indx.y][data->indx.x];
	data->cord.z1 = data->matrix[data->indx.y1][data->indx.x1];
	check_color(data, &data->cord.z, &data->cord.z1);
	altitud_mov(data);
	multep_zoom(data);
	rotation_mov(data);
	if (data->p % 2 == 0)
	{
		iso_pro(&data->indx.x, &data->indx.y, data->cord.z);
		iso_pro(&data->indx.x1, &data->indx.y1, data->cord.z1);
	}
	data->cord.delta_x = abs(data->indx.x1 - data->indx.x);
	data->cord.delta_y = -abs(data->indx.y1 - data->indx.y);
	data->cord.sx = check_sx_sy(data->indx.x, data->indx.x1);
	data->cord.sy = check_sx_sy(data->indx.y, data->indx.y1);
	data->cord.err = data->cord.delta_y + data->cord.delta_x;
}

//**********************************************************//
//**********************************************************//

void	multep_zoom(t_data *data)
{
	data->indx.x = data->indx.x * (data->zoom + data->zoom_offset);
	data->indx.y = data->indx.y * (data->zoom + data->zoom_offset);
	data->indx.x1 = data->indx.x1 * (data->zoom + data->zoom_offset);
	data->indx.y1 = data->indx.y1 * (data->zoom + data->zoom_offset);
}
