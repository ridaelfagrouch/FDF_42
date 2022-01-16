/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zome_iso_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:07:27 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/14 22:26:10 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	iso_pro(int *x, int *y, int z)
{
	int	new_x;
	int	new_y;

	new_x = *x;
	new_y = *y;
	*x = (new_x - new_y) * cos(0.523599);
	*y = -z + (new_x + new_y) * sin(0.523599);
}

//**********************************************************//
//**********************************************************//

void	chek_data_height(t_data *data)
{
	if (data->whidth > 400)
		data->zoom = 1;
	else if (data->whidth >= 200 && data->whidth <= 400)
		data->zoom = 2;
	else if (data->whidth > 50 && data->whidth < 200)
		data->zoom = 4;
	else if (data->whidth <= 50 && data->whidth > 20)
		data->zoom = 12;
	else if (data->whidth <= 20)
		data->zoom = 20;
}
