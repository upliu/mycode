#include <stdio.h>

struct DEVIDE {
	int left;
	int right;
	int sum;
};

struct DEVIDE find_max_crossing_sub_array(int *a, int low, int mid , int high) {
	int left_sum = a[mid];
	int right_sum = a[mid];
	int i;
	int sum;
	struct DEVIDE d;
	for (i = mid, sum = 0; i >= low; i--) {
		sum  = sum + a[i];
		if (sum >= left_sum) {
			left_sum = sum;
			d.left = i;
		}
	}
	for (i = mid+1, sum = 0; i <= high; i++) {
		sum  = sum + a[i];
		if (sum >= right_sum) {
			right_sum = sum;
			d.right = i;
		}
	}
	d.sum = left_sum + right_sum;
	printf("%d %d %d\n", d.left, d.right, d.sum);
	return d;
}

struct DEVIDE find_max_sub_array(int *a, int low, int high) {
	struct DEVIDE d;
	if (low == high) {
		d.left = low;
		d.right = high;
		d.sum = a[low];
		return d;
	}
	int mid = (low + high) / 2;
	struct DEVIDE left = find_max_sub_array(a, low, mid);
	struct DEVIDE right = find_max_sub_array(a, mid+1, high);
	struct DEVIDE crossing = find_max_crossing_sub_array(a, low, mid, high);
	if (left.sum >= right.sum && left.sum >= crossing.sum) {
		return left;
	}
	if (right.sum >= left.sum && right.sum >= crossing.sum) {
		return right;
	}
	return crossing;
}

int main(int argc, char *argv[]) {
	int a[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	struct DEVIDE result = find_max_sub_array(a, 0, 15);
	printf("The max sum of sub array is %d, from %d to %d.", result.sum, result.left, result.right);
	return 0;
}
