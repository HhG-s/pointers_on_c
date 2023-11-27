#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20		/* 所能处理的最大列号 */
#define MAX_INPUT 1000		/* 每个输入行的最大长度 */

int read_column_numbers( int [], int );
void rearrange( char*, char const*, int, int const[] );

int main() {
	int n_cols;		/* 储存区间 */
	int cols[MAX_COLS];
	char input[MAX_INPUT];
	char output[MAX_INPUT];

	/* 读取列标号 */
	n_cols = read_column_numbers(cols, MAX_COLS);

	/* 读取、处理和打印剩余的输入行 */
	while (fgets( input, MAX_INPUT, stdin )) {
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

	/* 列数为偶 
	** 除了一般取余的运算外，我们还可以通过按位与&操作来判断一个数是否为奇
	*/
	if ( num & 1 ) {
		fputs("Last column number is not paired", stderr);
		exit(EXIT_FAILURE);
	}

	/* 丢弃结束标志 */
	while ((ch = getchar()) != EOF && ch != '\n') {
		;
	}

	return num;
}

void
rearrange(char *output, char const *input, int n_cols, int const cols[]) {
	int col;
	int len;
	int output_col;

	len = strlen(input);
	output = 0;

	/* 处理每对列标号 */
	for (col = 0; col < n_cols; col += 2) {
		int nchars = cols[col+1] - cols[col] + 1;	/* 获取区间长度 */

		/* 如果输入行结束或者输出行已满则结束任务 */
		if (cols[col] >= len || 
		    output_col == MAX_COLS - 1) {
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