#include <stdarg.h>

int max_list(int n, ...) {
	int temp;
	int max = -1e5;
	va_list num_list;

	va_start(num_list, n);

	for (int i=0; i<n; i++) {
		temp = va_arg(num_list, int);
		if (temp < 0) {
			break;
		}
		else {
			max = max > temp ? max : temp;
		}
	}

	va_end(num_list);

	return max;
}