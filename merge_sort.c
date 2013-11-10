#include <stdio.h>
#include <stdlib.h>

#define INFINITY 999999999

void merge(int *a, int p, int q, int r) {
	int n1 = q - p + 2;
	int n2 = r - q + 1;
	int *L = (int *)malloc(sizeof(int) * n1);
	int *R = (int *)malloc(sizeof(int) * n2);
	int k;
	int i;
	int j;
	// 初始化 L 和 R 数组
	for (i = 0; i < n1-1; i++) {
		L[i] = a[p+i];
	}
	for (i = 0; i < n2-1; i++) {
		R[i] = a[q+i+1];
	}
	// 最后一个元素无穷大，设为哨兵
	L[n1-1] = R[n2-1] = INFINITY;
	for (k = p, i = 0, j = 0; k <= r; k++) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			j++;
		}
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
