#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <math.h>

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define WIDTH 1920
# define TITLE	"miniRT"

# define DEFAULT_BACKGROUD	0x000000FF
# define DEFAULT_TOUCH 0xFF0000FF

# define T_MIN 0
# define T_MAX INT_MAX

# define NB_REBOUND 1
# define RAY_PER_PIXEL 1

# define INVALID 0
# define VALID 1

# define NB_OBJECT 3

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef t_vec	t_color;
typedef t_vec	t_point;

typedef struct s_ray
{
	t_vec	or;
	t_vec	dir;
}	t_ray;

typedef struct	s_material
{
	t_color	color;
	float	bright;
}	t_material;

typedef struct s_hitrec
{
	bool		hit;
	t_point		hitpoint;
	t_vec		normal;
	t_material	material;
	int			type;
	double		t;
}	t_hitrec;

typedef struct s_objs
{
	int			type;
	t_hitrec	(*intersect_function)(struct s_objs, struct s_ray, int t_max);
	t_point		center;
	t_vec		normal;
	t_material	material;
	double		radius;
	double		height;
}	t_objs;

typedef struct s_alight
{
	t_material	material;
}	t_alight;

typedef struct s_light
{
	t_point		center;
	t_material	material;
}	t_light;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*mlx_image;
	t_objs		*objs;
	t_light		light;
	t_alight	alight;
	char		type[NB_OBJECT][NB_OBJECT];
	char		**map;
	t_vec		cam_dir;
	int			nb_objs;
	int			img_height;
	double		fov;
	t_vec		cam;
}	t_data;


#endif