/* 一个个赋值太麻烦了 */
char value[3][6][4][5] = {
	// Initialize all positions to 0
	[0 ... 2][0 ... 5][0 ... 3][0 ... 4] = 0,

	// Initialize positions mentioned in the table
	[1][2][2][3] = 'A',
	[2][4][3][2] = '3',
	[2][4][3][3] = '3',
	[2][1][1][2] = 0320,
	[1][1][1][1] = ' ',
	[1][4][2][3] = '\n',
	[2][5][3][4] = 125,
	[2][2][2][2] = '\'',
	[1][3][2][2] = 0xf3,
	[2][2][3][1] = '\121',
	[1][2][3][4] = 'x',
	[2][2][1][1] = '0',
};