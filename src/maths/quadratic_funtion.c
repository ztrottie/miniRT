# include "../../include/maths.h"

double	discriminant(double a, double b, double c)
{
	return (sqr(a) - 4 * a * c);
}

void	number_of_solutions(t_quad *quad)
{
	quad->disc = discriminant(quad->a, quad->b, quad->c);
	if (quad->disc > 0)
		quad->nb_solution = 2;
	else if (quad->disc == 0)
		quad->nb_solution = 1;
	else
		quad->nb_solution = 0;
}

/// @brief formula to get the intersection point of the sphere and vector
/// @param quad struct to store the intersection
/// @return if the vector is valid 1 is returned or if invalid 0 is returned
int	quadratic_formula(t_quad *quad)
{
	number_of_solutions(quad);
	if (quad->nb_solution == 0)
		return (INVALID);
	quad->solutions = ft_calloc(quad->nb_solution, sizeof(double));
	quad->solutions[0] = (-quad->b + sqrt(quad->disc)) / (2 * quad->a);
	if (quad->solutions == 2)
		quad->solutions[1] = (-quad->b - sqrt(quad->disc)) / (2 * quad->a);
	return (VALID);
}

/// @brief formula to get the value of a, b, c with 2 vectors
/// @param quad struct to store the intersection
/// @param vec1 start of the vector
/// @param vec2 direciton of the vector
/// @param r radius of the sphere
void	quadratic_function(t_quad *quad, t_vec vec1, t_vec vec2, double r)
{
	quad->a = sqr(vec2->x) + sqr(vec2->y) + sqr(vec2->z);
	quad->b = (2 * vec1->x * vec2->x) + (2 * vec1->y * vec2->y) + \
	(2 * vec1->z * vec2->z);
	quad->c = sqr(vec1->x) + sqr(vec1->y) + sqr(vec1->z) + sqr(r);
}
