short identity_matrix(unsigned ndim, int arr[ndim][ndim]) {
	for (int i=0; i<ndim; i++) {
		for (int j=0; j<ndim; j++) {
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