#include <iostream>

#define N 10

using namespace std;

int a[N] = { 7, 5, 2, 8, 9, 0, 4, 6, 1, 3 };

void output()
{
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void swap(int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void mergeSortMerge(int left, int mid, int right)
{
	int Llen = mid - left + 1;
	int Rlen = right - mid;
	int *L = new int[Llen + 1];
	int *R = new int[Rlen + 1];
	for (int i = left; i <= mid; i ++) {
		L[i - left] = a[i];
	}
	for (int i = mid + 1; i <= right; i ++) {
		R[i - mid - 1] = a[i];
	}
	L[Llen] = R[Rlen] = INT_MAX;
	int i = 0;
	int j = 0;
	for (int k = left; k <= right; k++) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			j++;
		}
	}
	delete[] L;
	delete[] R;
}

void mergeSort(int left, int right)
{
	if (left < right) {
		// equals (left + right) / 2 , but can stop integer overflow
		int q = (right - left) / 2 + left;
		mergeSort(left, q);
		mergeSort(q + 1, right);
		mergeSortMerge(left, q, right);
	}
}

int quickSortPartition(int left, int right)
{
	int pivotValue = a[right];
	int firstBiggerIndex = left;
	for (int i = left; i <= right; i ++) {
		if (a[i] < pivotValue) {
			swap(i, firstBiggerIndex);
			firstBiggerIndex ++;
		}
	}
	swap(firstBiggerIndex, right);
	return firstBiggerIndex;
}

void quickSort(int left, int right)
{
	if (left < right) {
		int q = quickSortPartition(left, right);
		quickSort(left, q - 1);
		quickSort(q + 1, right);
	}
}

void selectSort()
{
	for (int curPos = 0; curPos < N - 1; curPos ++) {
		int indexOfMin = curPos;
		for (int right = curPos + 1; right < N; right ++) {
			if (a[indexOfMin] > a[right]) {
				indexOfMin = right;
			}
		}
		if (curPos != indexOfMin) {
			swap(curPos, indexOfMin);
		}
	}
}

void insertSort()
{
	for (int curPos = 1; curPos < N; curPos ++) {
		int curVal = a[curPos];
		int left = curPos - 1;
		while (left >= 0 && a[left] > curVal) {
			a[left + 1] = a[left];
			left --;
		}
		a[left + 1] = curVal;
	}
}

void bubbleSort()
{
	for (int left = 0; left < N - 1; left++) {
		for (int right = left + 1; right < N; right++) {
			if (a[left] > a[right]) {
				swap(left, right);
			}
		}
	}
}

int main()
{
	output();
	// bubbleSort();
	// insertSort();
	// selectSort();
	// quickSort(0, N - 1);
	mergeSort(0, N - 1);
	output();
	return 0;
}
