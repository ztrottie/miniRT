#include "../../include/maths.h"

t_vec	vec_add(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

double	vec_dist(t_vec v1, t_vec v2)
{
	double t;

	t = sqrt(sqr(v2.x - v1.x) + sqr(v2.y - v1.y) + sqr(v2.z - v1.z));
	return (t);
}

double	vector_length(t_vec vec)
{
	return(sqrt(sqr(vec.x) + sqr(vec.y) + sqr(vec.z)));
}

t_vec	normalize(t_vec vec)
{
	double	vec_len;

	vec_len = vector_length(vec);
	return (vec_div(vec_len, vec));
}


t_vec	vec_add_nb(t_vec v1, double add)
{
	t_vec	res;

	res.x = v1.x + add;
	res.y = v1.y + add;
	res.z = v1.z + add;
	return (res);
}

t_vec    vec_sub_vec(t_vec v1, t_vec v2)
{
    t_vec    res;

    res.x = v1.x - v2.x;
    res.y = v1.y - v2.y;
    res.z = v1.z - v2.z;
    return (res);
}

t_vec    vec_sub_nb(t_vec v1, double sub)
{
    t_vec    res;

    res.x = v1.x - sub;
    res.y = v1.y - sub;
    res.z = v1.z - sub;
    return (res);
}

t_vec	vec_mult(double mult, t_vec v1)
{
	t_vec res;

	res.x = mult * v1.x;
	res.y = mult * v1.y;
	res.z = mult * v1.z;
	return (res);
}

t_vec	vec_div(double div, t_vec v1)
{
	return (vec_mult(1 / div, v1));
}


t_vec	vec_mult_vec(t_vec v1, t_vec v2)
{
	t_vec res;

	res.x = v1.x * v2.x;
	res.y = v1.y * v2.y;
	res.z = v1.z * v2.z;
	return (res);
}