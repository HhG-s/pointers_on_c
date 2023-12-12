#include <stdint.h>
#include <stdio.h>

#define N 8

/* 由于对角线掩码的位数为2N-1，所以需适当调整 */
#if N > 8
#define int_n uint32_t
#elif N > 4
#define int_n uint16_t
#else
#define int_n uint8_t
#endif

#define true 1
#define false 0
typedef int bool;

// Function to check if placing a queen is safe
bool is_safe(int_n row_mask, int_n diag_mask1, int_n diag_mask2, int row, int col);
// Recursive function to place queens on the board
void solve_n_queens(int_n row_mask, int_n diag_mask1, int_n diag_mask2, int row, int* solutions_count);

int main() {
	int solutions_count = 0;

	// Solve with backtracking and bitmasks
	solve_n_queens(0, 0, 0, 0, &solutions_count);

	printf("Number of solutions: %d\n", solutions_count);

	return 0;
}


void solve_n_queens(int_n row_mask, int_n diag_mask1, int_n diag_mask2, int row, int* solutions_count) {
	if (row >= N) {
		(*solutions_count)++;
		return;
	}

	for (int i=0; i<N; i++) {
		if (is_safe(row_mask, diag_mask1, diag_mask2, row, i)) {
			row_mask |= 1 << i;	/* 从右往左摆放 */
			diag_mask1 |= 1 << (row - i + N-1);	/* 加上N-1使得row-i的范围刚好落在0到2N-2之间 */
			diag_mask2 |= 1 << (row + i);	/* 用函数来表示就是y=-x+b，可知y+x为常数 */
			solve_n_queens(row_mask, diag_mask1, diag_mask2, row+1, solutions_count);

			/* 拿走棋子 */
			row_mask &= ~(1<<i);
			diag_mask1 &= ~(1<<(row-i+N-1));
			diag_mask2 &= ~(1<<(row+i));
		}
	}
	return;
}

bool is_safe(int_n row_mask, int_n diag_mask1, int_n diag_mask2, int row, int col) {
	return !( row_mask & (1 << col) || diag_mask1 & (1 << (row-col + N-1))
		|| diag_mask2 & (1 << (row + col)));
}