/*
 *
 *   FOR LIB TESTING
 *
#include "libft.h"
#include "ft_math.h"
#include <math.h>
#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");
	int len = 0;
	int e = 0;
	int prec = 23;
	double nb = -132143.00009999943243243;
	ft_putwchar(52564);
	printf("%lc\n", 52564);
	printf("%s\n", ft_ftoa(nb, prec, &len , &e));
	printf("%.*f\n", prec, nb);

	printf("%.53f\n", ft_atof("-3213321312312312345524423.000000000000000000000000312321"));
	printf("%.53f\n", atof("-32132132132131231345524423.000000000000000000000000312321"));

	printf("%.59f\n", log(0.0000000000000000000999999999));
	printf("%.59f\n", ft_ln(0.0000000000000000000999999999));

	printf("%.59f\n", 5.1 * pow(10, -52));
	printf("%.59f\n", 5.1 * ft_powf_ip(10, -52));

	printf("%.59f\n", pow(0, -100));
	printf("%.59f\n", ft_powf_ip(0, -100));

	printf("%.59f\n", pow(1e-23, -100));
	printf("%.59f\n", ft_powf_ip(1e-23, -100));

	printf("%.59f\n", pow(1e-47, 10));
	printf("%.59f\n", ft_powf_ip(1e-47, 10));

	printf("!!! %.59f\n", log(52));
	printf("!!! %.59f\n", ft_ln(52));

	printf("%.59f\n", log10(1e+308));
	printf("%.59f\n", ft_log10(1e+308));

	printf("%.59f\n", log(965654234.432423432));
	printf("%.59f\n", ft_ln(965654234.432423432));

	printf("%.59f\n", log10(1e-308));
	printf("%.59f\n", ft_log10(1e-308));

	printf("%.59f\n", log10(1e-57));
	printf("%.59f\n", ft_log10(1e-57));

	printf("%.59f\n", exp(1e-24));
	printf("%.59f\n", ft_exp(1e-24));
	return (0);
}
*/