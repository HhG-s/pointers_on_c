#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


/* 列主序 */
int array_offset2(int array_info[], ...) {
	/* 获取维数 */
	int dim = array_info[0];
	if (dim < 1 || dim > 10) {
		fprintf(stderr, "错误的维数！\n");
		return -1;
	}

	int offset = 0;
	/* 获取上下限 */
	int *low = calloc(dim, sizeof(int));
	int *high = calloc(dim, sizeof(int));
	if (low == NULL || high == NULL) {
		fprintf(stderr, "内存请求失败！\n");
		return -1;
	}

	for (int i=1; i<=dim*2; i+=2) {
		if (array_info[i] > array_info[i+1]) {
			fprintf(stderr, "上下限错误！\n");
			offset = -1;
			goto ret;
		}
		*(low++) = array_info[i];
		*(high++) = array_info[i+1];
	}
	low -= dim;
	high -= dim;

	/* 获取下标 */
	va_list var_sub;
	int subscript[10];

	va_start(var_sub, array_info);
	for (int i=0; i<dim; i++) {
		subscript[i] = va_arg(var_sub, int);
		if (subscript[i] < low[i] || subscript[i] > high[i]) {
			fprintf(stderr, "下标%d: %d不合法！！\n", i, subscript[i]);
			offset = -1;
			goto ret;
		}
	}
	va_end(var_sub);

	/* 计算偏移 */
	int i;
	for (i=dim-1; i>0; i++) {
		offset += (high[i] - low[i] + 1) * (subscript[i] - low[i]);
	}
	offset += subscript[i] - low[i];

	ret:
	free(low);
	free(high);
	return offset;
}