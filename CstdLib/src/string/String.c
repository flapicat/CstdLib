#include "string.h"
#include "core.h"
#include "types.h"

#include <stdio.h>

unsigned int str_length(const char* string)
{
	if (string == NULL)	{
		return 0;
	}
	unsigned int len = 0;
	while (string[len] != '\0')	{
		len++;
	}
	return len;
}

char* str_copy(char* dest, const char* src)
{
	if (dest == NULL || src == NULL) {
		return NULL;
	}

	int i = 0;
	while (src[i] != '\0')	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	
	return dest;
}

char* str_concat(char* dest, const char* src)
{
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	int destStrLen = 0;
	int i = 0;
	while (dest[i] != '\0'){
		i++;
	}
	destStrLen = i;

	i = 0;
	while (src[i] != '\0') {
		dest[destStrLen + i] = src[i];
		i++;
	}
	dest[destStrLen + i] = '\0';

	return dest;
}

int str_compare(const char* str1, const char* str2)
{
	if (str1 == NULL || str2 == NULL) {
		return -1;
	}

	int i = 0;

	while (str1[i] != '\0' || str2[i] != '\0')	{
		if (str1[i] != str2[i])	{
			return (unsigned char)str1[i] - (unsigned char)str2[i];
		}

		i++;
	}

	return 0;
}

char* str_find(const char* str1, const char* str2)
{
	if (str1 == NULL || str2 == NULL) {
		return NULL;
	}

	if (*str2 == '\0')
		return str1;

	for (int i = 0; str1[i] != '\0'; i++){
		int j = 0;
		while (str1[i + j] == str2[j] && str2[j] != '\0'){
			j++;
		}

		if (str2[j] == '\0')
			return &str1[i];
	}

	return NULL;
}

char* str_chr(const char* str, int ch)
{
	if (str == NULL) {
		return NULL;
	}

	for (size_t i = 0; ; i++)
	{
		if (str[i] == (char)ch)
			return (char*)&str[i];

		if (str[i] == '\0')
			break;
	}

	return NULL;
}

char* str_rchr(const char* str, int ch)
{
	if (str == NULL) {
		return NULL;
	}

	char* ptr = NULL;
	for (size_t i = 0; ; i++)
	{
		if (str[i] == (char)ch)
			ptr = (char*)&str[i];

		if (str[i] == '\0')
			break;
	}

	return ptr;
}

int str_ncmp(const char* str1, const char* str2, size_t count)
{
	if (str1 == NULL || str2 == NULL) {
		return -1;
	}

	for (size_t i = 0; i < count; i++)	{
		if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0') {
			return (unsigned char)str1[i] - (unsigned char)str2[i];
		}
	}

	return 0;
}

int str_to_int(const char* str)
{
	if (str == NULL)
		return 0;

	int sign = 1;
	int result = 0;

	if (*str == '-'){
		sign = -1;
		str++;
	}

	while (*str >= '0' && *str <= '9'){
		result = result * 10 + (*str - '0');
		str++;
	}

	return result * sign;
}

