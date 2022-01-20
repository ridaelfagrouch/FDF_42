/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:02:13 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/20 16:13:51 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_put_imag(t_data *data)
{
	creat_mlx(data);
	draw_42(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	color_screen1(data);
	print_screen1(data);
	mlx_hook(data->win_ptr, 2, 0L, clo_se1, data);
	mlx_hook(data->win_ptr, 17, 0L, close_fdf1, data);
	mlx_loop(data->mlx_ptr);
}

//**********************************************************//
//**********************************************************//

void	main_data(t_data *data, char *argv, int *wrong_line, int *err)
{
	int	fd;

	fd = 0;
	fd = open(argv, O_RDONLY);
	data->height = count_row(fd);
	close(fd);
	if (data->height == 0)
		message_error_main(1, data);
	creat_row(argv, data, wrong_line, err);
	if (*err == -1)
		message_error_wrong_line(data, 1);
	if (*wrong_line == -1)
		message_error_wrong_line(data, 0);
	if (data->check_av == 0)
		chek_data_height(data);
}

//**********************************************************//
//**********************************************************//

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		wrong_line;
	int		error_;

	wrong_line = 0;
	error_ = 0;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	initial_data(data);
	if (argc == 2 || argc == 4)
	{
		ft_check_arg(argv[1]);
		if (argc == 4)
			check_arg_3_4(argv[2], argv[3], data);
		main_data(data, argv[1], &wrong_line, &error_);
		if (data->serch != 0)
			creatmatrix(argv[1], data);
		draw_put_imag(data);
	}
	else
		message_error_main(2, data);
	if (data->serch != 0)
		free_matrix(data->matrix2);
	return (free_matrix(data->matrix), free (data), 0);
}
