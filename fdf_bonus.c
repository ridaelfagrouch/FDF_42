/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:02:13 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/16 16:56:42 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_put_imag(t_data *data)
{
	creat_mlx(data);
	draw_42(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	color_screen(data);
	print_screen(data);
	mlx_hook(data->win_ptr, 2, 0L, func_mouv, data);
	mlx_hook(data->win_ptr, 17, 0L, close_fdf, data);
	mlx_loop(data->mlx_ptr);
}

//**********************************************************//
//**********************************************************//

void	main_data(t_data *data, char *argv, int *wrong_line)
{
	int	fd;

	fd = 0;
	initial_data(data);
	fd = open(argv, O_RDONLY);
	data->height = count_row(fd);
	close(fd);
	if (data->height == 0)
		message_error_main(1, data);
	creat_row(argv, data, wrong_line);
	if (*wrong_line == -1)
		message_error_wrong_line(data);
	chek_data_height(data);
}

//**********************************************************//
//**********************************************************//

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		wrong_line;

	wrong_line = 0;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (argc >= 2)
	{
		main_data(data, argv[1], &wrong_line);
		if (data->serch != 0)
			creatmatrix(argv[1], data);
		draw_put_imag(data);
	}
	if (data->serch != 0)
		free_matrix(data->matrix2);
	free_matrix(data->matrix);
	free (data);
	return (0);
}
