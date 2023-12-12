float single_tax(float income) {
	float res = 0.f;


	if (income <= 0.f) {
		;
	}
	else if (income <= 23350.f) {
		res = income * 0.15f;
	}
	else if (income <= 56550.f) {
		res = income * 0.28f + 3502.50f;
	}
	else if (income <= 117950.f) {
		res = income * 0.31f + 12798.50f;
	}
	else if (income <= 256500.f) {
		res = income * 0.36f + 31832.50f;
	}
	else {
		res = income * 0.396f + 81710.50f;
	}

	return res;
}