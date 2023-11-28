#include <stdio.h>
#include <stdbool.h>

int main() {
	int ch;
	bool paired;
	bool neglect;
	int left_count;		/* 统计{ */
	int right_count;	/* 统计} */

	paired = false;
	neglect = false;
	left_count = 0;
	right_count = 0;

	/* 读取源代码 */
	/* 为了简便起见，这里未处理的注释形式 */
	/* 当然这种方式有很明显的缺陷，即不能正确处理嵌套的情况，或许可以通过用char数组代替单个字符ch来实现更加精确的判断 */
	while ( ( ch = fgetc(stdin) ) != EOF ) {
		/* 通过取异或来判断是否相等，使用&&而非||是因为当取异或的结果为0(即false)时才有两数相等 */
		/* 发现了额外的问题，即转义字符中包含的嵌套，同上 */
		bool is_special = (ch == 39) || (ch == 34 ) || (ch == 47);

		/* 忽略特殊情况下的花括号 */
		if (neglect && is_special) {
			neglect = false;
			continue;
		}
		else if (is_special) {
			neglect = true;
		}

		if (neglect) {
			/* 如果处在特殊情况中则不读取 */
			continue;
		}
		else {
			switch (ch) {
			case '{':
				left_count++;
				break;
			case '}':
				right_count++;
				break;
			}
		}
	}
	paired = (left_count == right_count);
	
	if (paired) {
		fprintf(stdout, "correctly paired!\n");
	}
	else {
		fprintf(stdout, "fail to get all paired!\n");
	}

	return 0;

}