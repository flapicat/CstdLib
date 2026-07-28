#include <stdio.h>

#include "stringTests.h"
#include "memoryTests.h"

#define RUN_STRING_TEST
#define RUN_MEMORY_TEST

int main()
{
#ifdef RUN_STRING_TEST
	int StringSuccess = stringTestsMain();
#endif 

#ifdef RUN_MEMORY_TEST
	int memorySuccess = memoryTestsMain();
#endif 

	char* status[2] = { "Success","Failed" };
	printf("===== LIBRARY TESTING =====\n");
	printf("- String testing status: %s\n", status[StringSuccess]);
	printf("- Memory testing status: %s\n", status[memorySuccess]);

	return EXIT_SUCCESS;
}