#include <stdio.h>

#if _TIME_BITS == 64
int __attribute__((weak)) __gentoo_time32 = 0;
int __gentoo_time64 = 1;
#else
int __gentoo_time32 = 1;
int __attribute__((weak)) __gentoo_time64 = 0;
#endif

__attribute__((constructor))
static void __gentoo_check_time_bits()
{
	printf("time32 = %d, time64 = %d\n", __gentoo_time32, __gentoo_time64);
}
