#ifndef TEST_H
#define TEST_H

// Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

// Reset
#define RESET "\e[0m"

// Test Macro
#define RUN_TEST(test)                      \
    do {                                    \
       printf("[" YEL "RUN" RESET "   ] %s\n", #test);   \
        test();                             \
       printf("[    " GRN "OK" RESET "] %s\n", #test);   \
    } while(0);                             \

#endif // !TEST_H
