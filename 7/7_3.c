int ascii_to_int(char *string) {
	int num;
	int i = 0;
	int res = 0;

	while (string[i] != '\0') {
		num = string[i] - '0';
		if (0<=num && num<=9) {
			res = res*10 + num;
		}
		i++;
	}

	return res;
}