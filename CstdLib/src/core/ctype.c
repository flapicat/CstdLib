#include "ctype.h"

int is_digit(int ch)
{
	return ch >= '0' && ch <= '9';
}

int is_alpha(int ch)
{
	return (ch >= 'A' && ch <= 'Z') ||
		   (ch >= 'a' && ch <= 'z');
}

int is_alnum(int ch)
{
	return is_alpha(ch) || is_digit(ch);
}

int is_space(int ch)
{
	return ch == ' ' ||
		ch == '\t' ||
		ch == '\n' ||
		ch == '\v' ||
		ch == '\f' ||
		ch == '\r';
}

int is_upper(int ch)
{
	return (ch >= 'A' && ch <= 'Z');
}

int is_lower(int ch)
{
	return (ch >= 'a' && ch <= 'z');
}

int to_upper(int ch)
{
	if (is_lower(ch))
		return ch - ('a' - 'A');

	return ch;
}

int to_lower(int ch)
{
	if (is_upper(ch))
		return ch + ('a' - 'A');

	return ch;
}
