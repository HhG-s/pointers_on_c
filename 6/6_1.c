const char *find_char(const char *src, const char *chars) {
	if (src == 0 || chars == 0) {
		return 0;
	}

	int i;
	int j = 0;
	const char *res = 0;

	while (*src != '\0') {
		i = 0;

		while (*chars != '\0') {
			if (*chars == *src) {
				res = src;
				chars -= i;
				goto ret;
			}

			i++;
			chars++;
		}

		j++;
		src++;
		chars -= i;
	}

	ret:
	src -= j;
	return res;
}