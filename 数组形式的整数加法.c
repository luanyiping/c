int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
    // �ж� K �Ǽ�λ��
    int KSize = 0;
    int KNum = K;
    while (KNum)
    {
        KSize++;
        KNum /= 10;
    }
    // ��������Ӻ����λ���� �������н϶�λ�� + 1
    int len = (ASize > KSize) ? ASize : KSize;
    int* arr = (int*)malloc(sizeof(int) * (len + 1));
    int Ai = ASize - 1, sum = 0, carry = 0, arri = 0;
    while (len--)
    {
        // �� Ai < 0 ʱ,˵��λ���ٵ����Ѿ����꣬����ñ��� a �����
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
    // ���λ��������� 10 ,����arr����ĩβ����Ԫ�� 1��Ȼ����ת����
    if (carry == 1)
    {
        arr[arri] = 1;
        arri++;
    }
    // ��������
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
