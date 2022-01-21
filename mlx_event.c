/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:38:50 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/21 18:54:22 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	clo_se1(int keycode, t_data *data)
{
	if (keycode == ESCP)
	{
		mlx_destroy_image(data->mlx_ptr, data->img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free_matrix(data->matrix);
		if (data->serch != 0)
			free_matrix(data->matrix2);
		free(data->mlx_ptr);
		free(data);
		exit(0);
	}
	return (0);
}

//**********************************************************//
//**********************************************************//

int	close_fdf1(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->win_ptr);
	free_matrix(data->matrix);
	if (data->serch != 0)
		free_matrix(data->matrix2);
	free(data->mlx_ptr);
	free(data);
	exit(0);
	return (0);
}
