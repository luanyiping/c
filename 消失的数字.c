 // 数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
#include<stdio.h>
int missingnumber(int* nums, int numssize)
{
	int ans = numssize;
	int i = 0;
	for (i = 0; i < numssize; i++)
	{
		ans ^= nums[i];
		ans ^= i;
	}
	return ans;
}
int main()
{
	int arr[3] = { 3,0,1 };
	printf("%d\n", missingnumber(arr, 3));
}