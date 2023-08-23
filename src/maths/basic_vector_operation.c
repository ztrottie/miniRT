#include "../../include/maths.h"

t_vec	vec_add(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vec    vec_sub_vec(t_vec v1, t_vec v2)
{
    t_vec    res;

    res = v1.x - v2.x;
    res = v1.y - v2.y;
    res = v1.z - v2.z;
    return (res);
}

t_vec    vec_sub_nb(t_vec v1, double sub)
{
    t_vec    res;

    res = v1.x - sub;
    res = v1.y - sub;
    res = v1.z - sub;
    return (res);
}

t_vec	vec_mult(double mult, t_vec v1)
{
	t_vec res;

	res = mult * v1.x;
	res = mult * v1.y;
	res = mult * v1.z;
	return (res);
}

t_vec	vec_div(double div, t_vec v1)
{
	return (vec_mult(1 / div, v1));
}
