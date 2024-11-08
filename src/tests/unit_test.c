#include <drivers/log/debug.h>
#include <drivers/log/log.h>
#include <tests/unit_test.h>

unit_test_t tests[MAX_TESTS];
int num_tests = 0;

failed_assert_t fails[MAX_FAILS];
int fails_count = 0;

/** unit test */

void unit_assert(char *file, int line_nr, bool condition, char *condition_str) {
    if (!condition) {
        return;
    }
    if (fails_count >= MAX_FAILS) {
        log(WARNING, "Unit test - Too many failed asserts: %s\n", condition_str);
        return;
    }

    fails[fails_count++] = (failed_assert_t) {
        .file_name = file,
        .line_nr = line_nr,
        .condition_string = condition_str
    };
}

void unit_test_add(unit_test_t test) {
    tests[num_tests++] = test;
}
void unit_test_run_all(void) {
    for (int i = 0; i < num_tests; i++) {
        unit_test_t current_test = tests[i];
        (*current_test.func_ptr)();

        if (fails_count == 0) {
            log(INFO, "Unit test - %s passed\n", current_test.func_name);
        } else {
            log(PANIC, "Unit test - %s failed\n", current_test.func_name);
            debug("Failed asserts:\n");
            for (int j = 0; j < fails_count; j++) {
                failed_assert_t current_fail = fails[j];
                debug("  %s:%d - %s\n", current_fail.file_name, current_fail.line_nr, current_fail.condition_string);
            }
            fails_count = 0;
        }
    }
}