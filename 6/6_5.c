// #include <stdio.h>
#include <stdlib.h>
#define TYPE_LEN 32


int get_index(int num);
int get_len(int limit);
int num_to_order(int num);
unsigned clear_bit(unsigned *num, unsigned i);
unsigned access_bit(unsigned num, unsigned i);

unsigned *eratosthenes_sieve(int limit) {
	/* 计算数组长度 */
	/* 此方法默认unsigned的长度为 TYPE_LEN bit */

	int i;
	int j;
	int len;

	int index = 0;
	int start = 3;		/* 起始点 */
	len = get_len(limit);
	unsigned *res = calloc(len, sizeof(unsigned));


	for (i=0; i<len; i++) {
		res[i] = 0xffffffff;
	}
	res[0] >>= 1;	/* 把一设置为0 */

	/* 当i*i大于上限时，可以知道对所有的i+1，其i+1以前的因子都已经被处理，而i+1倍又大于上限，无法再进行处理 */
	/* 故终止条件可设为i的平方小于等于上限 */
	/* 此处的i代表的是奇数的值 */
	for (i = start; i*i<=limit; i+=2) {

		/* 由于目标是减少内存占用所以这里没有引入中间变量来使得算法更加清晰 */
		/* access_bit的第二个参数为通过奇数的值得到的它在一个 TYPE_LEN bit的二进制数中的位置 */
		if (access_bit(res[get_index(i)], num_to_order(i) )) {

			/* 由于所有的i-1因子都被消去，所以j可以从i*i开始取 */
			/* 由于只有奇数，所以应该略去偶数倍 */
			for (j = i*i; j<=limit; j+=2*i) {
				clear_bit(res + get_index(j), num_to_order(j) );
			}
		}
	}
	return res;
}

int num_to_order(int i) {
	int res = ((i+1)/2) % TYPE_LEN ? (i+1)/2 % TYPE_LEN : TYPE_LEN;
	return res;
}

int get_index(int num) {
	int res = (++num) / 2 / TYPE_LEN;
	return res;
}

unsigned clear_bit(unsigned *num, unsigned i) {
	/* 将指定位清零  */
	*num &= ~(1u << (TYPE_LEN-i));
	return *num;
}

unsigned access_bit(unsigned num, unsigned i) {
	/* 如果指定位为0则返回0 */
	unsigned res = (1u << (TYPE_LEN-i)) & num;
	return res;
}

int get_len(int limit) {
	/*获取数组长度 */
	int len;
	len = limit % TYPE_LEN == 0? limit / TYPE_LEN: limit / TYPE_LEN + 1;
	len = len - len / 2;	/* 只保留奇数 */
	return len;
}

int main() {
	/* 当达到1e8时有明显卡顿 2.067s */
	/* 内存占用约为5MB */
	/* 如果想进行更大的测试请调整值的类型否则会收到segmentation fault */
	int limit = 1e8;
	unsigned *prime = eratosthenes_sieve(limit);

	// for (int i=0; i<get_len(limit); i++) {
	// 	printf("%#X ", prime[i]);
	// }

	free(prime);
}