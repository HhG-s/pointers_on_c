short identity_matrix(int arr[10][10]) {
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			if ( i == j && arr[i][j] != 1 ) {
				return 0;
			}
			else if (i != j && arr[i][j] != 0) {
				return 0;
			}
		}
	}

	return 1;
}