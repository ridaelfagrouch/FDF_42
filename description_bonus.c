/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:09:51 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/14 22:24:45 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	print_screen(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 0, BL, " MADE BY  ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 0, 0x9F0000, " REL_FAGR");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 40, BL, " MVM :");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 60, BL, " up");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 80, BL, " down");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 100, BL, " right");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 120, BL, " left");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 160, BL, " ZOOM :");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 180, BL, " zoom_up : O");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 200, BL, " zoom_dow : I");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 240, BL, " 3D/PARA :");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 260, BL, " P");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 300, BL, " ROTATION:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 320, BL, " axe_x: X");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 340, BL, " axe_y: Y");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 360, BL, " axe_z: Z");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 400, BL, " ALTITUDE : ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 420, BL, " up : +");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 440, BL, " down : -");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 480, BL, " EXIT : ESC");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 520, BL, " RANDOM COLOR: ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 540, BL, "ori/rnd : R");
	print_variable1(data);
	print_variable2(data);
	return (0);
}

int	print_variable1(t_data *data)
{
	char	*ptr;

	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 580, \
		0x9F0000, "MAP_STATUS");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 580, BL, "- - -");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 580, BL, "- - - -");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 580, \
		0x9F0000, "MAP_STATUS");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 620, BL, "x_offset : ");
	ptr = ft_itoa(data->x_offset);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 620, RED, ptr);
	free(ptr);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 650, BL, "y_offset : ");
	ptr = ft_itoa(data->y_offset);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 650, RED, ptr);
	free(ptr);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 680, BL, "zoom_offset : ");
	ptr = ft_itoa(data->zoom_offset);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 140, 680, RED, ptr);
	free(ptr);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 710, BL, "altitude : ");
	ptr = ft_itoa(data->z_altitude);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 120, 710, RED, ptr);
	free(ptr);
	return (0);
}

int	print_variable2(t_data *data)
{
	char	*ptr;

	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 740, BL, "x_rot : ");
	ptr = ft_itoa(data->cord.alpha_x);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 740, RED, ptr);
	free(ptr);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 770, BL, "y_rot : ");
	ptr = ft_itoa(data->cord.alpha_y);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 770, RED, ptr);
	free(ptr);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 800, BL, "z_rot : ");
	ptr = ft_itoa(data->cord.alpha_z);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 800, RED, ptr);
	free(ptr);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 830, BL, "whidth : ");
	ptr = ft_itoa(data->whidth);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 830, RED, ptr);
	free(ptr);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 860, BL, "height : ");
	ptr = ft_itoa(data->height);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 860, RED, ptr);
	free(ptr);
	return (0);
}
