#include "main.h"


/**
 * _strspn - returns the length of first occurence of accept
 * @s: string to parce
 * @accept: delim to compare
 * Return: length of occurrence of delim
 */
size_t _strspn(const char *s, const char *accept)
{
	const char *p;
	const char *a;
	size_t len = 0;

	for (p = s; *p != '\0'; ++p)
	{
		for (a = accept; *a != '\0'; ++a)
		{
			if (*p == *a)
			{
				break;
			}
		}
		if (*a == '\0')
		{
			return (len);
		}
		else
		{
			++len;
		}
	}
	return (len);
}

