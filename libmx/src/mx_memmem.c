#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    unsigned char *result = NULL;
    unsigned char *buff = NULL;

    if (big_len > 0 && little_len > 0 && big_len >= little_len) {
		result = (unsigned char *)big;
		buff = (unsigned char *)little;
		while (*result) {
			if (mx_memcmp(result, buff, little_len - 1) == 0)
				return result;
			result++;
		}
	}
	return NULL;
}
