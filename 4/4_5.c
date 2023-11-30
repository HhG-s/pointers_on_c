#include <stdio.h>
#include <string.h>

#define MAX_LEN 128
#define IN_STREAM stdin

/* 建议通过文件读取，在控制台的可视性比较差，容易混淆输入输出 */

int main() {
	char pre_line[MAX_LEN];
	char cur_line[MAX_LEN];

	/* 初始化第一行 */
	if (fgets(pre_line, MAX_LEN, IN_STREAM) == NULL) {
		return 1;
	}

	while (fgets(cur_line, MAX_LEN, IN_STREAM) != NULL) {
		if (!strcmp(cur_line, pre_line)) {
			fprintf(stdout, "%s", cur_line);
		}
		strcpy(pre_line, cur_line);
	}
}