char firstUniqChar(char* s)
{
	int len = strlen(s);
	if (s == NULL || len == 0)
	{
		return ' ';
	}
	int arr[26] = { 0 };
	int i = 0;
	for (i = 0; i < len; i++)
	{
		arr[s[i] - 'a']++;
	}
	for (i = 0; i < len; i++)
	{
		if (arr[s[i] - 'a'] == 1)
		{
			return s[i];
		}
	}
	return ' ';
}