#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = (int *)malloc(sizeof(int) * n1);
	int *R = (int *)malloc(sizeof(int) * n2);
	int k;
	int i;
	int j;
	// 初始化 L 和 R 数组
	for (i = 0; i < n1; i++) {
		L[i] = a[p+i];
	}
	for (i = 0; i < n2; i++) {
		R[i] = a[q+i+1];
	}
	for (k = p, i = 0, j = 0; i < n1 && j < n2; k++) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			j++;
		}
	}
	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n1) {
		a[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int *a, int p, int r) {
	if (p < r) {
		int q = (p+r) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q+1, r);
		merge(a, p, q, r);
	}
}

int main(int argc, char *argv[]) {
	int a[7] = {4,5,2,8,6,3,7};
	merge_sort(a, 0, 6);
	int i;
	for (i = 0; i < 7; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
