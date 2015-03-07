/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:35:34 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 17:41:25 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>

# include <stdio.h>

# define WIDTH 1200
# define HEIGHT 800
# define EPSILON 1e-7f

// # define WATER_DARK_COLOR 0x0033CC
// # define WATER_DARK_HEIGHT 0
// # define WATER_LIGHT_COLOR 0x00CCFF
// # define WATER_LIGHT_HEIGHT 1
// # define GRASS_DARK_COLOR 0x009900
// # define GRASS_DARK_HEIGHT 2
// # define GRASS_WHITE_COLOR 0x33FF00
// # define GRASS_WHITE_HEIGHT 3
// # define MOUNTAIN_DARK_COLOR 0x663300
// # define MOUNTAIN_DARK_HEIGHT 4
// # define MOUNTAIN_LIGHT_COLOR 0x996600
// # define MOUNTAIN_LIGHT_HEIGHT 5
// # define ICE_COLOR 0x0000FF
// # define ICE_HEIGHT 6

# define WATER_DARK_COLOR 0x33FF33
# define WATER_DARK_HEIGHT -10
# define WATER_LIGHT_COLOR 0x33FF33
# define WATER_LIGHT_HEIGHT 1
# define GRASS_DARK_COLOR 0x9999CC
# define GRASS_DARK_HEIGHT 3
# define GRASS_WHITE_COLOR 0xFFCC99
# define GRASS_WHITE_HEIGHT 5
# define MOUNTAIN_DARK_COLOR 0x663300
# define MOUNTAIN_DARK_HEIGHT 42
# define MOUNTAIN_LIGHT_COLOR 0x996600
# define MOUNTAIN_LIGHT_HEIGHT 5
# define ICE_COLOR 0x0000FF
# define ICE_HEIGHT 6

// # define WATER_DARK_COLOR 0xFFCC00
// # define WATER_DARK_HEIGHT -15
// # define WATER_LIGHT_COLOR 0xCC9900
// # define WATER_LIGHT_HEIGHT 10
// # define GRASS_DARK_COLOR 0xFFCC00
// # define GRASS_DARK_HEIGHT 20
// # define GRASS_WHITE_COLOR 0x3300FF
// # define GRASS_WHITE_HEIGHT 30
// # define MOUNTAIN_DARK_COLOR 0x996600
// # define MOUNTAIN_DARK_HEIGHT 40
// # define MOUNTAIN_LIGHT_COLOR 0x663300
// # define MOUNTAIN_LIGHT_HEIGHT 50
// # define ICE_COLOR 0x33FFFF
// # define ICE_HEIGHT 60

# define TRANSLATE 10
# define SCALE 11
# define ROTATE 12

typedef struct		s_matrix
{
	float			a;
	float			b;
	float			c;
	float			d;
	float			e;
	float			f;
	float			g;
	float			h;
	float			i;
	float			j;
	float			k;
	float			l;
	float			m;
	float			n;
	float			o;
	float			p;
}					t_matrix;

typedef struct		s_coordinates
{
	float			x;
	float			y;
}					t_coordinates;

typedef struct		s_vector
{
	float			x;
	float			y;
	float			z;
	float			p;
	int				color;
	int				exist;
	float			buffx;
	float			buffy;
}					t_vector;

typedef struct		s_edge
{
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			color1;
	float			color2;
}					t_edge;

typedef struct		s_span
{
	int				color1;
	int				color2;
	int				x1;
	int				x2;
}					t_span;

typedef struct		s_entity
{
	int				size;
	t_vector		*a;
	t_vector		*b;
	t_vector		*c;
	struct s_entity	*next;
}					t_entity;

typedef struct		s_object
{
	char			*name;
	char			*group;
	char			*sub_group;
	t_vector		***map;
	t_entity		*entities;
	t_matrix		rmatrix;
	t_matrix		tmatrix;
	t_matrix		smatrix;
	t_matrix		matrix;
	struct s_object	*next;
}					t_object;

typedef struct		s_env
{
	int				refresh;
	t_object		*world;
	t_vector		***map;
	int				xmax;
	int				color;
	void			*mlx;
	void			*win;
	int				bpp;
	int				size_line;
	int				endian;
	void			*img;
	char			*pimg;
	int				width;
	int				height;
	// t_vector		*fov;
	char			*gselected;
	char			*oselected;
	t_matrix		matrix;
	t_vector		center;
	t_vector		eye;
	t_vector		up;
	float			aspect;
	float			zfar;
	float			znear;
	float			fov;
	float 			maxlinep2;
}					t_env;

void				ft_drawmap(t_env *e);
void				ft_drawline(t_vector *p1, t_vector *p2, t_env *e);
t_vector			***parser(char *filename);
t_object			*ft_parsing(char *path);
t_matrix			ft_m_x_m(t_matrix b, t_matrix a);
t_vector			ft_m_x_v(t_matrix m, t_vector o);
t_matrix			ft_toscale(float a, float b, float c);
t_matrix			ft_translation(float a, float b, float c);
t_matrix			ft_rotate_x(float beta);
t_matrix			ft_rotate_y(float beta);
t_matrix			ft_rotate_z(float beta);
t_matrix			ft_normal();
void				ft_normalize(t_vector *a);
void				ft_apply_m_to_v(t_matrix m, t_vector *o);
void				ft_apply_m_to_obj(t_env *e, t_matrix matrix, char kind);
int					ft_refresh(t_env *e);
int					ft_updatekey(int key, t_env *e);
int					ft_update_img(t_env *e, void f(t_env *e));
int					ft_put_pixel_to_screen(t_env *e, int x, int y, int color);
t_matrix			ft_lookat(t_env *e);
t_matrix			ft_perspective(t_env *e);
t_vector			ft_v_l_v(t_vector a, t_vector b);
float				ft_dot(t_vector a, t_vector b);
t_vector			ft_cross(t_vector x, t_vector y);
void				ft_updateeye(t_env *e, int keycode);
void				ft_scaleworld(t_env *e, int keycode);
void				ft_translateworld(t_env *e, int keycode);
void				ft_rotateworld(t_env *e, int keycode);
void				ft_updatecenter(t_env *e, int keycode);
int					ft_getcolor(int height);
size_t				ft_sizeofline(char *str);
t_vector			**ft_fillline(char *buff, int y);
size_t				ft_getnbrofline(char *filename);
t_vector			ft_normalized(t_vector v);
int					ft_refresh(t_env *e);
int					expose_hook(t_env *e);
void				ft_recenter(t_vector ****map);
t_entity			*ft_new3entity(t_vector *a, t_vector *b, t_vector *c);
t_entity			*ft_new2entity(t_vector *a, t_vector *b);
t_entity			*ft_new1entity(t_vector *a);
t_object			*ft_parsing(char *path);
void				ft_dropvw(t_vector *v);
void				ft_entities_add(t_entity **alst, t_entity *newe);
void				ft_applym2w(t_env *e);
void				ft_applym2w2(t_vector *tmp, t_vector *v);
void				ft_drawtriangle(t_env *e, t_entity *t);
size_t				ft_lenline(t_vector **map);
void				*ft_perror(char *str);
t_object			*ft_parsing(char *path);
t_entity			*ft_parse_entities(t_vector ***map);
t_matrix			ft_normalm(void);
void				ft_drawtriangle2(t_env *e, t_entity *t);
t_matrix			ft_identity(void);

#endif
