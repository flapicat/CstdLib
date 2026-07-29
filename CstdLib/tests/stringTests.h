#include <stdio.h>
#include <CstdLib.h>

inline void Test_str_length()
{
    printf("Testing str_length...\n");

    ASSERT(str_length("") == 0);
    ASSERT(str_length("Hello") == 5);
    ASSERT(str_length("Hello World") == 11);

    printf("str_length passed!\n\n");
}


inline void Test_str_copy()
{
    printf("Testing str_copy...\n");

    char buffer[32] = {};

    str_copy(buffer, "Hello");

    ASSERT(str_compare(buffer, "Hello") == 0);

    str_copy(buffer, "");

    ASSERT(str_compare(buffer, "") == 0);

    printf("str_copy passed!\n\n");
}


inline void Test_str_concat()
{
    printf("Testing str_concat...\n");

    char buffer[64] = "Hello";

    str_concat(buffer, " World");

    ASSERT(str_compare(buffer, "Hello World") == 0);


    char buffer2[64] = "";

    str_concat(buffer2, "Test");

    ASSERT(str_compare(buffer2, "Test") == 0);


    printf("str_concat passed!\n\n");
}


inline void Test_str_compare()
{
    printf("Testing str_compare...\n");

    ASSERT(str_compare("Hello", "Hello") == 0);

    ASSERT(str_compare("ABC", "ABD") < 0);

    ASSERT(str_compare("ABD", "ABC") > 0);

    ASSERT(str_compare("", "") == 0);

    printf("str_compare passed!\n\n");
}


inline void Test_str_find()
{
    printf("Testing str_find...\n");

    const char* text = "Hello World";

    char* result;


    result = str_find(text, "World");

    ASSERT(result != NULL);
    ASSERT(str_compare(result, "World") == 0);


    result = str_find(text, "Hello");

    ASSERT(result != NULL);
    ASSERT(str_compare(result, "Hello World") == 0);


    result = str_find(text, "XYZ");

    ASSERT(result == NULL);


    printf("str_find passed!\n\n");
}

inline void Test_str_chr()
{
    printf("Testing str_chr...\n");

    ASSERT(str_chr("Hello", 'H') != NULL);
    ASSERT(*str_chr("Hello", 'H') == 'H');

    ASSERT(str_chr("Hello", 'e') != NULL);
    ASSERT(*str_chr("Hello", 'e') == 'e');

    ASSERT(str_chr("Hello", 'o') != NULL);
    ASSERT(*str_chr("Hello", 'o') == 'o');

    ASSERT(str_chr("banana", 'a') == &"banana"[1]);
    ASSERT(str_chr("banana", 'n') == &"banana"[2]);

    ASSERT(str_chr("abcdef", 'd') == &"abcdef"[3]);

    ASSERT(str_chr("abcdef", 'x') == NULL);

    ASSERT(str_chr("", 'a') == NULL);

    ASSERT(str_chr("Hello", '\0') == &"Hello"[5]);
    ASSERT(str_chr("", '\0') == &""[0]);

    ASSERT(str_chr("A", 'A') == &"A"[0]);
    ASSERT(str_chr("A", 'B') == NULL);

    ASSERT(str_chr("aaaaaa", 'a') == &"aaaaaa"[0]);

    ASSERT(str_chr("Hello World", ' ') == &"Hello World"[5]);

    ASSERT(str_chr("1234512345", '5') == &"1234512345"[4]);

    ASSERT(str_chr(NULL, 'a') == NULL);

    printf("str_chr passed!\n\n");
}

