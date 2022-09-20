/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:46:04 by echuong           #+#    #+#             */
/*   Updated: 2022/03/17 11:33:56 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"

# define TRUE 1
# define FALSE 0
# define WIDTH 1200
# define HEIGHT 800
# define FOV 60
# define MINI 5 

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define BLUE 0x0000FF
# define GREEN 0x00FF00

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
}		t_rect;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		height;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_ray
{
	double	dir;
	int		up;
	int		down;
	int		left;
	int		right;
	double	h_x;
	double	h_y;
	double	v_x;
	double	v_y;
	int		found_h;
	int		found_v;
	double	dist_h;
	double	dist_v;
	double	x;
	double	y;
	double	len;
	int		texture;
	int		text_x;
	int		text_y;
}			t_ray;

typedef struct s_p
{
	double	fov;
	double	x;
	double	y;
	char	dir;
	int		turn;
	double	front_back;
	double	left_right;
	double	rotate_angle;
	double	move_speed;
	double	rotate_speed;
	double	ray;
}			t_p;

typedef struct s_intersec
{
	double	start_x;
	double	start_y;
	double	inc_x;
	double	inc_y;
	int		flag_x;
	int		flag_y;
}			t_intersec;

typedef struct s_data
{
	int			fd;
	char		*line;
	char		*tmp;
	char		*n;
	char		*s;
	char		*w;
	char		*e;
	int			c[4];
	int			f[4];
	int			line_len;
	int			nb_line;
	char		**map;
	t_p			p;
	void		*mlx;
	void		*win;
	t_img		img;
	t_ray		rays[WIDTH];
	t_img		t[4];
	double		dist_pp;
	t_intersec	intersec;
}		t_data;

t_data	ft_init_data(void);
int		ft_init_mlx(t_data *data);
t_rect	ft_init_rect(int x, int y, int width, int height);
int		ft_check_params(int argc, char **argv, t_data *data);
int		ft_check_file(char *file, t_data *data);
int		ft_parse_file(t_data *data);
int		ft_get_textures(t_data *data, char *str);
int		ft_n_texture(t_data *data, char *str, int len, int flag);
int		ft_s_texture(t_data *data, char *str, int len, int flag);
int		ft_w_texture(t_data *data, char *str, int len, int flag);
int		ft_e_texture(t_data *data, char *str, int len, int flag);
int		ft_import_textures(t_data *data);
int		ft_get_fc(t_data *data, char *str);
int		ft_get_map(t_data *data);
int		ft_check_player(t_data *data);
int		ft_flood(char **map, int i, int j);
int		ft_display(t_data *data);
int		ft_render(t_data *data);
int		ft_render_walls(t_data *data);
int		ft_handle_moves(t_data *data);
int		ft_handle_fov(t_data *data);
int		ft_check_walls(t_data *data, double x, double y, int flag);
int		ft_spawn_p(t_data *data);
int		ft_draw_p(t_data *data);
int		ft_get_intersec(t_data *data, t_ray *ray);
int		ft_check_h(t_data *data, t_ray *ray);
int		ft_check_v(t_data *data, t_ray *ray);
int		ft_draw_img(t_data *data);
int		ft_draw_map2d(t_data *data);
int		ft_draw_rect(t_data *data, t_img *img, t_rect rect, int color);
void	ft_pxl_put(t_img *img, int x, int y, int color);
int		ft_handle_keypress(int keysym, t_data *data);
int		ft_handle_keyrelease(int keysym, t_data *data);
int		ft_handle_cross(t_data *data);
char	*ft_strdup(t_data *data, char *str, int len, int flag);
char	*ft_strjoin(t_data *data, char *s1, char *s2);
int		ft_isdigit(char c);
int		ft_atoi(char *str);
int		ft_check_whitespaces(char *str);
int		ft_check_char(char *str, char c);
int		ft_check_chars(char *str, char *chars);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlen(char *str);
int		ft_get_len(char *str);
int		ft_gnl(t_data *data, char **line);
void	ft_check_malloc(t_data *data, void *elem);
void	ft_error_open(char *str);
int		ft_put_error(char *str);
void	ft_free(t_data *data);
void	ft_free_arr(char **arr);

#endif
