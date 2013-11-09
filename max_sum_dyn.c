#include <stdio.h>

int max_sum_dyn(int *v, int n) {
	int sum = 0;
	int b = 0;
	int i;
	for (i = 1; i <= n; i++) {
		if (b > 0) {
			b += v[i];
		} else {
			b = v[i];
		}
		if (b > sum) {
			sum = b;
		}
	}
	return sum;
}

int main() {
	int v[9] = {2,-4,3,-5,6,-7,3,-4,9};
	printf("%d", max_sum_dyn(v, 9));
	return 0;
}