inline void Test_str_str_rchr()
{
    printf("Testing str_rchr...\n");

    ASSERT(str_rchr("Hello", 'H') != NULL);
    ASSERT(*str_rchr("Hello", 'H') == 'H');

    ASSERT(str_rchr("Hello", 'o') != NULL);
    ASSERT(*str_rchr("Hello", 'o') == 'o');

    ASSERT(str_rchr("banana", 'a') == &"banana"[5]);
    ASSERT(str_rchr("banana", 'n') == &"banana"[4]);

    ASSERT(str_rchr("abcdef", 'd') == &"abcdef"[3]);

    ASSERT(str_rchr("abcdef", 'x') == NULL);

    ASSERT(str_rchr("", 'a') == NULL);

    ASSERT(str_rchr("Hello", '\0') == &"Hello"[5]);
    ASSERT(str_rchr("", '\0') == &""[0]);

    ASSERT(str_rchr("A", 'A') == &"A"[0]);
    ASSERT(str_rchr("A", 'B') == NULL);

    ASSERT(str_rchr("aaaaaa", 'a') == &"aaaaaa"[5]);

    ASSERT(str_rchr("Hello World", ' ') == &"Hello World"[5]);

    ASSERT(str_rchr("1234512345", '5') == &"1234512345"[9]);

    ASSERT(str_rchr(NULL, 'a') == NULL);

    printf("str_rchr passed!\n\n");
}

inline void Test_str_ncmp()
{
    printf("Testing str_ncmp...\n");

    ASSERT(str_ncmp("Hello", "Hello", 5) == 0);
    ASSERT(str_ncmp("Hello", "Hello", 0) == 0);

    ASSERT(str_ncmp("Hello", "Helix", 3) == 0);
    ASSERT(str_ncmp("abcdef", "abcxyz", 3) == 0);

    ASSERT(str_ncmp("abc", "abd", 3) < 0);
    ASSERT(str_ncmp("Hello", "World", 1) < 0);

    ASSERT(str_ncmp("abd", "abc", 3) > 0);
    ASSERT(str_ncmp("World", "Hello", 1) > 0);

    ASSERT(str_ncmp("abc", "abcd", 4) < 0);
    ASSERT(str_ncmp("abcd", "abc", 4) > 0);

    ASSERT(str_ncmp("abcdef", "abcxyz", 2) == 0);
    ASSERT(str_ncmp("abcdef", "abcxyz", 4) < 0);

    ASSERT(str_ncmp("", "", 1) == 0);
    ASSERT(str_ncmp("", "abc", 1) < 0);
    ASSERT(str_ncmp("abc", "", 1) > 0);

    ASSERT(str_ncmp("A", "A", 1) == 0);
    ASSERT(str_ncmp("A", "B", 1) < 0);
    ASSERT(str_ncmp("B", "A", 1) > 0);

    ASSERT(str_ncmp("abc", "abc", 100) == 0);
    ASSERT(str_ncmp("abc", "abd", 100) < 0);

    ASSERT(str_ncmp("abc", "xyz", 0) == 0);

    printf("str_ncmp passed!\n\n");
}

inline void Test_str_to_int()
{
    printf("Testing str_to_int...\n");

    ASSERT(str_to_int("0") == 0);
    ASSERT(str_to_int("1") == 1);
    ASSERT(str_to_int("123") == 123);
    ASSERT(str_to_int("9999") == 9999);

    ASSERT(str_to_int("-1") == -1);
    ASSERT(str_to_int("-123") == -123);
    ASSERT(str_to_int("-9999") == -9999);

    ASSERT(str_to_int("123456789") == 123456789);

    ASSERT(str_to_int("") == 0);

    ASSERT(str_to_int("123 ") == 123);
    ASSERT(str_to_int("123") == 123);

    ASSERT(str_to_int("abc") == 0);
    ASSERT(str_to_int("123abc") == 123);
    ASSERT(str_to_int("abc123") == 0);

    ASSERT(str_to_int("-") == 0);
    ASSERT(str_to_int("+") == 0);

    ASSERT(str_to_int(NULL) == 0);

    printf("str_to_int passed!\n\n");
}

inline int stringTestsMain()
{
    printf("===== STRING TESTS =====\n");
    Test_str_length();
    Test_str_copy();
    Test_str_concat();
    Test_str_compare();
    Test_str_find();
    Test_str_chr();
    Test_str_str_rchr();
    Test_str_ncmp();
    Test_str_to_int();
    printf("All tests passed successfully!\n");
    printf("========================\n\n");
	
	return EXIT_SUCCESS;
}
