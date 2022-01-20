/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:33:27 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/20 17:20:58 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "FDF_libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

typedef struct coord
{
	int		delta_x;
	int		delta_y;
	int		sx;
	int		sy;
	int		z;
	int		z1;
	int		err;
	int		e2;
	float	alpha_x;
	float	alpha_y;
	float	alpha_z;
}	t_coord;

typedef struct indec
{
	int	x;
	int	x1;
	int	y;
	int	y1;
}	t_ind;

typedef struct creat
{
	char	*str;
	int		j;
	int		i;
	int		fd;
	char	**splt_str;
	int		**result;
	int		check_av;
}	t_tab;

typedef struct d_data
{
	int					whidth;
	int					height;
	int					color;
	void				*mlx_ptr;
	void				*win_ptr;
	int					**matrix;
	int					**matrix2;
	double				zoom;
	double				z_altitude;
	double				x_offset;
	double				y_offset;
	int					serch;
	void				*img;
	char				*addr;
	int					bpp;
	int					line_length;
	int					endian;
	int					k;
	unsigned int		p;
	int					ran;
	double				zoom_offset;
	int					rotition;
	int					check_av;
	t_coord				cord;
	t_ind				indx;
	t_tab				creat;
}	t_data;

# define WINDOW_WHITE	1900
# define WINDOW_HEIGHT	1080

# define WHIGHT_COLOR	0xFFFFFF
# define RED_COLOR	0x9F0000
# define BL	0xFFFFFF
# define RED 0xD30000

# define SCROLL_LIFT	123
# define SCROLL_RIGHT	124
# define SCROLL_UP	126
# define SCROLL_DOWN 125
# define ESCP 53
# define PLUS 69
# define MINES 78
# define X_BUTTON 7
# define Y_BUTTON 16
# define Z_BUTTON 6
# define P_PARALLEL 35
# define ZOOM_UP 31
# define ZOOM_DOWN 34
# define RNDM 15

# define BUFFER_SIZE 940

char	*get_next_line(int fd);
size_t	ft_strlen1(char *str);
char	*ft_strjoin1(char *s1, char *s2);
char	*if_star(void);
char	*ft_substr1(char *s, unsigned int start, unsigned int len);
void	ft_bzero1(void *s, size_t n);
//*************************************************************
void	draw_algo(t_data *data);
void	inetial_index1(t_data *data, int x, int y);
void	inetial_index2(t_data *data, int x, int y);
void	draw_42(t_data *data);
void	rotation_mov(t_data *data);
void	altitud_mov(t_data *data);
int		count_row(int fd);
int		strlen_split(t_data *data);
void	vergul_cherch(t_data *data);
void	rempler_numb_matrix(t_data *data);
void	creat_row_proces(t_data *data, int *wrong_line, int *err);
void	creat_row(char *argv, t_data *data, int *wrong_line, int *err);
void	draw_put_imag(t_data *data);
void	main_data(t_data *data, char *argv, int *wrong_line, int *err);
void	initial_data(t_data *data);
void	check_color(t_data *data, int *z, int *z1);
int		check_sx_sy(int i, int j);
void	initial_bresenhame(t_data *data);
void	multep_zoom(t_data *data);
void	zoom_centre(int keycode, t_data *data);
int		clo_se(int keycode, t_data *data);
int		close_fdf(t_data *data);
int		print_screen(t_data *data);
int		func_mouv(int keycode, t_data *data);
int		event_key(int keycode, t_data *data);
int		map_zoom(int keycode, t_data *data);
int		altitud_map(int keycode, t_data *data);
int		projection_para(int keycode, t_data *data);
int		rotation_map(int keycode, t_data *data);
void	img_pix_put(t_data *img, int x, int y, int color);
void	creat_mlx(t_data *data);
void	free_matrix(int **ptr);
void	free_split(char **ptr);
int		ft_char_to_hex(char *str);
void	ft_check_split(t_data *data);
void	creatmatrix_proces(t_data *data);
void	creatmatrix(char *argv, t_data *data);
void	iso_pro(int *x, int *y, int z);
void	chek_data_height(t_data *data);
void	rotation_x(t_data *data);
void	rotation_y(t_data *data);
void	rotation_z(t_data *data);
void	message_error_matrix_numb(int i, t_data *data);
void	message_error_matrix_color(int i, t_data *data);
void	message_error_main(int i, t_data *data);
int		color_screen(t_data *data);
int		random_color(int keycode, t_data *data);
int		print_variable1(t_data *data);
int		print_variable2(t_data *data);
int		mlx_key_init(t_data *data);
int		clo_se1(int keycode, t_data *data);
int		close_fdf1(t_data *data);
void	message_error_wrong_line(t_data *data, int i);
void	ft_check_arg(char *argv);
void	check_arg_3_4(char *av_3, char *av_4, t_data *data);
int		check_av4(char *av_4, int *j, t_data *data);
int		check_av3(char *av_3, int *i, t_data *data);
void	altitud_mov2(t_data *data);

#endif