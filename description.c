/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:09:51 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/15 12:50:06 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_screen1(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 0, BL, " MADE BY  ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 0, 0x9F0000, " REL_FAGR");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 40, BL, " M");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 60, BL, " A");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 80, BL, " N");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 100, BL, " D");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 120, BL, " A");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 140, BL, " T");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 160, BL, " O");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 180, BL, " R");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 200, BL, " Y");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 240, BL, " P");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 260, BL, " A");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 280, BL, " R");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 300, BL, " T");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 360, BL, "EXIT :    ESC");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 400, BL, "whidth : ");
	print_screen2(data);
	return (0);
}

int	print_screen2(t_data *data)
{
	char	*ptr;

	ptr = ft_itoa(data->whidth);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 400, RED, ptr);
	free(ptr);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 420, BL, "height : ");
	ptr = ft_itoa(data->height);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 420, RED, ptr);
	return (free(ptr), 0);
}

int	color_screen1(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 230)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 40);
			x++;
		}
		y++;
	}
	return (0);
}
