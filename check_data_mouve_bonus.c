/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_mouve_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:30:32 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/18 12:08:55 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotation_mov(t_data *data)
{
	if (data->rotition == 1)
		rotation_x(data);
	if (data->rotition == 2)
		rotation_y(data);
	if (data->rotition == 3)
		rotation_z(data);
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
