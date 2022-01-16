/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:01:10 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/16 13:18:10 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	message_error_matrix_numb(int i, t_data *data)
{
	if (i == 1)
	{
		free(data);
		perror("bad alloca matrix-row file creat_tab.c/funct creat_row\n");
		exit(1);
	}
	else if (i == 2)
	{
		free_matrix(data->matrix);
		free(data);
		perror("bad alloca matrix file creat_tab.c/funct creat_row\n");
		exit(1);
	}
}

void	message_error_matrix_color(int i, t_data *data)
{
	if (i == 1)
	{
		free_matrix(data->matrix);
		free(data);
		perror("bad alloca matrix2-row file remplir_tab.c/funct creatmatrix\n");
		exit(1);
	}
	else if (i == 2)
	{
		free_matrix(data->matrix);
		free_matrix(data->matrix2);
		free(data);
		perror("bad alloca matrix2 file remplir_tab.c/funct creatmatrix\n");
		exit(1);
	}
}

void	message_error_main(int i, t_data *data)
{
	if (i == 1)
	{
		free(data);
		perror("map bad size file fdf.c/funct main\n");
		exit(1);
	}
}

void	message_error_wrong_line(t_data *data)
{
	free_matrix(data->matrix);
	free(data);
	perror("Found wrong line length. Exiting.\n");
	exit(1);
}
