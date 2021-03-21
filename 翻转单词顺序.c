char* reverseWords(char* s)
{
	int len = strlen(s);
	char* ret = (char*)malloc(sizeof(char) * (len + 1));
	int start = 0, end1 = len - 1, end2 = len - 1;
	int num = 0;
	while (s[start] == ' ')
	{
		start++;
	}
	if (start == len)
	{
		return "";
	}
	while (end1 != start - 1)
	{
		while (s[end1] == ' ')
		{
			end1--;
		}
		end2 = end1;
		while (s[end2] != ' ' && end2 >= start)
		{
			end2--;
		}
		int i = end2 + 1;
		for (i = end2 + 1; i <= end1; i++)
		{
			ret[num++] = s[i];
		}
		ret[num++] = ' ';
		end1 = end2;
	}
	ret[num - 1] = '\0';
	return ret;
}
