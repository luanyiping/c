int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
    // 判断 K 是几位数
    int KSize = 0;
    int KNum = K;
    while (KNum)
    {
        KSize++;
        KNum /= 10;
    }
    // 两个数相加后最多位数是 两个数中较多位的 + 1
    int len = (ASize > KSize) ? ASize : KSize;
    int* arr = (int*)malloc(sizeof(int) * (len + 1));
    int Ai = ASize - 1, sum = 0, carry = 0, arri = 0;
    while (len--)
    {
        // 当 Ai < 0 时,说明位数少的数已经加完，因此用变量 a 来替代
        int a = 0;
        if (Ai >= 0)
        {
            a = A[Ai];
            Ai--;
        }
        sum = a + K % 10 + carry;
        if (sum >= 10)
        {
            sum -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        arr[arri] = sum;
        arri++;
        K /= 10;
    }
    // 最高位相加若大于 10 ,则在arr数组末尾增添元素 1，然后逆转数组
    if (carry == 1)
    {
        arr[arri] = 1;
        arri++;
    }
    // 逆置数组
    int start = 0, end = arri - 1;
    while (start < end)
    {
        int tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }
    *returnSize = arri;
    return arr;
}
