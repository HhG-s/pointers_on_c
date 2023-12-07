#include <stdio.h>
#include <stdarg.h>

int pows(int num, int x);
void print_int(int num);
void print_float(double num, int precison);
void print_string(char *str);
void simple_print(char *string, ...);

void simple_print(char *string, ...) {
	int i = -1;
	int flag = 0;
	va_list format;

	va_start(format, string);

	while (string[++i] != '\0') {
		if (string[i] == '%') {
			flag = 1;
			continue;
		}
		else if (!flag) {
			putchar(string[i]);
			continue;
		}

		switch (string[i]) {
		case 'c':
			putchar(va_arg(format, int));
			break;
		case 'd':
			print_int(va_arg(format, int));
			break;
		case 'f':
			/* 随便提供了一个精度，如果要指定的话还需读取其他说明符 */
			print_float(va_arg(format, double), 4);
			break;
		case 's':
			print_string(va_arg(format, char*));
			break;
		}
		flag = 0;
	}
}


void print_string(char *str) {
	int i = 0;

	while (str[i] != '\0') {
		putchar(str[i]);
		i++;
	}
}

void print_int(int num) {
	/* 可以通过不断mod 10以及除以10来依次取得末位数字，结束标志是商为0 */
	/* 因为得到的结果是逆序的，因此可以采用递归的方法输出 */
	if (num < 0) {
		putchar('-');
		num = -num;
	}

	if (num / 10 != 0) {
        	print_int(num / 10);
    	}
	putchar('0' + num % 10);
}

void print_float(double num, int precison) {
	/* 可以先处理整数部分(int 化) */
	/* 接着将小数部分乘上10的精度值次方并保留整数部分依照同样的逻辑进行处理 */
	int integer_part = (int)num;
	print_int(num);
	
	putchar('.');

	int fraction_part = (num - integer_part) * pows(10, precison);
	print_int(fraction_part);
}

int pows(int num, int x) {
	/* 只是个辅助函数所以功能不完善 */
	int res = num;

	for (int i=1; i<x; i++) {
		res *= num;
	}

	return res;
}

#ifdef DEBUG
int main() {
	int i = 1314;
	char a[] = "Hello World!";
	double pi = 3.1415936;
	
	simple_print("pi is %f, and say %s, i is %d", pi, a, i);
	return 0;
}
#endif