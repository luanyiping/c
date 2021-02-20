// 一.暴力双重循环
void rotate(int* nums, int numsSize, int k) 
{
    k %= numsSize;
    int i = 0;
    for (i = 0; i < k; i++)
    {
        int tmp = nums[numsSize - 1];
        int j = 0;
        for (j = numsSize - 2; j > 0; j--)
        {
            nums[j + 1] = nums[j];
        }
        nums[0] = tmp;
    }
}

// 二.翻转法
void rotate(int* nums, int numsSize, int k) 
{
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}
void reverse(int* nums, int start, int end)
{
    while (start < end)
    {
        int tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
        start++;
        end--;
    }
}

// 循环交换
void swap(int* nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
void rotate(int* nums, int numsSize, int k)
{
    int n = numsSize;
    k %= numsSize;
    int start = 0;
    for (start = 0; start < numsSize && k != 0; n -= k, start += k, k % n)
    {
        int i = 0;
        for (i = 0; i < k; i++)
        {
            swap(nums, start + i, numsSize - k + i);
        }
    }
}

