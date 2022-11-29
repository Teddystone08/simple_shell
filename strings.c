#include "main.h"


/**
 * _strdup - duplicate a string
 * @string: string to duplicate
 *
 * Return: string (success), NULL (fail)
 */
char *_strdup(char *string)
{
	int j, i = 0;
	char *str = NULL;

	i = _strlen(string) + 1;
	str = (char *)malloc(i * sizeof(char));
	if (str != NULL)
	{
		for (j = 0; j < i; j++)
		{
			str[j] = string[j];
		}
	}
	return (str);
}


/**
 * _strlen - returns the length of a string
 * @str: string to evaluate
 * Return: non-zero (success), zero (fail)
 */
int _strlen(char *str)
{
	int len = 0, i;

	if (str != NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			len++;
		}
	}

	return (len);
}


/**
 * _strcmp - evaluates two strings and returns greater, less, equal
 * @str1: first string
 * @str2: second string
 *
 * Return: 0 (equal), -1 (unequal)
 */
int _strcmp(char *str1, char *str2)
{
	int i, j, stat = -1;

	if (str1 == NULL && str2 == NULL)
	{
		return (stat);
	}
	j = _strlen(str1);
	if (_strlen(str1) != _strlen(str2))
	{
		return (stat);
	}
	for (i = 0; i < j; i++)
	{
		if (str1[i] != str2[i])
		{
			stat = -1;
			return (stat);
		}
		stat = 0;
	}
	return (stat);
}


/**
 * _strncmp - evaluates the first n chars of two strings
 * @str1: string one
 * @str2: string two
 * @n: first number of characters
 * Return: 0 (equal), -1 (unequal)
 */
int _strncmp(char *str1, char *str2, unsigned int n)
{
	unsigned int i, stat = -1;

	if (str1 == NULL && str2 == NULL)
	{
		return (stat);
	}

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			stat = -1;
			return (stat);
		}
		stat = 0;
	}
	return (stat);
}


/**
 * getenv_line - returns a matching string from env
 * @string: string to find
 * @env: environment
 *
 * Return: string (success), NULL (fail)
 */
char *getenv_line(char *string, char **env)
{
	char *env_line = NULL;
	int c, j, i = 0, count = 0, stat = 1;

	i = _strlen(string);
	for (j = 0; env[j] != NULL; j++)
	{
		for (c = 0; env[j][c] != '='; c++)
		{
			count++;
		}
		if (count != i)
		{
			count = 0;
			continue;
		}
		else if (count == i)
		{
			stat = _strncmp(env[j], string, count);
			if (stat == 0)
			{
				env_line = env[j];
				return (env_line);
			}
			count = 0;
		}
	}
	return (env_line);
}

