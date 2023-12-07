int gcd(int m, int n) {
	if (m <= 0 || n <= 0) {
		return 0;
	}
	
	/* n和m的相对大小不会影响结果 */
	return m % n == 0 ? n : gcd(n, m % n);
}