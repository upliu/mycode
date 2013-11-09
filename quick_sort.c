#include <stdio.h>
// 交换数组下标为	 和 j 的元素的值
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

void quick_sort(int *a, int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quick_sort(a, p, q-1);
		quick_sort(a, q+1, r);
	}
}

int main() {
	int a[7] = {4,5,2,8,6,3,7};
	int i;
	quick_sort(a, 0, 6);
	for (i = 0; i < 7; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
