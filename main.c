/*
 *
 *   FOR LIB TESTING
*/
#include "libft.h"
#include "ft_math.h"
#include "ft_printf.h"
#include <math.h>
#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");
	int prec = 23;
	double nb = -132143.00009999943243243;

	ft_printf("%.*f\n", prec, nb);
	printf("%.*f\n", prec, nb);

	ft_printf("%.59f\n", log(0.0000000000000000000999999999));
	printf("%.59f\n", ft_ln(0.0000000000000000000999999999));

	ft_printf("%.59f\n", 5.1 * pow(10, -52));
	printf("%.59f\n", 5.1 * ft_powf_ip(10, -52));

	return (0);
}
