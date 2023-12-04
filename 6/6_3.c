/* 可以使用递归的方法，但此处的函数声明需要修改，这种调用递归的方法可以帮助理解堆栈的概念即先进后出 */

void revese_string(char *str) {
	char *last_str = str;
	
	/* 设定到字符串尾部(不包括\0) */
	while (*(last_str++) != '\0') {
		;
	}
	last_str -= 2;

	/* 逆序直到两个指针相交 */
	while (str < last_str) {
		char temp;
		temp = *str;
		*str++ = *last_str;
		*last_str-- = temp;
	}

	/* 以上是作者的实现，但是返回的str的索引显然不是0，即第一项，因此应该加入变量i的追踪str的偏移量 */
}