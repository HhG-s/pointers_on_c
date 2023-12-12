/* 可参考https://www.hello-algo.com/chapter_backtracking/n_queens_problem/ */
#include <stdio.h>

#define N 8
#define true 1
#define false 0
typedef int bool;

/* 验证解法种数 */

bool is_safe(int board[N][N], int row, int col)
{
	/* 因为按照从上到下的行序放置皇后，所以只需检查来自先前的冲突，即棋盘上部可能带来的限制 */
	// 检查列
	for (int x = 0; x < row; x++)
		if (board[x][col])
			return false;
	// 检查左上主对角线
	for (int x = row, y = col; x >= 0 && y >= 0; x--, y--)
		if (board[x][y])
			return false;
	// 检查右上副对角线
	for (int x = row, y = col; x >= 0 && y < N; x--, y++)
		if (board[x][y])
			return false;
	return true;
}

void solveNQueens(int board[N][N], int row, int *count)
{
	if (row >= N) {
		(*count)++;
		/* 共有92种解法，打印基本没什么用 */
		// for (int i = 0; i < N; i++) {
		// 	for (int j = 0; j < N; j++)
		// 		printf("%d ", board[i][j]);
		// 	putchar('\n');
		// }
		// putchar('\n');
		return;
	}
	for (int col = 0; col < N; col++) {
		if (is_safe(board, row, col)) {
			board[row][col] = 1;
			solveNQueens(board, row + 1, count);
			board[row][col] = 0;
		}
	}
}

int main()
{
	int count = 0;
	int board[N][N] = { [0 ... N-1][0 ... N-1] = 0};
	solveNQueens(board, 0, &count);
	printf("Number of solutions: %d\n",count);
	return 0;
}
