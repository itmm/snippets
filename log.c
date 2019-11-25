#include <math.h>
#include <stdio.h>

int values[] = {
	20, 50, 100, 200, 500, 1000,
	2000, 3000, 4000, 5000, 10000,
	20000
};

int main() {
	int cnt = sizeof(values)/sizeof(*values);
	double mn = log(values[0]);
	double mx = log(values[cnt - 1]);
	int wd = 1320;

	for (int i = 0; i < cnt; ++i) {
		double v = log(values[i]);
		int x = (v - mn)/(mx - mn) * wd + 0.5;
		printf("%d: x(%d) == %d\n", i, values[i], x);
	}
}
