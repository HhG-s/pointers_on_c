#include <stdio.h>
#include <stdlib.h>
// #define DEBUG

int copy_n(char dst[], char src[], int n) {
	/* !请确保dst的大小至少为n */
	if (dst == NULL || src == NULL) {
		return 1;
	}


	/* 进行复制，此处假定src是一个标准的字符串，即采用\0结尾 */
	int i = -1;
	while (src[++i] != '\0') {
		dst[i] = src[i];
	}

	if (i >= n-1) {
		return 0;
	}

	for (; i < n; i++) {
		dst[i] = '\0';
	}
	return 0;

}

#ifdef DEBUG

int main() {
	char s1[100];
	char s2[] = "Hello World!";

	copy_n(s1, s2, 100);
	fputs(s1, stdout);

	return 0;
}

#endif