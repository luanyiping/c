//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

/*
	假设数组元素为 2，2，1，3，4，4
	全员异或后得到的结果为 1^3

	001
	011
	010

	异或后倒数第二位为1，以倒数第二位是1还是0进行分组
	第一组: 2,2,3
	第二组: 4,4,1

*/

/*
    两个相反数进行按位与操作后，结果二进制中只有一个1，1的位置为正数原码中第一个1出现的位置(从右向左数)

*/

int* singleNumbers(int* nums, int numsSize，int* returnSize)
{
    int ret = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];
    }
    int count = 0;
    for (i = 0; i < 32; i++)
    {
        if (((ret >> i) & 1) == 1)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    int ans1 = 0;
    int ans2 = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (((nums[i] >> (count + 1)) & 1) == 1)
        {
            ans1 ^= nums[i];
        }
        else
        {
            ans2 ^= nums[i];
        }
    }
    *returnSize = 2;
    int* a = (int*)malloc(sizeof(int) * 2);
    a[0] = ans1;
    a[1] = ans2;
    return a;
}

int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
    int ret = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];
    }
    int flag = ret & (-ret);
    int ans1 = 0;
    for (i = 0; i < numsSize; i++)
    {
        if ((flag & nums[i]) == 0)
        {
            ans1 ^= nums[i];
        }
    }
    *returnSize = 2;
    int* a = (int*)malloc(sizeof(int) * 2);
    a[0] = ans1;
    a[1] = ret ^ ans1;
    return a;

}
