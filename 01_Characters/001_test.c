#include <cmocka.h>
#include <string.h>
#include "001.c"

static void test_substring(void **state)
{
    char result[105];

    // Test case: Valid inputs
    substring("character", 4, 3, result);
    assert_string_equal(result, "act");
    memset(result, 0, sizeof(result)); // Clear the buffer

    // Test case: Start index beyond string length (Handled earlier)
    substring("hello_world", 100, 100, result);
    assert_string_equal(result, "");
    memset(result, 0, sizeof(result)); // Clear the buffer

    // Test case: Negative start index (Undefined behavior)
    substring("test", -1, 2, result);
    assert_string_equal(result, "");   // Should return an empty string
    memset(result, 0, sizeof(result)); // Clear the buffer

    // Test case: Negative count (Undefined behavior)
    substring("test", 0, -1, result);
    assert_string_equal(result, "");   // Should return an empty string
    memset(result, 0, sizeof(result)); // Clear the buffer

    // Test case: Start index at the null terminator
    substring("test", 4, 2, result);
    assert_string_equal(result, "");   // Should return an empty string
    memset(result, 0, sizeof(result)); // Clear the buffer

    // Test case: Empty input string
    substring("", 0, 10, result);
    assert_string_equal(result, "");   // Empty input, should return an empty string
    memset(result, 0, sizeof(result)); // Clear the buffer

    // Test case: Very large count value
    substring("small", 2, 1000, result);
    assert_string_equal(result, "all"); // Should return "all" because count is too large
    memset(result, 0, sizeof(result));  // Clear the buffer
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_substring),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
