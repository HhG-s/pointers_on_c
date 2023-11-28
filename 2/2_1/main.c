#include <stdio.h>
#include "negate.c"
#include "increment.c"


int main() {
	int test[] = {10, 0, -10};

	for (int i=0; i<3; i++) {
		fprintf(stdout, "Original:  %d\n", test[i]);
		fprintf(stdout, "Incremented: %d\n", increment(test[i]));
		fprintf(stdout, "Negated: %d\n", negate(test[i]));
	}
}