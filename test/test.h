#ifndef TEST_H
#define TEST_H

// Regular text
#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"

// Reset
#define RESET "\033[0m"

// Test Macro
#define RUN_TEST(test)                      \
    do {                                    \
       printf("[" YEL "RUN" RESET "   ] %s\n", #test);   \
        test();                             \
       printf("[    " GRN "OK" RESET "] %s\n", #test);   \
    } while(0);                             \

#endif // !TEST_H
