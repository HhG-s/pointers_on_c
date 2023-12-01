#include <stdio.h>


int main() {
	int ch;

	while ( (ch = fgetc(stdin)) != EOF) {
		/* 注意换行符不会导致读取结束 */
		if ('A' <= ch && ch <= 'Z') {
			ch -= ('A' - 'a');
		}

		fputc(ch, stdout);
	}
}