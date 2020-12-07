#include "../include/string.h"

uint16 strSize(string ch)
{
	uint16 len = 0;

	while (ch[len])
		len++;

	return len + 1;
}

uint8 strEqual(string str1, string str2)
{
	uint16 str1_size = strSize(str1);

	if (str1_size != strSize(str2))
		return 0;

	for (uint16 i = 0; i < str1_size; i++)
		if (str1[i] != str2[i])
			return 0;
	return 1;
}