#include <stdio.h>
#include <stdlib.h>

#define DEBUG

char *eratosthenes_sieve(int limit) {
	int i;
	int j;
	char start = 2;		/* 起始点 */
	char *res = calloc(limit + 1, sizeof(char));


	for (i=0; i<=limit; i++) {
		res[i] = 1;
	}
	/* 设定未处理的部分，建议进行打印时从索引1开始 */
	res[0] = 0;
	res[1] = 0;

	/* 当i*i大于上限时，可以知道对所有的i+1，其i+1以前的因子都已经被处理，而i+1倍又大于上限，无法再进行处理 */
	/* 故终止条件可设为i的平方小于等于上限 */
	for (i = start; i*i<=limit; i++) {
		if (res[i]) {
			/* 由于所有的i-1因子都被消去，所以j可以从i*i开始取 */
			for (j = i*i; j<=limit; j+=i) {
				res[j] = 0;
			}
		}
	}
	return res;
}

int get_number(char *prime, int n) {
	int res = 0;
	for (int i=0; i<n; i++) {
		if (prime[i]) {
			res++;
		}
	}

	return res;
}

#ifdef DEBUG
int main() {
	/* 1e8时耗时1.926s */
	/* 内存占用约为95MB */
	int limit = 0;
	int number = 0;

	while ((limit += 1000) <= 1000000) {
		char *prime = eratosthenes_sieve(limit);

		int temp = get_number(prime, limit+1);

		printf("%d ", temp-number);
		number = temp;

		free(prime);
		fflush(stdout);
	}

}
#endif