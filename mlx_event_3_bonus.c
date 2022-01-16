/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:16:04 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/16 16:03:02 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	event_key(int keycode, t_data *data)
{
	if (keycode == SCROLL_UP)
		data->y_offset -= 30;
	if (keycode == SCROLL_DOWN)
		data->y_offset += 30;
	if (keycode == SCROLL_RIGHT)
		data->x_offset += 30;
	if (keycode == SCROLL_LIFT)
		data->x_offset -= 30;
	if (keycode == ESCP)
	{
		mlx_destroy_image(data->mlx_ptr, data->img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

//**********************************************************//
//**********************************************************//

void	zoom_centre(int keycode, t_data *data)
{
	if (data->whidth > 300 && keycode == ZOOM_UP)
		data->y_offset -= 300;
	if (data->whidth > 300 && keycode == ZOOM_DOWN)
		data->y_offset += 300;
	if (data->whidth > 100 && data->whidth <= 200 && keycode == ZOOM_UP)
		data->y_offset -= 100;
	if (data->whidth > 150 && data->whidth <= 200 && keycode == ZOOM_DOWN)
		data->y_offset += 100;
	if (data->whidth >= 100 && data->whidth <= 150 && keycode == ZOOM_UP)
		data->y_offset -= 20;
	if (data->whidth >= 100 && data->whidth <= 150 && keycode == ZOOM_DOWN)
		data->y_offset += 20;
	if (data->whidth >= 20 && data->whidth < 100 && keycode == ZOOM_UP)
		data->y_offset -= 10;
	if (data->whidth >= 20 && data->whidth < 100 && keycode == ZOOM_DOWN)
		data->y_offset += 10;
}

void	rotation_x(int *y, int *z, float alpha)
{
	*y = (*y * cos(alpha)) + (*z * sin(alpha));
	*z = (*z * cos(alpha)) - (*y * sin(alpha));
}

void	rotation_y(int *x, int *z, float alpha)
{
	*x = (*x * cos(alpha)) + (*z * sin(alpha));
	*z = (*z * cos(alpha)) - (*x * sin(alpha));
}

void	rotation_z(int *x, int *y, float alpha)
{
	*x = (*x * cos(alpha)) - (*y * sin(alpha));
	*y = (*x * sin(alpha)) + (*y * cos(alpha));
}
