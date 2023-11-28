#include <stdio.h>
#include <stdlib.h>

int main() {
	char ch;
	int max_i;
	int cur_i;
	FILE * fp;
	long long cur_len;
	long long max_len;

	max_i = 0;
	cur_i = 0;
	max_len = 0;
	cur_len = 0;

	/* 指定读取的文件 */
	fp = fopen("test_file", "r");


	while ( !feof(fp) ) {
		/* 逐个字节读取 */
		fread_unlocked(&ch, sizeof(char), 1, fp);

		/* 如果读取到换行符 */
		switch (ch) {
		case '\n':
			/* 寻找并定位最大行 */
			if (max_len < cur_len) {
				max_len = cur_len;
				max_i = cur_i;
			}
			cur_i++;
			cur_len = 0;
			break;
		default:
			cur_len++;
			break;
		}
	}

	rewind(fp);	/* 重新开始读取 */

	/* 进行输出 */
	fprintf(stdout, "%lld: ", max_len);

	int j = 0;
	while (j++ < max_i) {
		/* 跳转到最大行 */
		fgets(&ch, 0, fp);
	}
	/* 输出最大行内容 */
	while (fread_unlocked(&ch, sizeof(char), 1, fp)) {
		fputc_unlocked(ch, stdout);

		if (ch == '\n') {
			break;
		}
	}

	return EXIT_SUCCESS;
}