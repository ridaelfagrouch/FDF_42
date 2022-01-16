/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algo_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:07:52 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/14 22:24:17 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_algo(t_data *data)
{
	int	rundom_color;

	rundom_color = rand() % 16777216;
	initial_bresenhame(data);
	if (data->ran % 2 != 0)
		data->color = rundom_color;
	while (1)
	{
		img_pix_put(data, data->indx.x + data->x_offset, \
			data->indx.y + data->y_offset, data->color);
		if (data->indx.x == data->indx.x1 && data->indx.y == data->indx.y1)
			break ;
		data->cord.e2 = 2 * data->cord.err;
		if (data->cord.e2 >= data->cord.delta_y)
		{
			data->cord.err += data->cord.delta_y;
			data->indx.x += data->cord.sx;
		}
		if (data->cord.e2 <= data->cord.delta_x)
		{
			data->cord.err += data->cord.delta_x;
			data->indx.y += data->cord.sy;
		}
	}
}

//**********************************************************//
//**********************************************************//

void	inetial_index1(t_data *data, int x, int y)
{
	data->indx.x = x;
	data->indx.x1 = x + 1;
	data->indx.y = y;
	data->indx.y1 = y;
}

//**********************************************************//
//**********************************************************//

void	inetial_index2(t_data *data, int x, int y)
{
	data->indx.x = x;
	data->indx.x1 = x;
	data->indx.y = y;
	data->indx.y1 = y + 1;
}

//**********************************************************//
//**********************************************************//

void	draw_42(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->whidth)
		{
			if (x < data->whidth - 1)
			{
				inetial_index1(data, x, y);
				draw_algo(data);
			}
			if (y < data->height - 1)
			{
				inetial_index2(data, x, y);
				draw_algo(data);
			}
			x++;
		}
		y++;
	}
}
