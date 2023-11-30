#include <stdio.h>
#define ECLIPSE 1e-30

int main() {
	double n;
	double a;
	double a_next;

	scanf("%lf", &n);
	a_next = 1.;

	do {
		a = a_next;
		a_next = (a + n/a) / 2;
	}while (a != a_next);

	printf("%lf\n", a_next);
}