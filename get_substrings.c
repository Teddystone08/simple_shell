#include "main.h"


/** stores the charater position of the string */
static int count = 1;
static int check = 1;


/**
 * _strpbrk - returns the position of first occurrence
 * @s: string to parce
 * @accept: delim to compare
 * Return: position of delim
 */
int _strpbrk(const char *s, const char *accept)
{
	int i = 0;

	while (*s != '\0')
	{
		const char *a = accept;

		while (*a != '\0')
		{
			if (*a++ == *s)
			{
				return (i);
			}
		}
		i++;
		++s;
	}
	return (0);
}


/**
 * token_len - returns count
 * Description: extension of get_substring
 * @j: integer
 * Return: count
 */
int token_len(int j)
{
	int tl = 0, k;

	for (k = 0; k < j; k++)
	{
		tl += 1;
	}
	return (tl);
}


/**
 * token_null - returns count
 * Description: extension of get_substring
 * @str: string
 * Return: character count
 */
int token_null(char *str)
{
	int tl = 0, k;

	for (k = 0; str[k] != '\0'; k++)
	{
		tl += 1;
	}
	return (tl);
}



/**
 * _strtok - gets tokens from string passed
 * Description: does not alter string passed
 * creates new memory for tokens
 *
 * @string: string to parce
 * @substring: delimiter string
 * Return: token
 */
char *_strtok(char *string, char *substring)
{
	int j = 0, k, c = 0, len = 0, tl = 0;
	char *str = string, *token = NULL;

	if (check == 1)
	{
		count = count - 1, check = 0;
	}
	c = count;
	if (count > 0)
	{
		str += c;
	}

	len = _strspn(str, substring);
	str += len;
	j = _strpbrk(str, substring);
	if (j > 0)
	{
		tl = token_len(j);
	}
	else
	{
		tl = token_null(str);
	}
	if (tl < 1)
	{
		goto Tz;
	}
	token = (char *)calloc(tl + 1, sizeof(char));

	for (k = 0; k < tl; k++)
	{
		token[k] = str[k];
	}
	token[k] = '\0';
Tz:
	count += tl, count += len;
	return (token);
}



/**
 * get_substrings - returns pointer to tokens
 * @string: string to parce
 * @delim: delimiter
 *
 * Return: pointer to tokens (success), NULL (fail)
 */
char **get_substrings(char *string, char *delim)
{
	int j, buff_check = 0, path_len;
	char *token = NULL, **paths = NULL, **temp;
	int i = _strlen(string);

	path_len = PATH_SIZE;
	paths = (char **)calloc(path_len, sizeof(char *));
	if (paths == NULL || i == 0 || string == NULL)
	{
		return (NULL);
	}
	for (j = 0; count < i; j++)
	{
		token = _strtok(string, delim);
		paths[j] = token;
		buff_check++;
		if (buff_check >= path_len)
		{
			path_len += PATH_SIZE;
			temp = paths;
			paths = (char **)realloc(paths, path_len * sizeof(char *));
			if (paths == NULL)
			{
				free_args(temp);
				return (NULL);
			}
		}
	}
	temp = paths;
	paths = (char **)realloc(paths, (j + 1) * sizeof(char *));
	if (paths == NULL)
	{
		free_args(temp);
		return (NULL);
	}
	paths[j] = NULL;
	count = 1;
	check = 1;
	return (paths);
}

