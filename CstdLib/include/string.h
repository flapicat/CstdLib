#pragma once

unsigned int str_length(const char* string);
char* str_copy(char* dest, const char* src);
char* str_concat(char* dest, const char* src);
int str_compare(const char* str1, const char* str2);
char* str_find(const char* str1, const char* str2);
char* str_chr(const char* str, int ch);
char* str_rchr(const char* str, int ch);
int str_ncmp(const char* str1, const char* str2, size_t count);
char* str_ncpy(char* dest, const char* src, size_t count);
int str_to_int(const char* str);