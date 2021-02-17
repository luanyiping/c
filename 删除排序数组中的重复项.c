#include<stdio.h>
int removeDuplicates(int* nums, int numsSize) 
{
    int p = 0;
    int q = 1;
    if (numsSize == 0)
    {
        return 0;
    }
    while (q < numsSize)
    {
        if (nums[p] != nums[q])
        {
            nums[++p] = nums[q];
        }
        q++;
    }
    return p + 1;
}
int main()
{
    int arr[] = { 1,1,1,1,1,2,2,2,2,2,3,3,4};
    int len = removeDuplicates(arr, 13);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}
