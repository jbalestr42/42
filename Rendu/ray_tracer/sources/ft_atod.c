#include "ray_tracer.h"
#include "parser.h"

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

double		ft_atod(char *str)
{
	double		total;
	double		total_d;
	int			is_neg;
	int			size;

	total = 0;
	total_d = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if ((is_neg = *str == '-' ? -1 : 1) == -1 || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
		total = (total * 10) + (*str++ - '0');
	if (*str && *str == '.')
	{
		str++;
		size = 1;
		while (*str && ft_isdigit(*str))
		{
			total_d = (total_d * 10) + (*str++ - '0');
			size = size * 10;
		}
	}
	return ((total + (total_d / size)) * is_neg);
}
