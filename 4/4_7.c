void deblank(char str[]) {
	int i;
	int j;
	unsigned int is_consecutive = 0;

	for (i=0, j=0; str[i] != '\0'; i++) {
		if (str[i] != ' ') {
			str[j++] = str[i];
			is_consecutive = 0;
		}
		else if (!is_consecutive) {
			str[j++] = ' ';
			is_consecutive = 1;
		}
	}
	str[j] = '\0';
}