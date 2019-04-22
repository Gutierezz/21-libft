# include "ft_printf.h"

#include <stdio.h>
static void print_doublebits(long double x)
{
	unsigned char * desmond = (unsigned char *) &x;
	int i;

	for (i = sizeof(long double) - 1 ; i >= 0 ; i--) {
		printf ("%02X ", desmond[i]);
	}

	printf ("\n");
}


static void print_fltbits(double x)
{
	unsigned char * desmond = (unsigned char *) &x;
	int i;

	for (i = sizeof(double) - 1 ; i >= 0 ; i--) {
		printf ("%02X ", desmond[i]);
	}

	printf ("\n");
}

static void print_ubits(uint64_t x)
{
	unsigned char * desmond = (unsigned char *) &x;
	int i;

	for (i = sizeof(uint64_t) - 1; i >=0 ; i--) {
		printf ("%02X ", desmond[i]);
	}

}

int main()
{
	setlocale(LC_ALL, "");
/*
	decimal_checker();
	unsigned_decimal_checker();
	hex_checker();
	octal_checker();
	char_checker();
float_checker();
	str_checker();
ptr_checker();
 extra_check();
 exp_check();
*/
/*
	wchar_t *str = L"ααααααααααααα";

	int ret2 = printf("da\x05s\rjdkl\vsad\tsalk");
	printf("\n");
	int ret1 = ft_printf("%r", "da\x05s\rjdkl\vsad\tsalk");
	ft_printf("\norig : %d\nmine : %d\n", ret2, ret1);

	ft_putstr("'");
	double a = -1.000000;
 */

//	ft_printf("my: %.2e|\n", 999999.01);
//	printf("og: %.2e|\n", 999999.01);
//	ft_printf("my: %.0le|\n", 99999999.1213);
//	printf("og: %.0le|\n", 99999999.1213);


	int ret1 = ft_printf("%lс", L'\u§1F43');
	printf("\n");
	int ret2 = printf("%lc", L'\u1F43');
	printf("\nmy: %d \nog: %d \n", ret1, ret2);
	return (0);
}
