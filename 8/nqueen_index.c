/* 采用索引压缩的方法实现 */
#include <stdio.h>

#define N 8

#define true 1
#define false 0
typedef int bool;

bool is_safe(signed char queen[], int row, int col);
void solve_n_queens(signed char queen[], int row, int *solutions);

int main() {
	int solutions = 0;
	signed char queen[N] = {[0 ... N-1] = -1};
	solve_n_queens(queen, 0, &solutions);
	printf("Number of solution is: %d\n", solutions);
}

void solve_n_queens(signed char queen[], int row, int *solutions) {
	if (row >= N) {
		(*solutions)++;
		return;
	}
	for (int col=0; col<N; col++) {
		if (is_safe(queen, row, col)) {
			queen[row] = col;
			solve_n_queens(queen, row+1, solutions);
			/* 不需要重新放置，因为默认只检查到当前行 */
		}
	}
	return;
}

bool is_safe(signed char queen[], int row, int col) {
	/* 这里依然是运用函数的思想来检查对角 */
	int diag1 = row + col;
	int diag2 = row - col;
	for (int i=0; i<row; i++) {
		if (queen[i] == col) {
			return false;
		}
		else if (i + queen[i] == diag1) {
			return false;
		}
		else if (i - queen[i] == diag2) {
			return false;
		}
	}

	return true;
}