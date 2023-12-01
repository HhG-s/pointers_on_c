#include <stdio.h>


int main() {
	int ch;

	while ( (ch = fgetc(stdin)) != EOF) {
		/* 注意换行符不会导致读取结束 */
		if ('A' <= ch && ch <= 'Z') {
			ch += ch - 13 < 'A' ? 13: -13;
		}
		else if ('a' <= ch && ch <= 'z') {
			ch += ch - 13 < 'z' ? 13: -13;
		}

		fputc(ch, stdout);
	}
}