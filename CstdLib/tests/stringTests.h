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

inline int stringTestsMain()
{
    printf("===== STRING TESTS =====\n");
    Test_str_length();
    Test_str_copy();
    Test_str_concat();
    Test_str_compare();
    Test_str_find();
    printf("All tests passed successfully!\n");
    printf("========================\n\n");
	
	return EXIT_SUCCESS;
}
