#include <stdio.h>


enum triangle_type {
	/* 按照边的关系分类，依次为等边、等腰、不等边，优先级依次递减 */
	equilateral, isosceles, scalene
};

int is_triangle(int a, int b, int c);
enum triangle_type type_of_tri(int a, int b, int c);

int main() {
	int a;
	int b;
	int c;
	enum triangle_type res;

	fprintf(stdout, "Enter 3 nums with space as the spliter:\n");
	fscanf(stdin, " %d %d %d", &a, &b, &c);

	if (a <= 0 || b <= 0 || c <= 0) {
		fprintf(stderr, "Invalid Input!\n");
		return 1;
	}
	else if (!is_triangle(a, b, c) || !is_triangle(b, a, c) || !is_triangle(c, a, b)) {
		fprintf(stderr, "Not a trianlge!\n");
		return 1;
	}

	res = type_of_tri(a, b, c);
	switch (res) {
	case equilateral:
			fprintf(stdout, "An equilateral triangle!\n");
			break;
	case isosceles:
			fprintf(stdout, "An isosceles triangle!\n");
			break;
	case scalene:
			fprintf(stdout, "A scalene triangle!\n");
			break;
	}

	return 0;
}

/* 判断是否为三角形 */
int is_triangle(int a, int b, int c) {
	return (b + c) > a;
}

/* 判断类型 */
enum triangle_type type_of_tri(int a, int b, int c) {
	if (a == b && b == c) {
		return equilateral;
	}
	else if (a == b || b == c || a == c) {
		return isosceles;
	}
	else {
		return scalene;
	}
}