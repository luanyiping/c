//һ���������� nums �����������֮�⣬�������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��

/*
	��������Ԫ��Ϊ 2��2��1��3��4��4
	ȫԱ����õ��Ľ��Ϊ 1^3

	001
	011
	010

	�������ڶ�λΪ1���Ե����ڶ�λ��1����0���з���
	��һ��: 2,2,3
	�ڶ���: 4,4,1

*/

/*
    �����෴�����а�λ������󣬽����������ֻ��һ��1��1��λ��Ϊ����ԭ���е�һ��1���ֵ�λ��(����������)

*/
int* singleNumbers(int* nums, int numsSize��int* returnSize)
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
