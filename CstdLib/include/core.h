#pragma once

#define EXIT_SUCCESS 0
#define EXIT_FAILED 1

#define NULL (void*)0

#define false 0 
#define true 1

#define ASSERT(x)                       \
    do {                                \
        if (!(x))                       \
            while (1)                   \
                {                       \
                }                       \
    } while(0)