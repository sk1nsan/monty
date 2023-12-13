#include "monty.h"

/**
 * _strdup - allocates space in memory, which contains a copy of the str
 *
 * @str: string to be copied
 *
 * Return: pointer to the copied string
 * or NULL if it fails
 */

char *_strdup(char *str)
{
	int i;
	char *str2;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		;
	str2 = malloc(sizeof(char) * i + 1);
	if (str2 == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		str2[i] = str[i];
	str2[i] = '\0';
	return (str2);

}

/**
 * _isdigit - check if the character is a digit (0-9)
 *
 *@c: the int to be checked
 *
 * Return: 1 if it is a digit
 *	0 otherwise
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);

}




/**
 * _atoi - convert string to int
 *
 *@s: string to be converted
 *
 * Return: int
 */

int _atoi(char *s)
{
	unsigned int result = 0, sign = 0, i = 0;

	while (s[i] != '\0')
	{
		if (_isdigit(s[i]))
		{
			result *= 10;
			result += s[i] - '0';
			i++;
			continue;
		}
		if (result != 0)
			break;

		if (s[i] == '-')
		{
			sign++;
			i++;
			continue;
		}
		i++;
	}
	if (sign % 2 != 0)
		result = -result;

	return (result);

}
/**
 * _isnumber - checks if s is a number
 *
 * @s: string
 *
 * Return: 1 if number
 * 0 otherwise
*/
int _isnumber(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (!_isdigit(s[i]))
			return (0);
	}
	return (1);
}
