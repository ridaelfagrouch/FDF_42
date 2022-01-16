/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_mouve_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:30:32 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/16 17:12:07 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotation_mov(t_data *data)
{
	if (data->cord.alpha_x != 0)
	{
		rotation_x(&data->indx.y, &data->cord.z, data->cord.alpha_x);
		rotation_x(&data->indx.y1, &data->cord.z1, data->cord.alpha_x);
	}
	if (data->cord.alpha_y != 0)
	{
		rotation_y(&data->indx.x, &data->cord.z, data->cord.alpha_y);
		rotation_y(&data->indx.x1, &data->cord.z1, data->cord.alpha_y);
	}
	if (data->cord.alpha_z != 0)
	{
		rotation_z(&data->indx.x, &data->indx.y, data->cord.alpha_z);
		rotation_z(&data->indx.x1, &data->indx.y1, data->cord.alpha_z);
	}
}

//**********************************************************//
//**********************************************************//

void	altitud_mov(t_data *data)
{
	if (data->cord.z != 0 || data->cord.z1 != 0)
	{
		if (data->k == 1)
		{
			data->cord.z *= data->z_altitude;
			data->cord.z1 *= data->z_altitude;
		}
		else if (data->k == -1)
		{
			data->cord.z *= data->z_altitude;
			data->cord.z1 *= data->z_altitude;
		}
	}
}
