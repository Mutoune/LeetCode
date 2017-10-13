#include "stdio.h"
#include "stdlib.h"

int* twoSum(int* nums, int numsSize, int target) {
	int* res = (int*)malloc(2 * sizeof(short));
	for (int i = 0; i < numsSize; i++)
		for (int j = i + 1; j < numsSize; j++)
			if (nums[i] + nums[j] == target) {
				res[0] = i;
				res[1] = j;
			}
	return res;
}

//int main()
//{
//	int nums[4] = { 2, 7, 11, 15 };
//	int target = 9;
//	int* res = twoSum(nums, 4, 9);
//	printf("%d, %d\n", *res, *(res+1));
//	return 0;
//}