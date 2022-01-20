/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:01:10 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/20 17:21:16 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	message_error_matrix_numb(int i, t_data *data)
{
	if (i == 1)
	{
		free(data);
		write(1, "bad alloca matrix-row file creat_tab.c/funct creat_row\n", 60);
		exit(1);
	}
	else if (i == 2)
	{
		free_matrix(data->matrix);
		free(data);
		write(1, "bad alloca matrix file creat_tab.c/funct creat_row\n", 51);
		exit(1);
	}
}

void	message_error_matrix_color(int i, t_data *data)
{
	if (i == 1)
	{
		free_matrix(data->matrix);
		free(data);
		write(1, "bad alloca matrix2-row \
			file remplir_tab.c/funct creatmatrix\n", 60);
		exit(1);
	}
	else if (i == 2)
	{
		free_matrix(data->matrix);
		if (data->serch != 0)
			free_matrix(data->matrix2);
		free(data);
		write(1, "bad alloca matrix2 file \
			remplir_tab.c/funct creatmatrix\n", 56);
		exit(1);
	}
}

void	message_error_main(int i, t_data *data)
{
	if (i == 1)
	{
		free(data);
		write(1, "map bad size file fdf.c/funct main\n", 35);
		exit(1);
	}
	else if (i == 2)
	{
		free(data);
		write(1, "bad arg number!\n", 16);
		exit(1);
	}
}

void	message_error_wrong_line(t_data *data, int i)
{
	if (i == 0)
	{
		free_matrix(data->matrix);
		free(data);
		write(1, "Found wrong line length. Exiting.\n", 34);
		exit(1);
	}
	else if (i == 1)
	{
		free_matrix(data->matrix);
		free(data);
		write(1, "error!\n", 7);
		exit(1);
	}
}
