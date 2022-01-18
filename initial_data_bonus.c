/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:19:22 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/17 12:04:07 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	initial_data(t_data *data)
{
	data->serch = 0;
	data->height = 0;
	data->whidth = 0;
	data->x_offset = 1100;
	data->y_offset = 300;
	data->z_altitude = 1;
	data->cord.alpha_x = 0;
	data->cord.alpha_y = 0;
	data->cord.alpha_z = 0;
	data->zoom_offset = 0;
	data->rotition = 0;
	data->p = 2;
	data->ran = 2;
	data->k = 0;
}
