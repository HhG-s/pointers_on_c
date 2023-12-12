#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// unsigned my_pow(unsigned x, unsigned y);	/* 引入math.h还要链接有点麻烦，所以直接写一个幂函数吧 */
void int_to_str(unsigned amount, char *buffer);

void written_amount(unsigned amount, wchar_t *buffer) {
	/* 使用中文的计数方法 */
	wchar_t *res = buffer;		/* 防止找不到数组头 */
	static const wchar_t unit[] = L"元拾佰仟萬億";
	static const wchar_t num[] = L"零壹贰叁肆伍陆柒捌玖";

	char str_amount[11];	/* 仅支持到十亿（unsigned的限制） */
	int_to_str(amount, str_amount);

	char *index = str_amount;
	unsigned len = strlen(str_amount);
	const unsigned length = len;	/* 保存长度 */

	int value;

	/* 进行分段处理 */

	while (len>9) {
		value = *(index++)-'0';
		if (value) {
			*(res++) = num[value];
			*(res++) = unit[len-9];
		}
		else if (len == 10 && *index != '0') {
			*(res++) = L'零';
		}

		len--;
	}

	while (len>5) {
		value = *(index++)-'0';
		if (len == 9) {
			if (value) {
				*(res++) = num[value];
			}
			*(res++) = L'億';			
		}
		else if (value) {
			*(res++) = num[value];
			*(res++) = unit[len-5];		/* 当数值达到亿级时需单独设定单位 */
		}
		else if (len == 6 && *index != '0') {
			*(res++) = L'零';
		}
		len--;
	}

	while (len>0) {
		value = *(index++)-'0';
		if (value) {
			*(res++) = num[value];
			*(res++) = unit[len-1];
		}
		else if (len == 5) {
			*(res++) = L'萬';
		}
		else if (len != length && len == 2) {
			*(res++) = L'零';
		}
		else if (len == 1) {
			*(res++) = L'元';
		}

		len--;
	}

}

#ifdef DEBUG
int main() {
	setlocale(LC_ALL, "");
	wchar_t buffer[100];
	written_amount(3123456789, buffer);
	wprintf(buffer);
}
#endif

void int_to_str(unsigned n, char *buffer) {
	int i = 0;
	while (n != 0) {
		/* 先获得逆序的字符串 */
		*(buffer + i++) = n % 10 + '0';
		n /= 10;
	}

	/* 反转得到正确的字符串 */
	int len = i;
	char *res = calloc(i, sizeof(char));
	while (i--) {
		*(res+len-i-1) = *(buffer+i);
	}
	strcpy(buffer, res);
}

// unsigned my_pow(unsigned x, unsigned y) {
// 	/* 舍弃了不必要的功能 */
// 	unsigned res = 1;
// 	while (y--) {
// 		res *= x;
// 	}
// 	return res;
// }