/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:21:24 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/19 16:52:52 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	clo_se(int keycode, t_data *data)
{
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

int	close_fdf(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

//**********************************************************//
//**********************************************************//

int	mlx_key_init(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WINDOW_WHITE, WINDOW_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, \
		&data->line_length, &data->endian);
	draw_42(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	color_screen(data);
	print_screen(data);
	return (0);
}

//**********************************************************//
//**********************************************************//

int	func_mouv(int keycode, t_data *data)
{
	event_key(keycode, data);
	altitud_map(keycode, data);
	rotation_map(keycode, data);
	projection_para(keycode, data);
	map_zoom(keycode, data);
	random_color(keycode, data);
	mlx_key_init(data);
	return (0);
}
