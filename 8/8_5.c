/* 注意到传入的是int*类型，所以不能进行诸如m1[i][j]的下标访问，需要人为地调整索引 */
void matix_multiply(int *m1, int *m2, int *r,
	int x, int y, int z) {
		for (int i=0; i<x; i++) {
			int factor = 0;
			for (int j=0; j<z; j++) {
				for (int k=0; k<z; k++) {
					factor += m1[i*y + k] * m2[k*z + j];
				
				}
				r[i*z + j] = factor;
			}
		}
}