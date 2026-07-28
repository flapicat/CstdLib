#include <stdio.h>
#include <CstdLib.h>

inline void Test_mem_copy()
{
    printf("Testing mem_copy...\n");

    char src[] = "Hello";
    char dest[32] = {};

    mem_copy(dest, src, sizeof(src));

    ASSERT(str_compare(dest, "Hello") == 0);


    char buffer[8] = {};

    mem_copy(buffer, "Test", 5);

    ASSERT(str_compare(buffer, "Test") == 0);


    printf("mem_copy passed!\n\n");
}


inline void Test_mem_move()
{
    printf("Testing mem_move...\n");

    char buffer[] = "abcdef";

    mem_move(buffer + 2, buffer, 4);

    ASSERT(str_compare(buffer, "ababcd") == 0);


    char buffer2[] = "abcdef";

    mem_move(buffer2, buffer2 + 2, 4);

    ASSERT(str_compare(buffer2, "cdefef") == 0);


    printf("mem_move passed!\n\n");
}


inline void Test_mem_set()
{
    printf("Testing mem_set...\n");

    char buffer[16] = {};

    mem_set(buffer, 'A', 5);

    buffer[5] = '\0';

    ASSERT(str_compare(buffer, "AAAAA") == 0);


    unsigned char bytes[4] = {};

    mem_set(bytes, 0xFF, sizeof(bytes));

    ASSERT(bytes[0] == 0xFF);
    ASSERT(bytes[1] == 0xFF);
    ASSERT(bytes[2] == 0xFF);
    ASSERT(bytes[3] == 0xFF);


    printf("mem_set passed!\n\n");
}


inline void Test_mem_compare()
{
    printf("Testing mem_compare...\n");

    char a[] = "Hello";
    char b[] = "Hello";
    char c[] = "World";


    ASSERT(mem_compare(a, b, sizeof(a)) == 0);

    ASSERT(mem_compare(a, c, sizeof(a)) < 0);

    ASSERT(mem_compare(c, a, sizeof(a)) > 0);


    unsigned char x[] = { 1, 2, 3 };
    unsigned char y[] = { 1, 2, 4 };

    ASSERT(mem_compare(x, y, sizeof(x)) < 0);


    printf("mem_compare passed!\n\n");
}


inline void Test_mem_find()
{
    printf("Testing mem_find...\n");

    unsigned char data[] = { 10, 20, 30, 40, 50 };


    const unsigned char* result;


    result = mem_find(data, 30, sizeof(data));

    ASSERT(result != NULL);
    ASSERT(*result == 30);


    result = mem_find(data, 10, sizeof(data));

    ASSERT(result == &data[0]);


    result = mem_find(data, 50, sizeof(data));

    ASSERT(result == &data[4]);


    result = mem_find(data, 99, sizeof(data));

    ASSERT(result == NULL);


    printf("mem_find passed!\n\n");
}


inline int memoryTestsMain()
{
    printf("===== MEMORY TESTS =====\n");

    Test_mem_copy();
    Test_mem_move();
    Test_mem_set();
    Test_mem_compare();
    Test_mem_find();

    printf("All tests passed successfully!\n");
    printf("========================\n\n");

    return EXIT_SUCCESS;
}