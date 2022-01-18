/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:16:04 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/18 12:38:00 by rel-fagr         ###   ########.fr       */
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

void	rotation_x(t_data *data)
{
	data->indx.y = (data->indx.y * cos(data->cord.alpha_x)) \
		+ (data->cord.z * sin(data->cord.alpha_x));
	data->cord.z = (data->cord.z * cos(data->cord.alpha_x)) \
		- (data->indx.y * sin(data->cord.alpha_x));
	data->indx.y1 = (data->indx.y1 * cos(data->cord.alpha_x)) \
		+ (data->cord.z1 * sin(data->cord.alpha_x));
	data->cord.z1 = (data->cord.z1 * cos(data->cord.alpha_x)) \
		- (data->indx.y1 * sin(data->cord.alpha_x));
}

void	rotation_y(t_data *data)
{
	data->indx.x = (data->indx.x * cos(data->cord.alpha_y)) \
		+ (data->cord.z * sin(data->cord.alpha_y));
	data->cord.z = (data->cord.z * cos(data->cord.alpha_y)) \
		- (data->indx.x * sin(data->cord.alpha_y));
	data->indx.x1 = (data->indx.x1 * cos(data->cord.alpha_y)) \
		+ (data->cord.z1 * sin(data->cord.alpha_y));
	data->cord.z1 = (data->cord.z1 * cos(data->cord.alpha_y)) \
		- (data->indx.x1 * sin(data->cord.alpha_y));
}

void	rotation_z(t_data *data)
{
	data->indx.x = (data->indx.x * cos(data->cord.alpha_z)) \
		- (data->indx.y * sin(data->cord.alpha_z));
	data->indx.y = (data->indx.x * sin(data->cord.alpha_z)) \
		+ (data->indx.y * cos(data->cord.alpha_z));
	data->indx.x1 = (data->indx.x1 * cos(data->cord.alpha_z)) \
		- (data->indx.y1 * sin(data->cord.alpha_z));
	data->indx.y1 = (data->indx.x1 * sin(data->cord.alpha_z)) \
		+ (data->indx.y1 * cos(data->cord.alpha_z));
}
