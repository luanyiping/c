int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
    int ret = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];
    }
    int flag = ret & (-ret);
    int ans1 = 0, ans2 = 0;
    for (i = 0; i < numsSize; i++)
    {
        if ((nums[i] & flag) == 0)
        {
            ans1 ^= nums[i];
        }
        else
        {
            ans2 ^= nums[i];
        }
    }
    int* arr = (int*)malloc(2 * sizeof(int));
    arr[0] = ans1;
    arr[1] = ans2;
    *returnSize = 2;
    return arr;
}