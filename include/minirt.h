#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <math.h>

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define WIDTH 1080
# define TITLE	"miniRT"

# define DEFAULT_BACKGROUD	0x000000FF
# define DEFAULT_TOUCH 0xFF0000FF

# define INVALID 0
# define VALID 1

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef t_vec t_color;
typedef t_vec t_point;

typedef	struct s_ray
{
	t_vec	or;
	t_vec	dir;
}	t_ray;

typedef struct	s_viewport
{
	double	vp_height;
	double	vp_width;
	t_vec	delta_v;
	t_vec	delta_u;
	t_vec	vp_v;
	t_vec	vp_u;
	t_vec	vp_center;
	t_vec	upper_left;
	t_vec	p00_loc;
}	t_viewport;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*mlx_image;
	int			img_height;
	double		foc_len;
	t_vec		cam;
}	t_data;


#endif