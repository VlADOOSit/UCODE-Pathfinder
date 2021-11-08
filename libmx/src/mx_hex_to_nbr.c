#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long result = 0;
	unsigned long temp = 1;
	int size = 0;

	if (hex != NULL) {
		while (hex[size]) {
			size++;
        }
    }
	else {
		return result;
    }
	for (int i = 0; i <= size; i++) {
		if (hex[size - i] >= '0' && hex[size - i] <= '9') {
			result = result + (hex[size - i] - 48) * temp;
			temp = temp * 16;
		}
		if (hex[size - i] >= 'A' && hex[size - i] <= 'F') {
			result = result + (hex[size - i] - 55) * temp;
			temp = temp * 16;
		}
		if (hex[size - i] >= 'a' && hex[size - i] <= 'f') {
			result = result + (hex[size - i] - 87) * temp;
			temp = temp * 16;
		}
	}
	return result;
}
