#include <stdio.h>
#include <stdlib.h>

void peano(int level, int* x, int* y, int v, int h);

int main(int argc, char* argv[]) {
	int x, y, n;

	if (argc != 2) {
		fprintf(stderr, "\nUsage : %s <split level>\n\n", argv[0]);
		exit(1);
	}
	n = atoi(argv[1]);
	if (n < 1) {
		fprintf(stderr, "Error : split level is too small\n");
		exit(1);
	}

	x = y = 0;
	peano(n, &x, &y, 1, 1);
}

void peano(int level, int* x, int* y, int v, int h) {
	if (level == 1) {
		printf("(%d, %d)\n", *x, *y);
		*y += v;
		printf("(%d, %d)\n", *x, *y);
		*y += v;
		printf("(%d, %d)\n", *x, *y);
		*x += h;
		printf("(%d, %d)\n", *x, *y);
		*y -= v;
		printf("(%d, %d)\n", *x, *y);
		*y -= v;
		printf("(%d, %d)\n", *x, *y);
		*x += h;
		printf("(%d, %d)\n", *x, *y);
		*y += v;
		printf("(%d, %d)\n", *x, *y);
		*y += v;
		printf("(%d, %d)\n", *x, *y);
	}
	else {
		peano(level - 1, x, y,  v,  h);
		*y += v;
		peano(level - 1, x, y,  v, -h);
		*y += v;
		peano(level - 1, x, y,  v,  h);
		*x += h;
		peano(level - 1, x, y, -v,  h);
		*y -= v;
		peano(level - 1, x, y, -v, -h);
		*y -= v;
		peano(level - 1, x, y, -v,  h);
		*x += h;
		peano(level - 1, x, y,  v,  h);
		*y += v;
		peano(level - 1, x, y,  v, -h);
		*y += v;
		peano(level - 1, x, y,  v,  h);
	}
}