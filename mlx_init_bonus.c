/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:16:32 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/19 17:13:34 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	img_pix_put(t_data *img, int x, int y, int color)
{
	char	*pixel;

	if ((x >= 0 && x < 1900) && (y >= 0 && y < 1080))
	{
		pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

//**********************************************************//
//**********************************************************//

void	creat_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		if (data->serch != 0)
			free_matrix(data->matrix2);
		free_matrix(data->matrix);
		free(data);
		return ;
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
		WINDOW_WHITE, WINDOW_HEIGHT, "42_graph_fdf");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		if (data->serch != 0)
			free_matrix(data->matrix2);
		free_matrix(data->matrix);
		free(data);
		return ;
	}
	data->img = mlx_new_image(data->mlx_ptr, WINDOW_WHITE, WINDOW_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, \
		&data->line_length, &data->endian);
}

//**********************************************************//
//**********************************************************//

int	color_screen(t_data *data)
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
