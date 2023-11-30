#include <stdio.h>
#define MAX 100

struct flags {
	/* 采用位域可以节省内存 */
	unsigned flag : 1;
};

int main() {
	int n;
	struct flags f;


	for (n=1; n<=MAX; n++) {
		int i;
		f.flag = 0;		
		
		for (i=1; i<n/2; i++) {
			if (n % i == 0 && i != 1) {
				f.flag = 1;
			}
		}
		if (!f.flag) {
			/* 如果为素数则打印 */
			fprintf(stdout, "%d ", n);
		}
	}
}