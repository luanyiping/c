int singleNumber(int* nums, int numsSize)
{
    int bit[32] = { 0 };
    int count = 31;
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        int j = 0, tmp = 0;
        for (j = 0; j < numsSize; j++)
        {
            tmp += (nums[j] >> i) & 1;
        }
        bit[count--] = tmp % 3;
    }
    int weight = 0, ret = 0;
    for (i = 31; i >= 0; i--)
    {
        ret += bit[i] * pow(2, weight);
        weight++;
    }
    return ret;
}