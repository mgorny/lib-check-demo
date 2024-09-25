#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#if _TIME_BITS == 64
int __gentoo_time64 = 1;
#else
int __gentoo_time32 = 1;
#endif

__attribute__((constructor))
static void __gentoo_check_time_bits()
{
	void *time32_sym = dlsym(RTLD_DEFAULT, "__gentoo_time32");
	void *time64_sym = dlsym(RTLD_DEFAULT, "__gentoo_time64");

	if (time32_sym != NULL && time64_sym != NULL) {
		fprintf(stderr,
				"Both time32 and time64 libraries found in link chain. "
				"This likely indicates ABI incompatibility. Please make "
				"sure to rebuild all the executables against the same ABI.\n");
		abort();
	}
}
