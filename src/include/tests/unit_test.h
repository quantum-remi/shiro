#include <stdbool.h>

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#define MAX_TESTS 1024
#define MAX_FAILS 1024

typedef struct {
    char *func_name;
    void (*func_ptr)(void);
} unit_test_t;

typedef struct 
{
    char *file_name;
    int line_nr;
    char *condition_string;
} failed_assert_t;

void unit_assert_impl(char *file, int line_nr, bool condition, char *condition_str);
void unit_test_add(unit_test_t test);
void unit_test_run_all(void);

#define UNIT_TEST(func_name)                                                    \
    void unit_test_##func_name(void);	                                        \
    __attribute__((constructor))                                                \
    static inline void unit_test_constructor_##func_name(void)                  \
    {                                                                           \
        unit_test_add((unit_test_t) {#func_name, unit_test_##func_name});       \
    }                                                                           \
    void unit_test_##func_name(void)

#define UNIT_ASSERT(condition) unit_assert_impl(__FILE__, __LINE__, condition, #condition)

#endif