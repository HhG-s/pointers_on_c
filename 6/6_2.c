
int in_str(char *str, const char *substr) {
	/* 从开头开始比较 */
	
	int i = 0;	/* 用于后续还原str和substr */
	int res = 0;

	while (*substr != '\0' && *str == *substr) {
		i++;
		str++;
		substr++;
	}

	if (*substr == '\0') {
		res = 1;
	}

	str -= i;
	substr -= i;

	return res;
}

int del_substr(char *str, const char *substr) {
	int i = 0; 
	int j = 0;
	int len = 0;
	int res = 0;

	/* 获取长度 */
	while (*substr != '\0') {
		len++;
		substr++;
	}
	substr -= len;

	while (*str != '\0') {
		if (in_str(str, substr)) {
			/* 删除 */
			/* 可以调用库函数memmove一键迁移 */
			while (*substr != '\0') {
				*(str+j) = *(str+j+len);
				j++;
				substr++;
			}
			res = 1;
			goto ret;
		}
		i++;
		str++;
	}

	ret:
	str -= i;
	return res;
}