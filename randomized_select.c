#include <stdio.h>

void swap(int *a, int i, int j) {
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

int partition(int *a, int p, int r) {
	int i = p - 1;
	int x = a[r];
	int j;
	for (j = p; j < r; j++) {
		if (a[j] <= x) {
			i++;
			swap(a, i, j);
		}
	}
	swap(a, i+1, r);
	return i+1;
}


int randomized_select(int *a, int p, int r, int i) {
	if (p == r) {
		return a[p];
	}
	int q = partition(a, p, r);
	int k = q - p + 1;
	if (i == k) {
		return a[q];
	} else if (i < k) {
		return randomized_select(a, p, q-1, i);
	} else {
		return randomized_select(a, q+1, r, i-k);
	}
}

int main(int argc, char *argv[]) {
	int a[8] = {2, 4, 1, 8, 4, 2, 9, 7};
	printf("%d", randomized_select(a, 0, 7, 8));
	return 0;
}
