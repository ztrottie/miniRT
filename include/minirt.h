#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <math.h>

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define WIDTH 1920
# define HEIGHT 1080
# define TITLE	"miniRT"

# define DEFAULT_BACKGROUD	0xB6BDCCFF
# define DEFAULT_TOUCH 0xFF0000FF

# define INVALID 0
# define VALID 1

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_data
{
	mlx_t	*mlx;
}	t_data;


#endif