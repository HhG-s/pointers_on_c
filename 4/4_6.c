int substr(char dst[], char src[], int start, int len) {
	/* 请调用者自行保证dst不会越界 */
	int i = -1;
	src += start;

	while (src[++i] != '\0') {
		dst[i] = src[i];
		if (len <= i+1) {
			break;
		}
	}
	
	dst[++i] = '\0';
	src -= start;

	return i;
}