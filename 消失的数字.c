 // ����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
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