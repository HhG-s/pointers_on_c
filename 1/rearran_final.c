#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20		/* 所能处理的最大列号 */
#define MAX_INPUT 1000		/* 每个输入行的最大长度 */

int read_column_numbers( int [], int );
void rearrange( char*, char const*, int, int [] );

int main() {
	int n_cols;		/* 储存区间 */
	int cols[MAX_COLS];
	char input[MAX_INPUT];
	char *output = calloc(MAX_COLS, sizeof(char));

	/* 读取列标号 */
	n_cols = read_column_numbers(cols, MAX_COLS);
	/* 处理列数为奇的情况 */
	if (n_cols & 1) {
		cols[n_cols] = MAX_INPUT-1;
	}

	/* 读取、处理和打印剩余的输入行 */
	while (fgets( input, MAX_INPUT, stdin ) != NULL &&
		strcmp(input, "\n")) {
			
		fprintf( stdout, "Original input: %s\n", input );
		rearrange(output, input, n_cols, cols);
		fprintf( stdout, "Rearranged line: %s\n", output );
	}

	return EXIT_SUCCESS;
}

/* 读取列标号，如果超过规定范围则忽略 */
int
read_column_numbers( int cols[], int max ) {
	int ch;		/* 采用int而不是char是因为ch可能为EOF(-1) */
	int num = 0;

	/* 取得列标号直到所读取的数小于0 */
	while ( num < max && scanf(" %d", cols+num) == 1
		&& cols[num] >= 0 ) {
		num++;
	}


	/* 丢弃结束标志 */
	while ((ch = getchar()) != EOF && ch != '\n') {
		;
	}

	return num;
}

void
rearrange(char *output, char const *input, int n_cols, int cols[]) {
	int col;
	int len;
	int nchars;
	int output_col;

	len = strlen(input);
	nchars = 0;
	output_col = 0;

	/* 处理每对列标号 */
	for (col = 0; col < n_cols; col += 2) {
		/* 解决列非升序排列问题 */
		if (cols[col+1] < cols[col]) {
			/* 如果非升序则交换两列位置 */
			cols[col] ^= cols[col+1];
			cols[col+1] ^= cols[col];
			cols[col] ^= cols[col+1];
		}

		nchars = cols[col+1] - cols[col] + 1;

		/* 如果行数过长则跳过 */
		if (cols[col] > len) {
			continue;continue;
		}

		/* 如果输出行已满则结束任务 */
		if (output_col == MAX_COLS - 1) {
			break;
		}

		/* 如果输出行数据空间不够则只复制可容纳的数据 */
		if (output_col + nchars > MAX_INPUT - 1) {
			nchars = MAX_INPUT - output_col - 1;
		}

		/* 复制相关数据 */
		strncpy(output+output_col, input+cols[col], nchars);
		output_col += nchars;
	}

	output[output_col] = '\0';
}