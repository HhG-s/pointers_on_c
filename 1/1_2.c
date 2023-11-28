#include <stdio.h>
#include <stdbool.h>

int main() {
	int ch;
	int row = 0;
	bool at_beginning = true;


	/* 循环至读取到结束符EOF */
	while ((ch = getchar()) != EOF) {

		if (at_beginning) {
			row++;
			at_beginning = false;
			fprintf(stdout, "%d: ", row);
		}
		
		/* 为了去掉行长度的限制，逐个打印字符 */
		fprintf(stdout, "%c", ch);

		/* 遇到换行符时使得行数加1 */
		if (ch == '\n') {
			at_beginning = 1;
		}

	}
}