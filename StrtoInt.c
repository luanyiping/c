int strToInt(char* str)
{
    int len = strlen(str);
    if (str == NULL || len == 0)
    {
        return 0;
    }
    int count = 0;
    while (*str == ' ')
    {
        str++;
        count++;
    }
    if (len == count)
    {
        return 0;
    }
    int flag = 1;
    if (*str == '-')
    {
        flag = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }
    if (!isdigit(*str))
    {
        return 0;
    }
    long long ret = 0;
    while (isdigit(*str))
    {
        ret = ret * 10 + (*str - '0') * flag;
        if (ret > INT_MAX || ret < INT_MIN)
        {
            return (ret > INT_MAX) ? (INT_MAX) : (INT_MIN);
        }
        str++;
    }
    return ret;
}
