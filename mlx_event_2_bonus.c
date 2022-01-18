/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:48:31 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/17 12:05:29 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	random_color(int keycode, t_data *data)
{
	if (keycode == RNDM)
		data->ran += 1;
	return (0);
}

//**********************************************************//
//**********************************************************//

int	rotation_map(int keycode, t_data *data)
{	
	if (keycode == X_BUTTON)
	{
		data->cord.alpha_x += 0.3;
		data->rotition = 1;
	}
	else if (keycode == Y_BUTTON)
	{
		data->cord.alpha_y += 0.3;
		data->rotition = 2;
	}
	else if (keycode == Z_BUTTON)
	{
		data->cord.alpha_z += 0.3;
		data->rotition = 3;
	}
	return (0);
}

//**********************************************************//
//**********************************************************//

int	projection_para(int keycode, t_data *data)
{
	if (keycode == P_PARALLEL)
	{
		data->p += 1;
		if (data->p % 2 != 0)
		{
			data->x_offset = 1000;
			data->y_offset = 300;
		}
	}
	return (0);
}

//**********************************************************//
//**********************************************************//

int	altitud_map(int keycode, t_data *data)
{
	if (keycode == PLUS)
	{
		data->z_altitude += 2;
		data->k = 1;
	}
	else if (keycode == MINES)
	{
		data->z_altitude -= 2;
		data->k = -1;
	}
	return (0);
}

//**********************************************************//
//**********************************************************//

int	map_zoom(int keycode, t_data *data)
{
	if (keycode == ZOOM_UP)
	{
		data->zoom_offset += 1;
		zoom_centre(keycode, data);
	}
	else if (keycode == ZOOM_DOWN)
	{
		if (data->zoom <= 0)
			chek_data_height(data);
		data->zoom_offset -= 1 ;
		zoom_centre(keycode, data);
	}
	return (0);
}
