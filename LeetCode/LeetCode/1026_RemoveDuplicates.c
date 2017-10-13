#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0) return 0;
	int size = 1;
	int point = 1;
	while (point < numsSize) {
		if (nums[point] != nums[point - 1]) {
			nums[size] = nums[point];
			size++;
		}
		point++;
	}
	return size;
}

int main() {
	int nums[] = {1, 1, 2};
	int length = removeDuplicates(nums, 3);
	printf("%d\n", length);
	for (int i = 0; i < length; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}