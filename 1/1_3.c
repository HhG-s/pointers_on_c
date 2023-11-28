#include <stdio.h>
#include <stdlib.h>


int main() {
	int ch;
	unsigned char checksum = 0;	/* 虽然书中给出的初始值为-1，但网上更普遍的说法为0，个人猜测可能与系统采用补码还是反码相关 */

	while ( ( ch = getchar()) != EOF ) {
		/* 计算检验和 */
		checksum += ch;
	}

	/* 对其取反获得校验值并打印 */
	/* 关于反码可参考 https://www.cnblogs.com/zhangziqiu/archive/2011/03/30/ComputerCode.htm */
	checksum = ~checksum;
	fprintf(stdout, "%d\n", checksum);

	return EXIT_SUCCESS;
}